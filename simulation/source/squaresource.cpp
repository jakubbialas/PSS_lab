#include "squaresource.h"

SquareSource::SquareSource(){
}

void SquareSource::setParameter(std::string name, double value){
    if(name.compare("amplitude") == 0){
        amplitude = value;
    }
    if(name.compare("frequency") == 0){
        frequency = value;
    }
    if(name.compare("dutycycle") == 0){
        dutycycle = value;
    }
}

double SquareSource::getSample(){
    double t = (int)(getTime())%(int)(1000/frequency);
    t = t/(1000/frequency);
    if(t < dutycycle/100){
        return amplitude;
    }else{
        return 0;
    }
}
