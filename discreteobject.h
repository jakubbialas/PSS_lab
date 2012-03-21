#ifndef DISCRETEOBJECT_H
#define DISCRETEOBJECT_H

#include "objectsiso.h"

#include <vector>
#include <deque>

using namespace std;

class DiscreteObject : public ObjectSISO
{
private:
    vector<double> A; //wielomian A
    vector<double> B; //wielomian B

    deque<double> stat; //kolejka stanu (poprzednie wartości)

public:
    DiscreteObject();
    DiscreteObject(vector<double>, vector<double>);

    void setAB(vector<double>, vector<double>);

    double Symuluj(double);
};

#endif // DISCRETEOBJECT_H
