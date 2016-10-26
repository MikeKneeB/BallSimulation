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
        //Floor
        fPos.SetX(fRadius);
        fVel.SetY(std::abs(fVel.GetY()));
    }
    else if (fPos.GetY() < fRadius)
    {
        //Left wall.
        fPos.SetY(fRadius);
        fVel.SetX(std::abs(fVel.GetX()));
    }
    else if (fPos.GetX() > fField->GetX() - fRadius)
    {
        //Ceiling.
        fPos.SetX(fField->GetX() - fRadius);
        fVel.SetY(-std::abs(fVel.GetY()));
    }
    else if (fPos.GetY() > fField->GetY() - fRadius)
    {
        //Right Wall.
        fPos.SetY(fField->GetY() - fRadius);
        fVel.SetX(-std::abs(fVel.GetX()));
    }
}

void RegularBall::Tick(double time)
{
    fPos.SetX(fVel.GetX()*time + 0.5*fField->GetGrav().GetX()*time*time);
    fPos.SetY(fVel.GetY()*time + 0.5*fField->GetGrav().GetY()*time*time);
}

//void RegularBall::Print()
//{
//    std::cout << "Mass: " << fMass << std::endl;
//    std::cout << "Radius: " << fRadius << std::endl;
//    std::cout << "Position: " << fPos.GetX() << ", " << fPos.GetY() << std::endl;
//    std::cout << "Velocity: " << fVel.GetX() << ", " << fVel.GetY() << std::endl;
//}
