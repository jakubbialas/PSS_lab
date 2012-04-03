#include "controllerp.h"

ControllerP::ControllerP(){
}

ControllerP::ControllerP(double n_P){
    parameter["P"] = n_P;
}

ControllerP::~ControllerP(){
}

void ControllerP::setParameter(std::string name, double value){
    if(name.compare("P") == 0){
        parameter["P"] = value;
    }else{
        throw "Undefined parameter";
    }
}

double ControllerP::simulate(double input){
    if(parameter.find("P") == parameter.end()){
        throw "P is undefined";
    }else{
        double e = source.nextSample() - input;
        return e*parameter["P"];
    }
}
