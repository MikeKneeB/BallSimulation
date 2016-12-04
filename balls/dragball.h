#ifndef DRAGBALL_H
#define DRAGBALL_H

#include "regularball.h"

/**
 * @brief The DragBall class
 *
 * @author Mike Knee
 * @date 04/11/2016
 *
 * DragBall class inherits from RegularBall (and therefore has Ball abstract
 * as it's grandparent). This represents a ball type which feels the affects of
 * air resistance.
 *
 * In all other regards this ball is identical to the RegularBall class, and so
 * does not need to implement any new parameter and only overwrites the Tick()
 * method.
 */
class DragBall : public RegularBall
{
public:
    /**
     * @brief DragBall Constructor
     *
     * Does nothing, no initialisation.
     */
    DragBall();
    /**
     * @brief DragBall Constructor
     *
     * Copy constructor.
     *
     * @param other: DragBall to make a copy of.
     */
    DragBall(const DragBall & other);
    /**
     * @brief DragBall Constructor
     *
     * Parameter constructor.
     *
     * @param position: TwoVector initial position.
     * @param velocity: TwoVector initial velocity.
     * @param radius: double radius of the ball.
     * @param mass: double mass of the ball.
     * @param field: pointer to the field the ball is contained in.
     */
    DragBall(TwoVector position,
             TwoVector velocity,
             double radius,
             double mass,
             Field* field);
    /**
     * @brief DragBall destructor
     *
     * Does nothing, as no heap memory used.
     */
    ~DragBall();

    /**
     * @brief Tick
     *
     * Updates the ball's position and velocity, similarly to RegularBall, but
     * in this case takes the affects of air resistance into account.
     */
    void Tick();

    /**
     * @brief Copy
     *
     * Copy method to create a copy of this Ball on the heap.
     *
     * @return pointer to a copy of this DragBall.
     */
    DragBall * Copy();
};

#endif // DRAGBALL_H
