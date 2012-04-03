#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "source.h"
#include "discreteobject.h"

class Controller : public DiscreteObject
{
public:
    Controller();
    ~Controller();

    Source source;
};

#endif // CONTROLLER_H
