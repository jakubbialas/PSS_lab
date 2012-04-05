#include "impulssource.h"

ImpulsSource::ImpulsSource(){
}

void ImpulsSource::setParameter(std::string name, double value){
    if(name.compare("amplitude") == 0){
        amplitude = value;
    }
}

double ImpulsSource::getSample(){
    if(getTime() == 0){
        return amplitude;
    }else{
        return 0;
    }
}
