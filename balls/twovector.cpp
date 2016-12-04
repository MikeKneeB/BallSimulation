#include "twovector.h"
#include <cmath>
#include <iostream>
#include <string>

//Nothing
TwoVector::TwoVector()
{

}

//Initialises values
TwoVector::TwoVector(double x, double y)
{
    fX = x;
    fY = y;
}

//Nothing
TwoVector::~TwoVector()
{

}

double TwoVector::Modulus()
{
    //Modulus given by pythagorus.
    return std::sqrt(fX * fX + fY * fY);
}

double TwoVector::Argument()
{
    //Argument computed using standard arctangent.
    return std::atan(fY/fX);
}

double TwoVector::Dot(TwoVector second)
{
    //Dot product.
    return this->fX * second.fX + this->fY * second.fY;
}

TwoVector TwoVector::Rotate(double radians)
{
    //Rotation done using matrix rotation.
    TwoVector temporary;
    temporary.fX = std::cos(radians)*this->fX + std::sin(radians)*this->fY;
    temporary.fY = -std::sin(radians)*this->fX + std::cos(radians)*this->fY;
    return temporary;
}

TwoVector TwoVector::operator+(const TwoVector& second)
{
    TwoVector temporary;
    temporary.fX = this->fX + second.fX;
    temporary.fY = this->fY + second.fY;
    return temporary;
}

TwoVector TwoVector::operator-()
{
    return TwoVector(-this->fX, -this->fY);
}

TwoVector TwoVector::operator-(const TwoVector& second)
{
    TwoVector temporary;
    temporary.fX = this->fX - second.fX;
    temporary.fY = this->fY - second.fY;
    return temporary;
}

TwoVector TwoVector::operator*(const double multiplier)
{
    TwoVector temporary;
    temporary.fX = this->fX * multiplier;
    temporary.fY = this->fY * multiplier;
    return temporary;
}

TwoVector TwoVector::operator/(const double multiplier)
{
    TwoVector temporary;
    temporary.fX = this->fX / multiplier;
    temporary.fY = this->fY / multiplier;
    return temporary;
}

void TwoVector::Print()
{
    std::cout << "(" << fX << ", " << fY << ")";
}
