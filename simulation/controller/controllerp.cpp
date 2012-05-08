#include "controllerp.h"

ControllerP::ControllerP(){
}

ControllerP::ControllerP(double n_P){
    P = n_P;
}

ControllerP::~ControllerP(){
}

void ControllerP::setParameter(std::string name, double value){
    if(name.compare("P") == 0){
        P = value;
    }else{
        throw "Undefined parameter " + name + ".";
    }
}

double ControllerP::simulate(double y){
    double e = source->getNextSample() - y;
    return e*P;
}
