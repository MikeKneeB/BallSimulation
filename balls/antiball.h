#ifndef ANTIBALL_H
#define ANTIBALL_H

#include "regularball.h"

/**
 * @brief The AntiBall class
 *
 * @author Mike Knee
 * @date 04/11/2016
 *
 * AntiBall class (similar to the DragBall class) inherits from RegularBall.
 * This type represents a ball which is affected inversely by gravity.
 *
 * This ball only needs to implement the Tick() and Copy() method, as
 * everything else is inherited from RegularBall.
 */
class AntiBall : public RegularBall
{
public:
    /**
     * @brief AntiBall Constructor
     *
     * Does nothing, no initialisation.
     */
    AntiBall();
    /**
     * @brief AntiBall Constructor
     *
     * Parameter constructor.
     *
     * @param position: TwoVector initial position.
     * @param velocity: TwoVector initial velocity.
     * @param radius: double radius of the ball.
     * @param mass: double mass of the ball.
     * @param field: pointer back to the field the ball is contained in.
     */
    AntiBall(TwoVector position,
         TwoVector velocity,
         double radius,
         double mass,
         Field* field);
    /**
     * @brief AntiBall Constructor
     *
     * Copy constructor.
     *
     * @param other: AntiBall to make a copy of.
     */
    AntiBall(const RegularBall & other);
    /**
     * @brief AntiBall Destructor
     *
     * Destructor does nothing, no heap memory used.
     */
    ~AntiBall();

    /**
     * @brief Tick
     *
     * Updates the ball's position and velocity, similarly to RegularBall. Here
     * the affects of the gravity of the field are reversed.
     */
    void Tick();

    /**
     * @brief Copy
     *
     * Copy method to create a copy of this ball on the heap.
     *
     * @return pointer to a copy of this AntiBall.
     */
    AntiBall * Copy();
};

#endif // ANTIBALL_H
