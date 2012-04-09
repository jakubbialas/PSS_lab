#ifndef CONTROLLERPID_H
#define CONTROLLERPID_H

#include "controller.h"

class ControllerPID : public Controller
{
protected:
    double P;
    double I;
    double D;
public:
    ControllerPID();
    ~ControllerPID();
    ControllerPID(double, double, double);

    void setParameter(std::string, double);
    double simulate(double);
};

#endif // CONTROLLERPID_H
