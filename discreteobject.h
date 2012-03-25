#ifndef DISCRETEOBJECT_H
#define DISCRETEOBJECT_H

#include "objectsiso.h"

#include <vector>
#include <deque>
#include <iostream>

using namespace std;

class DiscreteObject : public ObjectSISO
{
private:
    vector<double> A; //wielomian A - ten na dole...
    vector<double> B; //wielomian B - ten na gorze
    deque<double> U;  //kolejka wymuszeń
    deque<double> Y;  //kolejka stanu (poprzednie wartości)
    int k;            //opoznienie wejscia

    //double counter; //aktualny numer próbki // niepotrzebny

public:
    DiscreteObject();
    DiscreteObject(vector<double>, vector<double>, int);

    void setBAk(vector<double>, vector<double>, int);
    //void setY(deque<double>); //niepotrzebne
    //void setU(deque<double>); //ustaw wektor wymuszeń

    vector<double> getB();
    vector<double> getA();
    int getk();

    double Symuluj(double);

};

#endif // DISCRETEOBJECT_H
