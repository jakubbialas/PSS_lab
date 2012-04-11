#include "simulation.h"

#include "object/nonstationarydiscreteobject.h"
#include "source/multisource.h"
#include "controller/controllerp.h"


Simulation::Simulation(QObject *parent) :
    QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextStep()));

    samplingTime = 10;
    feedback = false;
}

Simulation::~Simulation(){
}

void Simulation::setFeedback(bool n_feedback){
    feedback = n_feedback;
}

void Simulation::setSamplingTime(int n_samplingTime){
    samplingTime = n_samplingTime;
    timer->setInterval(samplingTime);
}

void Simulation::startSimulation(){
    timer->start(samplingTime);
}

void Simulation::stopSimulation(){
    timer->stop();
}

void Simulation::resetSimulation(){
    source->reset();
    object->reset();
    controller->reset();
}

void Simulation::stepSimulation(int i){
    for(int k=0; k<i; k++){
        nextStep();
    }
}

void Simulation::nextStep(){
    double w = source->getNextSample();
    double y_last = 0;
    if(feedback){
        y_last = object->getLastValue();
    }
    double e = w - y_last;
    double u = controller->simulate(e);
    double y = object->simulate(u);

    emit drawInput(w);
    emit drawError(e);
    emit drawControl(u);
    emit drawOutput(y);
}

void Simulation::setObject(ObjectSISO* n_object){
    object = n_object;
}

void Simulation::setController(ObjectSISO* n_controller){
    controller = n_controller;
}

void Simulation::setSource(Source* n_source){
    source = n_source;
}

/*ObjectSISO* Simulation::getObject(){
    return object;
}

ObjectSISO* Simulation::getController(){
    return controller;
}

Source* Simulation::getSource(){
    return source;
}*/
