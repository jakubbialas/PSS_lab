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

    double Kp, Kd, Ki;
    Kp = P;
    Kd = P*D;
    Ki = P/I;

    B.push_back(Kp+Kd+Ki); B.push_back(-Kp-2*Kd); B.push_back(Kd); // (Kp*Kd*Ki) + (-Kp-2*Kd)*z^-1 + Kd*z^-2
    A.push_back(1); A.push_back(-1); // 1 - z^-1

    this->setBAk(B,A,0);
}
