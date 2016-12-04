#ifndef REGULARBALL_H
#define REGULARBALL_H

#include "ball.h"
#include "field.h"

/**
 * @brief The RegularBall class
 *
 * @author Mike Knee
 * @date 04/11/2016
 *
 * Regular ball is the first implemented, inheriting from the Ball abstract
 * class. It implements all the necessary methods from the Ball abstract, and
 * behaves like a regular ball which does not feel the affects of air
 * resistance.
 *
 * This Ball type has a pointer to the field it is placed in. It uses this for
 * Collision resolution with the field wall, and for ticking it's position.
 * Logically this makes sense, as this type of ball is only supposed to exist
 * inside a box (the field).
 */
class RegularBall : public Ball
{
public:
    /**
     * @brief RegularBall Constructor
     *
     * Empty constructor.
     */
    RegularBall();
    /**
     * @brief RegularBall Constructor
     *
     * Parameter constructor, initialises RegularBall values.
     *
     * @param position: TwoVector initial position.
     * @param velocity: TwoVector initial velocity.
     * @param radius: double radius.
     * @param mass: double mass.
     * @param field: pointer back to field ball is in.
     */
    RegularBall(TwoVector position,
         TwoVector velocity,
         double radius,
         double mass,
         Field* field);
    /**
     * @brief RegularBall Constructor
     *
     * Copy constructor. Creates a copy of the RegularBall.
     *
     * @param other: RegularBall to copy.
     */
    RegularBall(const RegularBall & other);
    /**
     * @brief RegularBall destructor
     *
     * Does nothing, despite fField being a pointer. This is because many balls
     * will have a reference to the same field, so it is inappropriate to
     * delete it from the heap.
     */
    ~RegularBall();

    /**
     * @brief CheckCollision
     *
     * Check's for a collision with the walls of the field.
     *
     * @return true if the ball is colliding with the field, false otherwise.
     */
    bool CheckCollision();

    /**
     * @brief ResolveCollision
     *
     * Resolves a ball's collision with the field walls. Ball must be colliding
     * with the wall.
     *
     * @pre Ball is colliding with the walls of the field it is in.
     * @post Ball's velocity and position are updated correctly after the
     * collision.
     */
    void ResolveCollision();

    /**
     * @brief Tick
     *
     * Updates the balls position for a time period specified by the fTime
     * parameter in the field class.
     */
    void Tick();

    /**
     * @brief Copy
     *
     * Copy method to create a copy of this RegularBall.
     *
     * @return pointer to a copy of this RegularBall.
     */
    RegularBall * Copy();

    //Getter and setter for the field, others inherited.
    inline const Field* GetField() const {return fField;}

    inline void SetField(Field* field) {fField = field;}

protected:
    //Only need the field parameter, other inherited from Ball.
    const Field * fField;

    /**
     * @brief InternalResolve
     *
     * Implemented from pure virtual version in Ball abstract. Updates this
     * balls position and velocity for a collision, leaves the other ball
     * unchanged.
     *
     * @pre This RegularBall and other Ball are colliding.
     * @post This ball's position and velocity are updated.
     *
     * @param other: Ball this is colliding with.
     */
    void InternalResolve(const Ball & other);
};

#endif // REGULARBALL_H
