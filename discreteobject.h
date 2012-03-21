#ifndef DISCRETEOBJECT_H
#define DISCRETEOBJECT_H

#include "objectsiso.h"

class DiscreteObject : public ObjectSISO
{
public:
    DiscreteObject();

    double Symuluj(double);
};

#endif // DISCRETEOBJECT_H
