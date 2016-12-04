#include "dragball.h"

#include <cmath>
#include <iostream>

#define PI 3.14159265359

//Does nothing.
DragBall::DragBall()
{

}

//Copy constructor just calls superclass copy constructor - no extra parameters
//to initialise.
DragBall::DragBall(const DragBall &other)
    : RegularBall::RegularBall(other)
{

}

//Parameter constructor, like the copy constructor, does not need to initialise
//any extra parameters.
DragBall::DragBall(TwoVector position, TwoVector velocity, double radius, double mass, Field *field)
    : RegularBall::RegularBall(position, velocity, radius, mass, field)
{

}

//Destructor does nothing, as no heap memory used.
DragBall::~DragBall()
{

}

//Tick method very similar to the RegularBall Tick(), but now also considers
//acceleration due to air resistance.
void DragBall::Tick()
{
    double time = fField->GetTime();

    TwoVector airResistance;

    //Compute air resistance acceleration, see report for full details on this
    //caluculation.
    airResistance.SetX(-0.5 * fField->GetResistance() * PI * fRadius * fRadius * fVel.GetX() * std::abs(fVel.GetX()));
    airResistance.SetY(-0.5 * fField->GetResistance() * PI * fRadius * fRadius * fVel.GetY() * std::abs(fVel.GetY()));

    //Update using suvat.
    fPos.SetX(fPos.GetX() + fVel.GetX()*time + 0.5*(fField->GetGrav().GetX() + (airResistance.GetX()/fMass))*time*time);
    fVel.SetX(fVel.GetX() + (fField->GetGrav().GetX()+airResistance.GetX()/fMass)*time);
    fPos.SetY(fPos.GetY() + fVel.GetY()*time + 0.5*(fField->GetGrav().GetY() + (airResistance.GetY()/fMass))*time*time);
    fVel.SetY(fVel.GetY() + (fField->GetGrav().GetY()+airResistance.GetY()/fMass)*time);
}

DragBall * DragBall::Copy()
{
    return new DragBall(*this);
}
