#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <memory>

#include "ball.h"

/**
 * @brief The Field class
 *
 * @author Mike Knee
 * @date 04/11/2016
 *
 * The field class describes a box containing balls bouncing inside it. It
 * describes the geometry and other global properties of the field (air
 * resistance and gravity) and contains methods to update all ball's positions
 * and resolve all collisions (using the ball type's methods).
 */
class Field
{
public:
    /**
     * @brief Field constructor.
     *
     * Empty constructor does not initialise values.
     */
    Field();
    /**
     * @brief Field constructor.
     *
     * Initialises field properties with supplied parameters. Field has area
     * xy. time parameter specifies how much time passes for each tick of the
     * simulation.
     *
     * @param x: double x size of the field.
     * @param y: double y size of the field.
     * @param time: double time period of each "tick".
     * @param resistance: air resistance coefficient for the field.
     * @param grav: TwoVector gravity of the field.
     */
    Field(double x, double y, double time, double resistance, TwoVector grav);
    /**
     * @brief Field destructor.
     *
     * As std::unique_ptr is used for pointers to each ball no memory
     * management is required here.
     */
    ~Field();

    /**
     * @brief AddBall
     *
     * Adds a ball to the field. This uses unique_ptrs to greatly improve
     * memory management. When the unique_ptr goes out of scope it's object is
     * automatically destroyed and memory reclaimed. Particularly when dealing
     * with Ball objects, which will only be referenced by this field (and this
     * field alone) it greatly simplifies the memory management required.
     *
     * @param ball: unique_ptr to ball type to add to the field.
     */
    void AddBall(std::unique_ptr<Ball> ball);

    /**
     * @brief ClearBalls
     *
     * Removes all balls from the field.
     */
    void ClearBalls();

    /**
     * @brief Update
     *
     * Updates all ball's positions resolving any collisions between balls.
     * This calls CheckCollision(other) for each ball pair, as well as
     * CheckCollision() for each ball; to check for collisions between balls
     * and between balls and the field (respectively). Each ball is ticked
     * after it's collisions are checked and resolved.
     */
    void Update();

    //Getters and setters.
    //The only notable feature here is the lack of GetBalls. There is no way
    //to access the std::vector list of balls. This is because of memory
    //management concerns. Balls can be accessed by reference individually
    //using their index in the vector.
    inline double GetX() const { return fX; }
    inline double GetY() const { return fY; }
    inline double GetTime() const { return fTime; }
    inline double GetResistance() const { return fResistance; }
    inline double GetSize() const { return fSize; }
    inline Ball & GetBall(int index); //Gets ball at particular index.
    inline TwoVector GetGrav() const { return fGrav; }

    inline void SetX(double x);
    inline void SetY(double y);
    inline void SetTime(double time);
    inline void SetXY(double x, double y);
    inline void SetResistance(double resistance);
    inline void SetGrav(const TwoVector& grav);

    //Debug print method.
    void Print();

private:
    //Parameters describing the field.
    double fX;
    double fY;
    double fTime;
    double fResistance; //Air resistance coefficient.
    //fSize is the number of balls currently in the field.
    int fSize;
    //std::vector of balls in the field.
    std::vector<std::unique_ptr<Ball>> fBalls;
    TwoVector fGrav; //Gravity.
};

Ball & Field::GetBall(int index)
{
    return *fBalls[index];
}

//Setters check to make sure input values are valid.
//They do nothing if input values are not valid.
void Field::SetX(double x)
{
    if (x <= 0)
    {
        return;
    }
    else
    {
        fX = x;
    }
}

void Field::SetY(double y)
{
    if (y <= 0)
    {
        return;
    }
    else
    {
        fY = y;
    }
}

void Field::SetTime(double time)
{
    if (time <= 0)
    {
        return;
    }
    else
    {
        fTime = time;
    }
}

void Field::SetXY(double x, double y)
{
    if (x <= 0 || y <= 0)
    {
        return;
    }
    else
    {
        fX = x;
        fY = y;
    }
}

void Field::SetResistance(double resistance)
{
    if (resistance < 0)
    {
        return;
    }
    else
    {
        fResistance = resistance;
    }
}

void Field::SetGrav(const TwoVector& grav)
{
    fGrav = grav;
}

#endif // FIELD_H
