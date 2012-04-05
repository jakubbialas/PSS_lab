#include "multisource.h"

MultiSource::MultiSource(){
}

void MultiSource::addSource(std::string type){
    Source *source = NULL;
    if(type.compare("step") == 0){
        source = new StepSource();
    }
    if(type.compare("impuls") == 0){
        source = new ImpulsSource();
    }
    if(type.compare("sinus") == 0){
        source = new SinusSource();
    }
    if(type.compare("square") == 0){
        source = new SquareSource();
    }
    if(type.compare("triangle") == 0){
        source = new TriangleSource();
    }
    if(type.compare("noise") == 0){
        source = new NoiseSource();
    }
    if(source){
        sources.push_back(source);
    }
}

void MultiSource::removeLastSource(){
    if(sources.size()>0){
        sources.pop_back();
    }
}

void MultiSource::setLastSourceParameter(std::string name, double value){
    Source *a = sources.at(sources.size()-1);
    a->setParameter(name, value);
}

void MultiSource::setParameter(std::string name, double value){
}

double MultiSource::getSample(){
    double value = 0;
    std::vector<Source*>::iterator it;
    for(it = sources.begin(); it < sources.end(); it++){
        (*it)->setTime(getTime());
        value += (*it)->getSample();
    }
    return value;
}
