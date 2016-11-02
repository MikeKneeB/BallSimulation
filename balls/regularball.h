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
    RegularBall(const RegularBall & other);
    ~RegularBall();

    bool CheckCollision();

    void ResolveCollision();

    void Tick();

    RegularBall * Copy();

    inline const Field* GetField() const {return fField;}

    inline void SetField(Field* field) {fField = field;}

    //void Print();

protected:
    const Field * fField;

    void InternalResolve(const Ball & other);
};

#endif // REGULARBALL_H
