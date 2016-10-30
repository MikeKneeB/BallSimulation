#ifndef INELASTICBALL_H
#define INELASTICBALL_H

#include "twovector.h"
#include "field.h"

class InelasticBall : public Ball
{
public:
    InelasticBall();
    InelasticBall(const InelasticBall & other);
    InelasticBall(TwoVector position,
                  TwoVector velocity,
                  double radius,
                  double mass,
                  double elasticity,
                  Field * field);
    ~InelasticBall();

    bool CheckCollision();

    void ResolveCollision();

    void Tick(double time);

    InelasticBall * Copy();

    inline Field * GetField() const {return fField;}
    inline void SetField(Field * field) {fField = field;}

private:
    Field * fField;
    double fElastic;

    void InternalResolve(const Ball & other);

};

#endif // INELASTICBALL_H
