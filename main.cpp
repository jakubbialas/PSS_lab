#include <QtGui/QApplication>
//#include <iostream>
//#include <stdlib.h>
//#include <QLabel>
//#include <QTimer>
#include "gui/mainwindow.h"
#include "simulation/simulation.h"

#include "simulation/configuration.h"


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
    QObject::connect(&config, SIGNAL(setSource(Source*)),
                     &simulation, SLOT(setSource(Source*)));


    QObject::connect(&window, SIGNAL(getObjectsList()),
                     &config, SLOT(getObjectsList()));
    QObject::connect(&config, SIGNAL(retObjectsList(std::vector<std::string>)),
                     &window, SLOT(retObjectsList(std::vector<std::string>)));
    QObject::connect(&window, SIGNAL(getObjectData(std::string)),
                     &config, SLOT(getObjectData(std::string)));
    QObject::connect(&config, SIGNAL(retObjectData(ObjectData)),
                     &window, SLOT(retObjectData(ObjectData)));
    QObject::connect(&window, SIGNAL(editObjectData(std::string, ObjectData)),
                     &config, SLOT(editObjectData(std::string, ObjectData)));
    QObject::connect(&window, SIGNAL(setActiveObject(std::string)),
                     &config, SLOT(setActiveObject(std::string)));
    QObject::connect(&config, SIGNAL(retActiveObject(std::string)),
                     &window, SLOT(retActiveObject(std::string)));



    QObject::connect(&window, SIGNAL(getAdjustmentsList()),
                     &config, SLOT(getAdjustmentsList()));
    QObject::connect(&config, SIGNAL(retAdjustmentsList(std::map<std::string, ControllerData>)),
                     &window, SLOT(retAdjustmentsList(std::map<std::string, ControllerData>)));
    QObject::connect(&window, SIGNAL(setActiveController(std::string, AdjustmentData)),
                     &config, SLOT(setActiveController(std::string, AdjustmentData)));
    QObject::connect(&window, SIGNAL(removeAdjustment(std::string, std::string)),
                     &config, SLOT(removeAdjustment(std::string, std::string)));
    QObject::connect(&window, SIGNAL(saveAdjustment(std::string, AdjustmentData)),
                     &config, SLOT(saveAdjustment(std::string, AdjustmentData)));


    //getAdjustment(std::string, std::string)
    //retAdjustment(std::string, AdjustmentData)
    ////getAdjustmentsList()
    //retAdjustmentsList(std::vector<std::string>) ??
    //editAdjustment(std::string, AdjustmentData)
    //setAtciveController(std::string)
    //retAtciveController(std::string)



    //getSource(std::string)
    //retSource(std::string, SourceData)
    ////getSourcesList()
    //retSourcesList(std::vector<std::string>)
    //editSource(std::string, SourceData)
    //setActiveSource(std::string)
    //retActiveSource(std::string)
    QObject::connect(&window, SIGNAL(addSource(std::string)),
                     &config, SLOT(addSource(std::string)));
    QObject::connect(&window, SIGNAL(setLastSourceParameter(std::string, double)),
                     &config, SLOT(setLastSourceParameter(std::string, double)));
    QObject::connect(&window, SIGNAL(removeLastSource()),
                     &config, SLOT(removeLastSource()));


    window.show();



    //YamlConfigParser ycp;
    //ycp.parseFile("model.yaml");
    //ycp.saveFile("model.yaml");

    return a.exec();
}
