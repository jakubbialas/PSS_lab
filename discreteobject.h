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
    vector<double> A; //wielomian A
    vector<double> Ap; //wielomian A pomocniczy, tworzony po to by obiekt przechowywał jego nie przekształconą wersję
    vector<double> B; //wielomian B
    vector<double> U; //wektor wymuszeń
    vector<double> C;

    deque<double> state; //kolejka stanu (poprzednie wartości)

    double counter; //aktualny numer próbki

public:
    DiscreteObject();
    DiscreteObject(vector<double>, vector<double>);

    void setAB(vector<double>, vector<double>);
    void setU(vector<double>); //ustaw wektor wymuszeń

    vector<double> getA();
    vector<double> getB();


    double Symuluj(double);
    double Symuluj();

};

#endif // DISCRETEOBJECT_H
