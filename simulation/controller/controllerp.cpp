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
        throw PSSDiscreteObjectUnknownParameterException();
    }
}

double ControllerP::simulate(double y){
    if(source != NULL){
        double e = source->getNextSample() - y;
        return e*P;
    }else{
        throw PSSDiscreteObjectSorceNotDefinedException();
    }
}
