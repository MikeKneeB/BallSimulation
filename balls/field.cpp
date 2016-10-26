#include "field.h"
#include "ball.h"

#include <vector>
#include <iostream>
#include <memory>

Field::Field()
{

}

Field::Field(double x, double y, double time, TwoVector grav)
{
    fX = x;
    fY = y;
    fTime = time;
    fGrav = grav;
}

Field::~Field()
{

}

void Field::AddBall(std::unique_ptr<Ball> ball)
{
    fBalls.push_back(std::move(ball));
}

void Field::ClearBalls()
{
    fBalls.clear();
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
        (*iter)->Tick(fTime);
    }
}

void Field::Print()
{
    std::cout << "Size: " << fX << ", " << fY << std::endl;
    std::cout << "Time: " << fTime << std::endl;
    std::cout << "No. of balls: " << fBalls.size() << std::endl;
    std::cout << "Gravity: " << fGrav.GetX() << ", " << fGrav.GetY() << std::endl;
}
