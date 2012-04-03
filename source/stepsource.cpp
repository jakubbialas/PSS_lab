#include "stepsource.h"

StepSource::StepSource(){
}

void StepSource::setParameter(std::string name, double value){
    if(name.compare("amplitude") == 0){
        amplitude = value;
    }
}

double StepSource::getSample(){
    if(getTime()>0){
        return amplitude;
    }else{
        return 0;
    }
}
