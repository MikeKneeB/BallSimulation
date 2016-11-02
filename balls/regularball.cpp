#include "regularball.h"
#include "ball.h"

#include <cmath>
#include <iostream>

RegularBall::RegularBall()
{

}

RegularBall::RegularBall(TwoVector position,
               TwoVector velocity,
               double radius,
               double mass,
               Field * field)
    : Ball::Ball(position, velocity, radius, mass)
{
    fField = field;
}

RegularBall::RegularBall(const RegularBall & other)
    : Ball::Ball(other)
{
    this->fField = other.fField;
}

RegularBall::~RegularBall()
{

}

bool RegularBall::CheckCollision()
{
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
    if (fPos.GetX() < fRadius)
    {
        fPos.SetX(fRadius);
        fVel.SetX(-(fVel.GetX()));
    }
    else if (fPos.GetY() < fRadius)
    {
        fPos.SetY(fRadius);
        fVel.SetY(-(fVel.GetY()));
    }
    else if (fPos.GetX() > fField->GetX() - fRadius)
    {
        fPos.SetX(fField->GetX() - fRadius);
        fVel.SetX(-(fVel.GetX()));
    }
    else if (fPos.GetY() > fField->GetY() - fRadius)
    {
        fPos.SetY(fField->GetY() - fRadius);
        fVel.SetY(-(fVel.GetY()));
    }
}

void RegularBall::Tick()
{
    double time = fField->GetTime();

    fPos.SetX(fPos.GetX() + fVel.GetX()*time + 0.5*fField->GetGrav().GetX()*time*time);
    fVel.SetX(fVel.GetX() + fField->GetGrav().GetX()*time);
    fPos.SetY(fPos.GetY() + fVel.GetY()*time + 0.5*fField->GetGrav().GetY()*time*time);
    fVel.SetY(fVel.GetY() + fField->GetGrav().GetY()*time);
}

RegularBall * RegularBall::Copy()
{
    return new RegularBall(*this);
}

void RegularBall::InternalResolve(const Ball & other)
{
    TwoVector distance = this->GetPos() - other.GetPos();
    double angle = distance.Argument();

    double mass = this->GetMass();
    double otherMass = other.GetMass();

    TwoVector workingVelocity = this->GetVel().Rotate(angle);
    TwoVector otherWorkingVelocity = other.GetVel().Rotate(angle);

    double afterCollision = (workingVelocity.GetX()*(mass - otherMass) + 2*otherMass*otherWorkingVelocity.GetX())/(otherMass + mass);

    workingVelocity.SetX(afterCollision);

    this->fVel = workingVelocity.Rotate(-angle);

    double fullDistance = this->GetRadius() + other.GetRadius();
    double distanceDifference = fullDistance - distance.Modulus();

    TwoVector normDistance = distance*(1/distance.Modulus());

    TwoVector newPosition = this->GetPos() + normDistance*(distanceDifference/2);

    this->fPos = newPosition;

    return;
}

