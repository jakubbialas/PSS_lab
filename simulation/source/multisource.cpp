#include "multisource.h"

MultiSource::MultiSource(){
}

MultiSource::MultiSource(std::vector<SourceData> vsd){
    std::vector<SourceData>::iterator it;
    for(it = vsd.begin(); it != vsd.end(); it++){
        Source* source = createSource((*it).getType());
        if(source){
            std::map<std::string, double>::iterator it2;
            std::map<std::string, double> param = (*it).getParameters();
            for(it2 = param.begin(); it2 != param.end(); it2++){
                source->setParameter((*it2).first, (*it2).second);
            }
            sources.push_back(source);
        }
    }
}

MultiSource::~MultiSource(){

}

Source* MultiSource::createSource(std::string type){
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
    return source;
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
