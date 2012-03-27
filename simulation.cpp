#include "simulation.h"

Simulation::Simulation(QObject *parent) :
    QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextStep()));

    samplingTime = 100;
    coerce = new Coerce();
}


void Simulation::loadConfig(const char * filename)
{
    ymp.parseFile(filename);

    //std::string name("inercja");
    //std::string name("calka");
    //std::string name("inercja z calka");
    std::string name("niestacjonarny1");

    if(ymp.hasKey(name)){
        object = new DiscreteObject(*ymp.getObject(name));
        cout << "dodano obiekt" << endl;
    }else{
        cout << "nie dodano obiektu" << endl;
    }
}

void Simulation::setCoercionType(Coerce::CoercionType type){
    coerce->setCoercionType(type);
}

void Simulation::setCoercionValue(double value){
    coerce->setCoercionValue(value);
}

void Simulation::startSimulation(){
    timer->start(samplingTime);
}

void Simulation::setSamplingTime(int n_samplingTime){
    samplingTime = n_samplingTime;
    timer->setInterval(samplingTime);
}

void Simulation::stopSimulation(){
    timer->stop();
}

void Simulation::resetSimulation(){

}

void Simulation::stepSimulation(int i){
    for(int k=0; k<i; k++){
        nextStep();
    }
}


void Simulation::nextStep(){
    double x = coerce->nextSample();
    emit drawInput(x);
    emit drawOutput(object->Symuluj(x));
    //emit drawError();
    //emit drawControl();
}
