#include "controllerpid.h"

ControllerPID::ControllerPID(){
}

ControllerPID::ControllerPID(double n_P, double n_I, double n_D){
    P = n_P;
    I = n_I;
    D = n_D;
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
}

double ControllerPID::simulate(double e){
    return 0;
}
