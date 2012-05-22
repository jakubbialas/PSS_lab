#include "controller.h"

Controller::Controller(){
    source = NULL;
}

Controller::~Controller(){
}

void Controller::setSource(Source* n_source){
    source = n_source;
}

double Controller::getSP(){
    return source->getSample();
}

void Controller::reset(){
    if(source){
        source->reset();
    }
    DiscreteObject::reset();
}

Source* Controller::getSource(){
    return source;
}
