#include "trianglesource.h"

TriangleSource::TriangleSource(){
}

void TriangleSource::setParameter(std::string name, double value){
    if(name.compare("amplitude") == 0){
        amplitude = value;
    }
    if(name.compare("frequency") == 0){
        frequency = value;
    }
}

double TriangleSource::getSample(){
    double t = (int)(getTime())%(int)(1/frequency);
    t = t*frequency;
    if(t < 0.25){
        return 4*t*amplitude;
    }else if (t<0.75){
        return 4*(0.5-t)*amplitude;
    }else{
        return 4*(t-1)*amplitude;
    }
}
