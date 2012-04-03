#include "simulation.h"

Simulation::Simulation(QObject *parent) :
    QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextStep()));

    samplingTime = 100;
    controller = NULL;
    source = new Source();
    object = new NonStationaryDiscreteObject();
}

Simulation::~Simulation(){
    delete controller;
    delete source;
    delete object;
}

void Simulation::loadConfig(const char * filename)
{
    ymp.parseFile(filename);
    setObjectsList(ymp.getKeys());
}

void Simulation::setSourceType(Source::SourceType type){
    source->setSourceType(type);
}

void Simulation::setSourceValue(double value){
    source->setSourceValue(value);
}


void Simulation::setObject(std::string name){
    if(ymp.hasKey(name)){
        object->setData(ymp.getObject(name));
    }else{
        //
    }
}

void Simulation::setControllerType(std::string type){
    std::cout << "controller " << type;
    if(type.compare("P") == 0){
        delete controller;
        controller = new ControllerP(1);
    }
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
}

void Simulation::stepSimulation(int i){
    for(int k=0; k<i; k++){
        nextStep();
    }
}

void Simulation::nextStep(){
    double w = source->nextSample();
    double y_last = 0;
    double e = w - y_last;
    double u = controller->simulate(e);
    double y = object->simulate(u);

    emit drawInput(w);
    emit drawError(e);
    emit drawControl(u);
    emit drawOutput(y);
}
