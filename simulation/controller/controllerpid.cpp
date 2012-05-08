#include "controllerpid.h"

ControllerPID::ControllerPID(){
    setNoiseRatio(0);
    lastI = 0;
    lastD = 0;
}

ControllerPID::ControllerPID(double n_P, double n_I, double n_D){
    P = n_P;
    I = n_I;
    D = n_D;
    setNoiseRatio(0);

    lastI = 0;
    lastD = 0;
}

ControllerPID::~ControllerPID(){
}

void ControllerPID::setParameter(std::string name, double value){
    if(name.compare("P") == 0){
        P = value;
    }else if(name.compare("I") == 0){
        I = value;
    }else if(name.compare("D") == 0){
        D = value;
    }else{
        throw "Undefined parameter " + name + ".";
    }
    //actualize();
}

double ControllerPID::simulateP(){
    return P * U[0];
}

double ControllerPID::simulateI(){
    if(U.size() > 1){
        lastI = lastI + P/I*U[1];
    }
    return lastI;
}

double ControllerPID::simulateD(){
    double N = 100;
    if(U.size() > 1){
        lastD = D/(D+N)*lastD + P*N*D/(D+N)*(U[0] - U[1]);
    }else{
        lastD = D/(D+N)*lastD;
    }
    return lastD;
}

double ControllerPID::simulate(double y){
    double e = source->getNextSample() - y;
    U.push_front(e);
    if(U.size() > 2){
        U.pop_back();
    }
    return simulateP() + simulateI() + simulateD();
}

void ControllerPID::reset(){
    lastI = 0;
    lastD = 0;
    DiscreteObject::reset();
}

