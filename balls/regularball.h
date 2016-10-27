#ifndef REGULARBALL_H
#define REGULARBALL_H

#include "ball.h"
#include "field.h"

class RegularBall : public Ball
{
public:
    RegularBall();
    RegularBall(TwoVector position,
         TwoVector velocity,
         double radius,
         double mass,
         Field* field);
    ~RegularBall();

    bool CheckCollision();

    void ResolveCollision();

    void Tick(double time);

    inline const Field* GetField() const {return fField;}

    inline void SetField(Field* field) {fField = field;}

    //void Print();

private:
    const Field * fField;
};

#endif // REGULARBALL_H
