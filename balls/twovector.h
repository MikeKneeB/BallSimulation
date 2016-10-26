#ifndef TWOVECTOR_H
#define TWOVECTOR_H

#include <string>


class TwoVector
{
public:
    TwoVector();
    TwoVector(double x, double y);
    ~TwoVector();

    double Modulus();
    double Argument();
    double Dot(TwoVector second);
    TwoVector Rotate(double radians);

    inline double GetX() const { return fX; }
    inline double GetY() const { return fY; }

    inline void SetX(double x) { fX = x; }
    inline void SetY(double y) { fY = y; }
    inline void SetBoth(double x, double y) { fX = x; fY = y; }

    TwoVector operator+(const TwoVector& second);
    TwoVector operator-();
    TwoVector operator-(const TwoVector& second);
    TwoVector operator*(const double multiplier);
    TwoVector operator/(const double multiplier);

    void Print();

private:
    double fX;
    double fY;
};

#endif // TWOVECTOR_H
