#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "discreteobject.h"
#include <string>
#include <map>

class Controller : public DiscreteObject
{
public:
    Controller();

public:
    virtual void setParameter(std::string, double)=0;
    virtual double simulate(double)=0;
};

#endif // CONTROLLER_H
