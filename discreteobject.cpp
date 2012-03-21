#include "discreteobject.h"

DiscreteObject::DiscreteObject(){
    //A = null;
    //B = null;
}

double DiscreteObject::Symuluj(double input){
    return input;
}

DiscreteObject::DiscreteObject(vector<double> n_A, vector<double> n_B){
    A = n_A;
    B = n_B;
}

void DiscreteObject::setAB(vector<double> n_A, vector<double> n_B){
    A = n_A;
    B = n_B;
}
