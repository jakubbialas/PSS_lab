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
    feedback = true;

    filePath = "";
    toFile = false;

    controller = NULL;
    object = NULL;
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
    if(toFile){
        openFile();
    }
    timer->start(samplingTime);
}

void Simulation::stopSimulation(){
    if(toFile){
        closeFile();
    }
    timer->stop();
}

void Simulation::resetSimulation(){
    object->reset();
    controller->reset();
}

void Simulation::stepSimulation(int i){
    if(toFile){
        openFile();
    }
    for(int k=0; k<i; k++){
        nextStep();
    }
    if(toFile){
        closeFile();
    }
}

void Simulation::nextStep(){
    if(controller && object){
        double w = ((Controller*) controller)->getSP();
        double y_last = 0;
        if(feedback){
            y_last = object->getLastValue();
        }

        double u = controller->simulate(y_last);
        double y = object->simulate(u);

        emit drawInput(w);
        emit drawControl(u);
        emit drawOutput(y);
        if(toFile){
            printFile(w, u, y);
        }
    }else{
        emit simulationStopped(std::string("First set object, controller and source!"));
        timer->stop();
    }
}

void Simulation::setObject(ObjectSISO* n_object){
    object = n_object;
}

void Simulation::setController(ObjectSISO* n_controller){
    controller = n_controller;
}

/*void Simulation::setSource(Source* n_source){
    source = n_source;
}*/

/*ObjectSISO* Simulation::getObject(){
    return object;
}

ObjectSISO* Simulation::getController(){
    return controller;
}

Source* Simulation::getSource(){
    return source;
}*/

void Simulation::saveSignalsToFile(bool n_toFile, std::string n_filePath){
    toFile = n_toFile;
    filePath = n_filePath;
}

void Simulation::openFile(){
    file.open(filePath.c_str(), std::ios::out|std::ios::app);
}

void Simulation::printFile(double w, double u, double y){
    file << w << ";" << u << ";" << y << "\n";
}

void Simulation::closeFile(){
    file.close();
}
