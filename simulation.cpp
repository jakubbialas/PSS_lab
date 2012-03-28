#include "simulation.h"

Simulation::Simulation(QObject *parent) :
    QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextStep()));

    samplingTime = 100;
    source = Source();
    object = DiscreteObject();
}


void Simulation::loadConfig(const char * filename)
{
    ymp.parseFile(filename);

    setObjectsList(ymp.getKeys());
}

void Simulation::setSourceType(Source::SourceType type){
    source.setSourceType(type);
}

void Simulation::setSourceValue(double value){
    source.setSourceValue(value);
}


void Simulation::setObject(std::string name){
    if(ymp.hasKey(name)){
        object.setData(ymp.getObject(name));
    }else{
        //
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
    source.reset();
    object.reset();
}

void Simulation::stepSimulation(int i){
    for(int k=0; k<i; k++){
        nextStep();
    }
}

void Simulation::nextStep(){
    double x = source.nextSample();
    emit drawInput(x);
    emit drawOutput(object.Symuluj(x));
    //emit drawError();
    //emit drawControl();
}
