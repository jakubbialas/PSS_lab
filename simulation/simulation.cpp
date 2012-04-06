#include "simulation.h"

Simulation::Simulation(QObject *parent) :
    QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextStep()));

    samplingTime = 100;
    controller = new ControllerP(1);
    source = new MultiSource();
    object = new NonStationaryDiscreteObject();
    feedback = false;
}

Simulation::~Simulation(){
    delete controller;
    delete source;
    delete object;
}

/*void Simulation::openConfig(std::string filename){
    ymp.openConfig(filename);
    setObjectsList(ymp.getKeys());
}*/

/*void Simulation::saveConfig(std::string filename){
    ymp.saveConfig(filename);
}*/

void Simulation::addSource(std::string type){
    source->addSource(type);
}

void Simulation::setLastSourceParameter(std::string name, double value){
    source->setLastSourceParameter(name, value);
}

void Simulation::removeLastSource(){
    source->removeLastSource();
}


void Simulation::setObject(ObjectData od){
    object->setData(od);
}

void Simulation::setControllerType(std::string type){
    if(type.compare("P") == 0){
        delete controller;
        controller = new ControllerP();
    }
}

void Simulation::setControllerParameter(std::string name, double value){
    this->controller->setParameter(name, value);
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
