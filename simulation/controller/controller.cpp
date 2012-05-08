#include "controller.h"

Controller::Controller(){
    source = NULL;
}

void Controller::setSource(Source* n_source){
    delete source;
    source = n_source;
}

double Controller::getSP(){
    return source->getSample();
}

void Controller::reset(){
    DiscreteObject::reset();
    source->reset();
}
