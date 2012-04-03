#include "controller.h"

Controller::Controller()
{
    source = Source();
}

Controller::~Controller(){

}

void Controller::setSourceType(Source::SourceType st){
    source.setSourceType(st);
}

void Controller::setSourceValue(double v){
    source.setSourceValue(v);
}

double Controller::getSetPoint(){
    return source.getSample();
}

double Controller::getError(){
    return source.getSample() - getLastValue();
}
