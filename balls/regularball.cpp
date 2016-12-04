#include "regularball.h"
#include "ball.h"

#include <cmath>
#include <iostream>

//Nothing
RegularBall::RegularBall()
{

}

//Initialises RegularBall, calls Ball supertype constructor.
RegularBall::RegularBall(TwoVector position,
               TwoVector velocity,
               double radius,
               double mass,
               Field * field)
    : Ball::Ball(position, velocity, radius, mass)
{
    fField = field;
}

//Copy constructor calls Ball supertype copy constructor.
RegularBall::RegularBall(const RegularBall & other)
    : Ball::Ball(other)
{
    this->fField = other.fField;
}

//Destructor does nothing.
RegularBall::~RegularBall()
{

}

bool RegularBall::CheckCollision()
{
    //Check if the balls radius is overlapping the walls of the field.
    if (fPos.GetX() < fRadius ||
        fPos.GetY() < fRadius ||
        fPos.GetX() > fField->GetX() - fRadius ||
        fPos.GetY() > fField->GetY() - fRadius)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void RegularBall::ResolveCollision(/*Field & field*/)
{
    //Collision resolution pushes ball so it's radius is on the wall of the
    //field and then negates the velocity component perpendicular to the wall
    //of the field.
    if (fPos.GetX() < fRadius)
    {
        //Colliding with:
        //  ---
        // |<  |
        //  ---
        fPos.SetX(fRadius);
        fVel.SetX(-(fVel.GetX()));
    }
    else if (fPos.GetY() < fRadius)
    {
        //Colliding with:
        //  ---
        // | v |
        //  ---
        fPos.SetY(fRadius);
        fVel.SetY(-(fVel.GetY()));
    }
    else if (fPos.GetX() > fField->GetX() - fRadius)
    {
        //Colliding with:
        //  ---
        // |  >|
        //  ---
        fPos.SetX(fField->GetX() - fRadius);
        fVel.SetX(-(fVel.GetX()));
    }
    else if (fPos.GetY() > fField->GetY() - fRadius)
    {
        //Colliding with:
        //  ---
        // | ^ |
        //  ---
        fPos.SetY(fField->GetY() - fRadius);
        fVel.SetY(-(fVel.GetY()));
    }
}

void RegularBall::Tick()
{
    //Time interval for this tick.
    double time = fField->GetTime();

    //Update using usual suvat equations of motion, including acceleration due
    //to gravity.
    fPos.SetX(fPos.GetX() + fVel.GetX()*time + 0.5*fField->GetGrav().GetX()*time*time);
    fVel.SetX(fVel.GetX() + fField->GetGrav().GetX()*time);
    fPos.SetY(fPos.GetY() + fVel.GetY()*time + 0.5*fField->GetGrav().GetY()*time*time);
    fVel.SetY(fVel.GetY() + fField->GetGrav().GetY()*time);
}

RegularBall * RegularBall::Copy()
{
    //Copy method.
    return new RegularBall(*this);
}

void RegularBall::InternalResolve(const Ball & other)
{
    //Internal resolve method for a collision with another ball type.

    //Distance between this ball and the other.
    TwoVector distance = this->GetPos() - other.GetPos();
    //Angle of vector normal to the collision. (see report for details.)
    double angle = distance.Argument();

    //Done to prevent multiple repeated function calls.
    double mass = this->GetMass();
    double otherMass = other.GetMass();

    //Rotate velocities so collision only happens in the x plane.
    TwoVector workingVelocity = this->GetVel().Rotate(angle);
    TwoVector otherWorkingVelocity = other.GetVel().Rotate(angle);

    //Compute new velocity using conservation of momentum and energy.
    double afterCollision = (workingVelocity.GetX()*(mass - otherMass) + 2*otherMass*otherWorkingVelocity.GetX())/(otherMass + mass);

    workingVelocity.SetX(afterCollision);

    //Rotate working velocity back to the usual x-y coordinates.
    this->fVel = workingVelocity.Rotate(-angle);

    //Move ball outward, so once the other ball is moved their radius' will be
    //touching.
    double fullDistance = this->GetRadius() + other.GetRadius();
    double distanceDifference = fullDistance - distance.Modulus();

    TwoVector normDistance = distance*(1/distance.Modulus());

    TwoVector newPosition = this->GetPos() + normDistance*(distanceDifference/2);

    //Update position.
    this->fPos = newPosition;

    return;
}

