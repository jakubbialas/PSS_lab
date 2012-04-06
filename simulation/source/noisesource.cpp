#include "noisesource.h"

NoiseSource::NoiseSource(){
    std::srand ( ::time(NULL) );
}

void NoiseSource::setParameter(std::string name, double value){
    if(name.compare("amplitude") == 0){
        amplitude = value;
    }
}

double NoiseSource::getSample(){
    int r = std::rand();
    double e = r%32767; //0-32767
    e = (e/32767)*2 - 1; //(-1) - 1
    e = e*amplitude;
    return e;
}
