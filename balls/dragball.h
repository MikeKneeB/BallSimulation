#ifndef DRAGBALL_H
#define DRAGBALL_H

#include "regularball.h"

class DragBall : public RegularBall
{
public:
    DragBall();
    DragBall(const DragBall & other);
    DragBall(TwoVector position,
             TwoVector velocity,
             double radius,
             double mass,
             Field* field);
    ~DragBall();

    void Tick(double time);

    DragBall * Copy();
};

#endif // DRAGBALL_H
