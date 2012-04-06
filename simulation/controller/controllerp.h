#ifndef CONTROLLERP_H
#define CONTROLLERP_H

#include "controller.h"

class ControllerP : public Controller
{
protected:
    double P;
public:
    ControllerP();
    ~ControllerP();
    ControllerP(double);

    void setParameter(std::string, double);
    double simulate(double);
};

#endif // CONTROLLERP_H