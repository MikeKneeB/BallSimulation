#include "antiball.h"

//Empty constructor.
AntiBall::AntiBall()
{

}

//Parameter constructor calls the superclass constructor, no new variables to
//initialise.
AntiBall::AntiBall(TwoVector position, TwoVector velocity, double radius, double mass, Field *field)
    : RegularBall::RegularBall(position, velocity, radius, mass, field)
{

}

//Copy constructor calls the superclass constructor, no new variables to
//initialise.
AntiBall::AntiBall(const RegularBall &other)
    : RegularBall::RegularBall(other)
{

}

//Destructor doesn't need to do anything.
AntiBall::~AntiBall()
{

}

//Tick method very similar to RegularBall's tick, but negates the field's
//gravity.
void AntiBall::Tick()
{
    double time = fField->GetTime();

    fPos.SetX(fPos.GetX() + fVel.GetX()*time - 0.5*fField->GetGrav().GetX()*time*time);
    fVel.SetX(fVel.GetX() - fField->GetGrav().GetX()*time);
    fPos.SetY(fPos.GetY() + fVel.GetY()*time - 0.5*fField->GetGrav().GetY()*time*time);
    fVel.SetY(fVel.GetY() - fField->GetGrav().GetY()*time);
}

AntiBall * AntiBall::Copy()
{
    return new AntiBall(*this);
}
