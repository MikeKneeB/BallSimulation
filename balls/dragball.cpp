#include "dragball.h"
#include <cmath>

#define PI 3.14159265359

DragBall::DragBall()
{

}

DragBall::DragBall(const DragBall &other)
    : RegularBall::RegularBall(other)
{

}

DragBall::DragBall(TwoVector position, TwoVector velocity, double radius, double mass, Field *field)
    : RegularBall::RegularBall(position, velocity, radius, mass, field)
{

}

DragBall::~DragBall()
{

}

void DragBall::Tick(double time)
{
    TwoVector airResistance;

    airResistance.SetX(-0.5 * fField->GetResistance() * PI * fRadius * fRadius * fVel.GetX() * std::abs(fVel.GetX()));
    airResistance.SetY(-0.5 * fField->GetResistance() * PI * fRadius * fRadius * fVel.GetY() * std::abs(fVel.GetY()));

    fPos.SetX(fPos.GetX() + fVel.GetX()*time + 0.5*(fField->GetGrav().GetX()+airResistance.GetX()/fMass)*time*time);
    fVel.SetX(fVel.GetX() + (fField->GetGrav().GetX()+airResistance.GetX()/fMass)*time);
    fPos.SetY(fPos.GetY() + fVel.GetY()*time + 0.5*(fField->GetGrav().GetY()+airResistance.GetY()/fMass)*time*time);
    fVel.SetY(fVel.GetY() + (fField->GetGrav().GetY()+airResistance.GetY()/fMass)*time);
}

DragBall * DragBall::Copy()
{
    return new DragBall(*this);
}
