#include <cmath>
#include <iostream>

#include "ball.h"
#define PI 3.14159265359

//Empty constructor, does nothing.
Ball::Ball()
{

}

//Regular value constructor.
Ball::Ball(TwoVector position,
               TwoVector velocity,
               double radius,
               double mass)
{
    fPos = position;
    fVel = velocity;
    fRadius = radius;
    fMass = mass;
    //fField = field;
}

//Copy constructor.
Ball::Ball(const Ball & other)
{
    this->fPos = other.fPos;
    this->fVel = other.fVel;
    this->fRadius = other.fRadius;
    this->fMass = other.fMass;
}

//Destructor has nothing to do.
Ball::~Ball()
{

}

//Final checkcollision method.
bool Ball::CheckCollision(const Ball & other)
{
    //Distance between the balls.
    TwoVector distance;
    distance = this->fPos - other.fPos;

    //If it is less than the sum of radii, balls are colliding.
    if (distance.Modulus() < this->fRadius + other.fRadius)
        return true;
    else
        return false;
}

void Ball::ResolveCollision(Ball & other)
{   
    //Make copy of this.
    Ball * temp = this->Copy();

    //Update this' position and velocity for collision.
    this->InternalResolve(other);
    //Update other's position and velocity based on copy temp (i.e. position
    //and velocity of this at collision time).
    other.InternalResolve(*temp);

    delete temp;

    //Despite needing to create heap objects and delete, this method runs in
    //reasonable time, without serious impact on performance. If ball objects
    //were made to complicated, however, this could have a serious adverse
    //affect on the quality of the simulation. Fortunately all these classes
    //are only being used internally and so this can be easily taken into
    //consideration when writing subclasses.
    return;
}

//Debug method to print ball properties to the standard output.
void Ball::Print()
{
    std::cout << "Mass: " << fMass << std::endl;
    std::cout << "Radius: " << fRadius << std::endl;
    std::cout << "Position: " << fPos.GetX() << ", " << fPos.GetY() << std::endl;
    std::cout << "Velocity: " << fVel.GetX() << ", " << fVel.GetY() << std::endl;
}
