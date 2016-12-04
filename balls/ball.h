#ifndef BALL_H
#define BALL_H

#include "twovector.h"

/**
 * @brief The Ball class
 *
 * @author Mike Knee
 * @date 04/11/2016
 *
 * Abstract ball class which all real ball methods inherit from. Conatins all
 * the necessary methods for simulating the ball's motion, and provides the
 * basic member variables defining a ball's properties.
 *
 * Inherited classes must implement the CheckCollision(), ResolveCollision()
 * and InternalResolve() methods, which are intended to be check and resolution
 * methods for collisions with the walls of the field. Inherited classes are
 * therefore intended to have a member variable pointing back to the field they
 * reside in though this is not mandated in any way.
 */
class Ball
{
public:
    /**
     * @brief Ball constructor.
     *
     * Empty constructor, does not initialise values.
     */
    Ball();
    /**
     * @brief Ball constructor.
     *
     * Takes in parameters describing a ball's basic properties.
     *
     * @param position: TwoVector position of the ball.
     * @param velocity: TwoVector velocity of the ball.
     * @param radius: double radius of the ball.
     * @param mass: double mass of the ball.
     */
    Ball(TwoVector position,
         TwoVector velocity,
         double radius,
         double mass);
    /**
     * @brief Ball copy constructor.
     *
     * Copies all the properties of one ball to another.
     *
     * @param other: Ball to copy.
     */
    Ball(const Ball & other);
    /**
     * @brief ~Ball destructor.
     *
     * Ball class creates to heap objects, so nothing to do here.
     */
    virtual ~Ball() = 0;

    /**
     * @brief CheckCollision with other ball.
     *
     * Checks for a collision with another ball. This is declared final as it
     * is always the same for all Ball types, and so should not be overwritten.
     * I.e. there is only one way for two balls to collide, so no need for this
     * function to be overwritten.
     *
     * @param other: Ball to check collision against.
     * @return false if the two balls are not colliding, true if they are.
     */
    virtual bool CheckCollision(const Ball & other) final;
    /**
     * @brief CheckCollision with field wall.
     *
     * Check's if the ball is colliding with the walls of a field. This must be
     * implemented in subclasses, as it is pure virtual here. In order to
     * implement this properly the subclasses should have a pointer back to the
     * field they reside in.
     *
     * @return true if the ball is colliding with the field, false otherwise.
     */
    virtual bool CheckCollision() = 0;

    /**
     * @brief ResolveCollision with other ball.
     *
     * Resolves a collision with another ball. The two balls must be colliding
     * when this method is called (it does not perform this check). Both this
     * ball's velocity and position as well as the other ball's velocity and
     * poisition will be updated when this method is called.
     *
     * @pre The two balls are colliding (i.e. CheckCollision(other) returns
     * true).
     * @post The two balls are no longer colliding, and have correct velocity
     * and position for after the collision.
     *
     * @param other: Ball to resolve collision with.
     */
    virtual void ResolveCollision(Ball & other) final;
    /**
     * @brief ResolveCollision with field walls.
     *
     * Resolves a collision of this ball with the field. This function does not
     * check whether the ball is actually colliding with the field. Ball's
     * position and velocity will be updated after this method is called.
     *
     * @pre This ball is colliding with the field (i.e. CheckCollision() returns
     * true).
     * @post The ball is no longer colliding with the field, and has the
     * correct velocity and position for after the collision.
     */
    virtual void ResolveCollision() = 0;

    /**
     * @brief Tick
     *
     * Updates the ball's position, based on it's own properties and the
     * properites of the field it is in. This method is pure virtual and must
     * be implemented by each subclass of Ball. The ball's position and
     * velocity along with the time interval passing each tick (specified by
     * the field class) are always used to update the position, but other
     * factors may be used by exotic ball types.
     */
    virtual void Tick() = 0;

    /**
     * @brief Copy method for making a copy of a ball.
     *
     * Pure virtual method for copying ball pointers, used by
     * ResolveCollision(other).
     *
     * @return Pointer to copy of this ball.
     */
    virtual Ball* Copy() = 0;

    //Getters and setters.
    inline TwoVector GetPos() const {return fPos;}
    inline TwoVector GetVel() const {return fVel;}
    inline double GetRadius() const {return fRadius;}
    inline double GetMass() const {return fMass;}
    //inline Field* GetField() const {return fField;} ball subclasses should have this.

    inline void SetPos(TwoVector position) {fPos = position;}
    inline void SetVel(TwoVector velocity) {fVel = velocity;}
    inline void SetRadius(double radius) {fRadius = radius;}
    inline void SetMass(double mass) {fMass = mass;}
    //inline void SetField(Field* field) {fField = field;}

    //Debug print method.
    void Print();

protected:
    //Member variables are protected, as subclasses need access to them.
    TwoVector fPos; //Position vector.
    TwoVector fVel; //Velocity vector.
    double fRadius; //Radius.
    double fMass; //Mass

    /**
     * @brief InternalResolve
     *
     * This function is called by the final ResolveCollision method in order to
     * update this ball's collision with another ball. This method must be
     * overwritten by subclasses, as they may want to resolve collisions in
     * specific ways. The other ball's position and velocity is not updated
     * by this method.
     *
     * @pre This ball and other are colliding.
     * @post This ball's position and velocity are updated correctly for the
     * collision
     *
     * @param other: Ball this is colliding with.
     */
    virtual void InternalResolve(const Ball & other) = 0;
};

#endif // BALL_H
