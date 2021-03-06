#include "field.h"
#include "ball.h"

#include <vector>
#include <iostream>
#include <memory>

Field::Field()
{
    fSize = 0;
}

Field::Field(double x, double y, double time, double resistance, TwoVector grav)
{
    if (x > 0)
        fX = x;
    if (y > 0)
        fY = y;
    if (time > 0)
        fTime = time;
    if (resistance >= 0)
        fResistance = resistance;
    fGrav = grav;
    fSize = 0;
}

Field::~Field()
{

}

void Field::AddBall(std::unique_ptr<Ball> ball)
{
    fBalls.push_back(std::move(ball));
    fSize++;
}

void Field::ClearBalls()
{
    fBalls.clear();
    fSize = 0;
}

void Field::Update()
{
    for (std::vector<std::unique_ptr<Ball>>::iterator iter = fBalls.begin();
         iter != fBalls.end(); iter++)
    {
        if ((*iter)->CheckCollision())
        {
            (*iter)->ResolveCollision();
        }
        for (std::vector<std::unique_ptr<Ball>>::iterator initer = iter+1;
             initer != fBalls.end(); initer++){
            if ((*iter)->CheckCollision(*(*initer)))
            {
                (*iter)->ResolveCollision(*(*initer));
            }
        }
        (*iter)->Tick();
    }
}

void Field::Print()
{
    std::cout << "Size: " << fX << ", " << fY << std::endl;
    std::cout << "Time: " << fTime << std::endl;
    std::cout << "No. of balls: " << fBalls.size() << std::endl;
    std::cout << "Gravity: " << fGrav.GetX() << ", " << fGrav.GetY() << std::endl;
}
