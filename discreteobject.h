#ifndef DISCRETEOBJECT_H
#define DISCRETEOBJECT_H

#include "objectsiso.h"

#include <vector>
#include <deque>
#include <iostream>
#include "objectdata.h"

using namespace std;

class DiscreteObject : public ObjectSISO
{
private:
    vector<double> A; //wielomian A - ten na dole...
    vector<double> B; //wielomian B - ten na gorze
    deque<double> U;  //kolejka wymuszeń
    deque<double> Y;  //kolejka stanu (poprzednie wartości)
    int k;            //opoznienie wejscia

    ObjectData data;
    int counter; //aktualny numer próbki

    void updateModel();

public:
    DiscreteObject();
    DiscreteObject(ObjectData);
    DiscreteObject(vector<double>, vector<double>, int);

    void setBAk(vector<double>, vector<double>, int);
    void setModel(ModelData);
    void setData(ObjectData);

    vector<double> getB();
    vector<double> getA();
    int getk();

    double Symuluj(double);

};

#endif // DISCRETEOBJECT_H
