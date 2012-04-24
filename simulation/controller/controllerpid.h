#ifndef CONTROLLERPID_H
#define CONTROLLERPID_H

#include "controller.h"

/**
 * @brief Klasa Regulatora typu PID dziedziczy po klasie Regulaora
 * Na razie jest to tylko wzów klasy, sam regulator nie został jeszcze zaimplementowany!
 * TODO: implementacja regulatora PID
 */
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

private:
    void actualize();
};

#endif // CONTROLLERPID_H
