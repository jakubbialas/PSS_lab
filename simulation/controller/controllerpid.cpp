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
    //actualize();

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

double ControllerPID::simulate(double input){
    U.push_front(input);
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


/*void ControllerPID::actualize(){
    std::vector<double> A;
    std::vector<double> B;

    double Kp, Kd, Ki;
    Kp = P;
    Kd = P*D;
    Ki = P/I;

    B.push_back(Kp+Kd+Ki); B.push_back(-Kp-2*Kd); B.push_back(Kd); // (Kp*Kd*Ki) + (-Kp-2*Kd)*z^-1 + Kd*z^-2
    A.push_back(1); A.push_back(-1); // 1 - z^-1

    this->setBAk(B,A,0);
}*/
