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

void RegularBall::Tick(double time)
{
    fPos.SetX(fPos.GetX() + fVel.GetX()*time + 0.5*fField->GetGrav().GetX()*time*time);
    fVel.SetX(fVel.GetX() + fField->GetGrav().GetX()*time);
    fPos.SetY(fPos.GetY() + fVel.GetY()*time + 0.5*fField->GetGrav().GetY()*time*time);
    fVel.SetY(fVel.GetY() + fField->GetGrav().GetY()*time);
}

