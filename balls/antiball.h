#ifndef ANTIBALL_H
#define ANTIBALL_H

#include "regularball.h"

class AntiBall : public RegularBall
{
public:
    AntiBall();
    AntiBall(TwoVector position,
         TwoVector velocity,
         double radius,
         double mass,
         Field* field);
    AntiBall(const RegularBall & other);
    ~AntiBall();

    void Tick();

    AntiBall * Copy();
};

#endif // ANTIBALL_H
