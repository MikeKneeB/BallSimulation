#include <cmath>
#include <iostream>

#include "ball.h"
#define PI 3.14159265359

Ball::Ball()
{

}

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

Ball::Ball(const Ball & other)
{
    this->fPos = other.fPos;
    this->fVel = other.fVel;
    this->fRadius = other.fRadius;
    this->fMass = other.fMass;
}

Ball::~Ball()
{

}

bool Ball::CheckCollision(const Ball & other)
{
    TwoVector distance;
    distance = this->fPos - other.fPos;

    if (distance.Modulus() < this->fRadius + other.fRadius)
        return true;
    else
        return false;
}

//bool Ball::CheckCollision()
//{
//    if (fPos.GetX() < fRadius ||
//        fPos.GetY() < fRadius ||
//        fPos.GetX() > fField->GetX() - fRadius ||
//        fPos.GetY() > fField->GetY() - fRadius)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}

void Ball::ResolveCollision(Ball & other)
{   
//    TwoVector distance = this->GetPos() - other.GetPos();
//    double angle = distance.Argument();

//    double mass = this->GetMass();
//    double otherMass = other.GetMass();

//    TwoVector workingVelocity = this->GetVel().Rotate(angle);
//    TwoVector otherWorkingVelocity = other.GetVel().Rotate(angle);

//    double afterCollision = (workingVelocity.GetX()*(mass - otherMass) + 2*otherMass*otherWorkingVelocity.GetX())/(otherMass + mass);
//    double otherAfterCollision = (otherWorkingVelocity.GetX()*(otherMass - mass) + 2*mass*workingVelocity.GetX())/(otherMass + mass);

//    workingVelocity.SetX(afterCollision);
//    otherWorkingVelocity.SetX(otherAfterCollision);

//    this->fVel = workingVelocity.Rotate(-angle);
//    other.fVel = otherWorkingVelocity.Rotate(-angle);

//    double fullDistance = this->GetRadius() + other.GetRadius();
//    double distanceDifference = fullDistance - distance.Modulus();

//    TwoVector normDistance = distance*(1/distance.Modulus());

//    TwoVector newPosition = this->GetPos() + normDistance*(distanceDifference/2);
//    TwoVector otherNewPosition = other.GetPos() - normDistance*(distanceDifference/2);

//    this->fPos = newPosition;
//    other.fPos = otherNewPosition;

    Ball * temp = this->Copy();

    this->InternalResolve(other);
    other.InternalResolve(*temp);

    delete temp;

    return;
}

//void Ball::ResolveCollision(/*Field & field*/)
//{
//    if (fPos.GetX() < fRadius)
//    {
//        //Floor
//        fPos.SetX(fRadius);
//        fVel.SetY(std::abs(fVel.GetY()));
//    }
//    else if (fPos.GetY() < fRadius)
//    {
//        //Left wall.
//        fPos.SetY(fRadius);
//        fVel.SetX(std::abs(fVel.GetX()));
//    }
//    else if (fPos.GetX() > fField->GetX() - fRadius)
//    {
//        //Ceiling.
//        fPos.SetX(fField->GetX() - fRadius);
//        fVel.SetY(-std::abs(fVel.GetY()));
//    }
//    else if (fPos.GetY() > fField->GetY() - fRadius)
//    {
//        //Right Wall.
//        fPos.SetY(fField->GetY() - fRadius);
//        fVel.SetX(-std::abs(fVel.GetX()));
//    }
//}

//void Ball::Tick(double time)
//{
//    fPos.SetX(fVel.GetX()*time + 0.5*fField->GetGrav().GetX()*time*time);
//    fPos.SetY(fVel.GetY()*time + 0.5*fField->GetGrav().GetY()*time*time);
//}

void Ball::Print()
{
    std::cout << "Mass: " << fMass << std::endl;
    std::cout << "Radius: " << fRadius << std::endl;
    std::cout << "Position: " << fPos.GetX() << ", " << fPos.GetY() << std::endl;
    std::cout << "Velocity: " << fVel.GetX() << ", " << fVel.GetY() << std::endl;
}
