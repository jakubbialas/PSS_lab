#include "controllerpid.h"

ControllerPID::ControllerPID(){
    setNoiseRatio(0);
}

ControllerPID::ControllerPID(double n_P, double n_I, double n_D){
    P = n_P;
    I = n_I;
    D = n_D;
    setNoiseRatio(0);
    actualize();
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
    actualize();
}


void ControllerPID::actualize(){
    std::vector<double> A;
    std::vector<double> B;
    //B.push_back(P+D); B.push_back(-P+I+2*D); B.push_back(D); // (P*D)*z^2 + (-P+I+2*D)*z + D
    B.push_back(P+D+I); B.push_back(-P-2*D); B.push_back(D); // (P*D)*z^2 + (-P+I+2*D)*z + D

    A.push_back(1); A.push_back(-1); // z^2 - z
    this->setBAk(B,A,1);
}
