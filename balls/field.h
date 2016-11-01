#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <memory>

#include "ball.h"

class Field
{
public:
    Field();
    Field(double x, double y, double time, double resistance, TwoVector grav);
    ~Field();

    void AddBall(std::unique_ptr<Ball> ball);

    //void DeleteBall(int index);
    void ClearBalls();

    void Update();

    inline double GetX() const { return fX; }
    inline double GetY() const { return fY; }
    inline double GetTime() const { return fTime; }
    inline double GetResistance() const { return fResistance; }
    inline double GetSize() const { return fSize; }
    inline Ball & GetBall(int index);
    inline TwoVector GetGrav() const { return fGrav; }

    inline void SetX(double x);
    inline void SetY(double y);
    inline void SetTime(double time);
    inline void SetXY(double x, double y);
    inline void SetResistance(double resistance);
    inline void SetGrav(const TwoVector& grav);

    void Print();

private:
    double fX;
    double fY;
    double fTime;
    double fResistance;
    int fSize;
    std::vector<std::unique_ptr<Ball>> fBalls;
    TwoVector fGrav;
};

Ball & Field::GetBall(int index)
{
    return *fBalls[index];
}

void Field::SetX(double x)
{
    if (x <= 0)
    {
        return;
    }
    else
    {
        fX = x;
    }
}

void Field::SetY(double y)
{
    if (y <= 0)
    {
        return;
    }
    else
    {
        fY = y;
    }
}

void Field::SetTime(double time)
{
    if (time <= 0)
    {
        return;
    }
    else
    {
        fTime = time;
    }
}

void Field::SetXY(double x, double y)
{
    if (x <= 0 || y <= 0)
    {
        return;
    }
    else
    {
        fX = x;
        fY = y;
    }
}

void Field::SetResistance(double resistance)
{
    if (resistance < 0)
    {
        return;
    }
    else
    {
        fResistance = resistance;
    }
}

void Field::SetGrav(const TwoVector& grav)
{
    fGrav = grav;
}

#endif // FIELD_H
