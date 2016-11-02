#include "antiball.h"

AntiBall::AntiBall()
{

}

AntiBall::AntiBall(TwoVector position, TwoVector velocity, double radius, double mass, Field *field)
    : RegularBall::RegularBall(position, velocity, radius, mass, field)
{

}

AntiBall::AntiBall(const RegularBall &other)
    : RegularBall::RegularBall(other)
{

}

AntiBall::~AntiBall()
{

}

void AntiBall::Tick(double time)
{
    fPos.SetX(fPos.GetX() + fVel.GetX()*time - 0.5*fField->GetGrav().GetX()*time*time);
    fVel.SetX(fVel.GetX() - fField->GetGrav().GetX()*time);
    fPos.SetY(fPos.GetY() + fVel.GetY()*time - 0.5*fField->GetGrav().GetY()*time*time);
    fVel.SetY(fVel.GetY() - fField->GetGrav().GetY()*time);
}

AntiBall * AntiBall::Copy()
{
    return new AntiBall(*this);
}
