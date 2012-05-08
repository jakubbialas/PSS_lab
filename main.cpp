#include <QtGui/QApplication>
//#include <iostream>
//#include <stdlib.h>
//#include <QLabel>
//#include <QTimer>
#include "gui/mainwindow.h"
#include "simulation/simulation.h"

#include "simulation/configuration.h"
#include "simulation/identification/arxidentification.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;
    Simulation simulation;
    Configuration config;

    QObject::connect(&window, SIGNAL(newConfig()),
                     &config, SLOT(newConfig()));
    QObject::connect(&window, SIGNAL(openConfig(std::string)),
                     &config, SLOT(openConfig(std::string)));
    QObject::connect(&window, SIGNAL(saveConfig(std::string)),
                     &config, SLOT(saveConfig(std::string)));

    QObject::connect(&window, SIGNAL(startSimulation()),
                     &simulation, SLOT(startSimulation()));
    QObject::connect(&window, SIGNAL(stopSimulation()),
                     &simulation, SLOT(stopSimulation()));
    QObject::connect(&window, SIGNAL(resetSimulation()),
                     &simulation, SLOT(resetSimulation()));
    QObject::connect(&window, SIGNAL(stepSimulation(int)),
                     &simulation, SLOT(stepSimulation(int)));
    QObject::connect(&window, SIGNAL(setFeedback(bool)),
                     &simulation, SLOT(setFeedback(bool)));
    QObject::connect(&window, SIGNAL(setSamplingTime(int)),
                     &simulation, SLOT(setSamplingTime(int)));
    QObject::connect(&window, SIGNAL(saveSignalsToFile(bool, std::string)),
                     &simulation, SLOT(saveSignalsToFile(bool, std::string)));


    QObject::connect(&simulation, SIGNAL(simulationStopped(std::string)),
                     &window, SLOT(simulationStopped(std::string)));
    QObject::connect(&simulation, SIGNAL(drawInput(double)),
                     &window, SLOT(drawInput(double)));
    QObject::connect(&simulation, SIGNAL(drawOutput(double)),
                     &window, SLOT(drawOutput(double)));
    QObject::connect(&simulation, SIGNAL(drawError(double)),
                     &window, SLOT(drawError(double)));
    QObject::connect(&simulation, SIGNAL(drawControl(double)),
                     &window, SLOT(drawControl(double)));


    QObject::connect(&config, SIGNAL(setObject(ObjectSISO*)),
                     &simulation, SLOT(setObject(ObjectSISO*)));
    QObject::connect(&config, SIGNAL(setController(ObjectSISO*)),
                     &simulation, SLOT(setController(ObjectSISO*)));
//    QObject::connect(&config, SIGNAL(setSource(Source*)),
//                     &simulation, SLOT(setSource(Source*)));


    QObject::connect(&window, SIGNAL(getObjectsList()),
                     &config, SLOT(getObjectsList()));
    QObject::connect(&config, SIGNAL(retObjectsList(std::vector<std::string>)),
                     &window, SLOT(retObjectsList(std::vector<std::string>)));
    QObject::connect(&window, SIGNAL(getObjectData(std::string)),
                     &config, SLOT(getObjectData(std::string)));
    QObject::connect(&config, SIGNAL(retObjectData(ObjectData)),
                     &window, SLOT(retObjectData(ObjectData)));
    QObject::connect(&window, SIGNAL(editObject(std::string, ObjectData)),
                     &config, SLOT(editObject(std::string, ObjectData)));
    QObject::connect(&window, SIGNAL(removeObject(std::string)),
                     &config, SLOT(removeObject(std::string)));
    QObject::connect(&window, SIGNAL(setActiveObject(std::string)),
                     &config, SLOT(setActiveObject(std::string)));
    QObject::connect(&config, SIGNAL(retActiveObject(std::string)),
                     &window, SLOT(retActiveObject(std::string)));



    QObject::connect(&window, SIGNAL(getAdjustmentsList()),
                     &config, SLOT(getAdjustmentsList()));
    QObject::connect(&config, SIGNAL(retAdjustmentsList(std::vector<AdjustmentData>)),
                     &window, SLOT(retAdjustmentsList(std::vector<AdjustmentData>)));
    QObject::connect(&window, SIGNAL(removeAdjustment(std::string, std::string)),
                     &config, SLOT(removeAdjustment(std::string, std::string)));
    QObject::connect(&window, SIGNAL(saveAdjustment(AdjustmentData)),
                     &config, SLOT(saveAdjustment(AdjustmentData)));
    QObject::connect(&window, SIGNAL(setActiveAdjustment(AdjustmentData)),
                     &config, SLOT(setActiveAdjustment(AdjustmentData)));
    QObject::connect(&config, SIGNAL(retActiveAdjustment(std::string, std::string)),
                     &window, SLOT(retActiveAdjustment(std::string, std::string)));



    QObject::connect(&window, SIGNAL(setActiveSimpleSource(std::string, std::map<std::string, double>)),
                     &config, SLOT(setActiveSimpleSource(std::string, std::map<std::string, double>)));


    QObject::connect(&window, SIGNAL(getCustomSourcesList()),
                     &config, SLOT(getCustomSourcesList()));
    QObject::connect(&config, SIGNAL(retCustomSourcesList(std::vector<std::string>)),
                     &window, SLOT(retCustomSourcesList(std::vector<std::string>)));
    QObject::connect(&window, SIGNAL(getCustomSourceData(std::string)),
                     &config, SLOT(getCustomSourceData(std::string)));
    QObject::connect(&config, SIGNAL(retCustomSourceData(MultiSourceData)),
                     &window, SLOT(retCustomSourceData(MultiSourceData)));
    QObject::connect(&window, SIGNAL(editCustomSource(std::string, MultiSourceData)),
                     &config, SLOT(editCustomSource(std::string, MultiSourceData)));
    QObject::connect(&window, SIGNAL(removeCustomSource(std::string)),
                     &config, SLOT(removeCustomSource(std::string)));
    QObject::connect(&window, SIGNAL(setActiveCustomSource(std::string)),
                     &config, SLOT(setActiveCustomSource(std::string)));
    QObject::connect(&config, SIGNAL(retActiveSource(std::string)),
                     &window, SLOT(retActiveSource(std::string)));

   window.show();
  /*  std::vector<double> B;
    std::vector<double> A;

    B.push_back(0.05);
    A.push_back(1);
    A.push_back(-1.95);
    A.push_back(0.95);

    DiscreteObject o(B, A, 2);
    ModelData d;
    ARXIdentification ident(0, 2, 2, 1);
double y, w = 1;
    for(int i=0; i<100; i++){
        y = o.simulate(w);
        d = ident.identify(w, y);
    }
    cout << d;
*/
    return a.exec();
}
