#ifndef BALL_H
#define BALL_H

#include "twovector.h"

class Ball
{
public:
    Ball();
    Ball(TwoVector position,
         TwoVector velocity,
         double radius,
         double mass);
    Ball(const Ball & other);
    virtual ~Ball() = 0;

    virtual bool CheckCollision(const Ball & other) final;
    virtual bool CheckCollision() = 0;

    virtual void ResolveCollision(Ball & other) final;
    virtual void ResolveCollision() = 0;

    virtual void Tick(double time) = 0;

    virtual Ball* Copy() = 0;

    inline TwoVector GetPos() const {return fPos;}
    inline TwoVector GetVel() const {return fVel;}
    inline double GetRadius() const {return fRadius;}
    inline double GetMass() const {return fMass;}
    //inline Field* GetField() const {return fField;}

    inline void SetPos(TwoVector position) {fPos = position;}
    inline void SetVel(TwoVector velocity) {fVel = velocity;}
    inline void SetRadius(double radius) {fRadius = radius;}
    inline void SetMass(double mass) {fMass = mass;}
    //inline void SetField(Field* field) {fField = field;}

    void Print();

protected:
    TwoVector fPos;
    TwoVector fVel;
    double fRadius;
    double fMass;
    //Field * fField;

private:
    virtual void InternalResolve(const Ball & other) = 0;
};

#endif // BALL_H
