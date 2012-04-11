#include "sinussource.h"

SinusSource::SinusSource(){
}

void SinusSource::setParameter(std::string name, double value){
    if(name.compare("amplitude") == 0){
        amplitude = value;
    }
    if(name.compare("frequency") == 0){
        frequency = value;
    }
}

double SinusSource::getSample(){
    return sin(frequency*this->getTime()*2*M_PI)*amplitude;
}
