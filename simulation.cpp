#include "simulation.h"

Simulation::Simulation(QObject *parent) :
    QObject(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(nextStep()));

    samplingTime = 100;
    coerce = Coerce();
    object = DiscreteObject();
}


void Simulation::loadConfig(const char * filename)
{
    ymp.parseFile(filename);

    setObjectsList(ymp.getKeys());
}

void Simulation::setCoercionType(Coerce::CoercionType type){
    coerce.setCoercionType(type);
}

void Simulation::setCoercionValue(double value){
    coerce.setCoercionValue(value);
}


void Simulation::setObject(std::string name){
    if(ymp.hasKey(name)){
        object.setData(ymp.getObject(name));
        cout << "dodano obiekt" << endl;
    }else{
        cout << "nie dodano obiektu" << endl;
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
    coerce.reset();
    object.reset();
}

void Simulation::stepSimulation(int i){
    for(int k=0; k<i; k++){
        nextStep();
    }
}

void Simulation::nextStep(){
    double x = coerce.nextSample();
    emit drawInput(x);
    emit drawOutput(object.Symuluj(x));
    //emit drawError();
    //emit drawControl();
}
