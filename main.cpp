#include <QtGui/QApplication>
//#include <iostream>
//#include <stdlib.h>
//#include <QLabel>
//#include <QTimer>
#include "gui/mainwindow.h"
#include "simulation/simulation.h"
using namespace std;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;

    Simulation simulation;

    QObject::connect(&window, SIGNAL(loadConfig(const char * )),
                     &simulation, SLOT(loadConfig(const char * )));

/*    QObject::connect(&window, SIGNAL(setSourceType(std::string)),
                     &simulation, SLOT(setSourceType(std::string)));
    QObject::connect(&window, SIGNAL(setSourceParameter(std::string, double)),
                     &simulation, SLOT(setSourceParameter(std::string, double)));
  */
    QObject::connect(&window, SIGNAL(addSource(std::string)),
                     &simulation, SLOT(addSource(std::string)));
    QObject::connect(&window, SIGNAL(setLastSourceParameter(std::string, double)),
                         &simulation, SLOT(setLastSourceParameter(std::string, double)));
    QObject::connect(&window, SIGNAL(removeLastSource()),
                         &simulation, SLOT(removeLastSource()));
    QObject::connect(&window, SIGNAL(setFeedback(bool)),
                         &simulation, SLOT(setFeedback(bool)));


    QObject::connect(&window, SIGNAL(setControllerType(std::string)),
                     &simulation, SLOT(setControllerType(std::string)));
    QObject::connect(&window, SIGNAL(setControllerParameter(std::string, double)),
                     &simulation, SLOT(setControllerParameter(std::string, double)));

    QObject::connect(&window, SIGNAL(setSamplingTime(int)),
                     &simulation, SLOT(setSamplingTime(int)));

    QObject::connect(&window, SIGNAL(setObject(std::string)),
                     &simulation, SLOT(setObject(std::string)));


    QObject::connect(&window, SIGNAL(startSimulation()),
                     &simulation, SLOT(startSimulation()));
    QObject::connect(&window, SIGNAL(stopSimulation()),
                     &simulation, SLOT(stopSimulation()));
    QObject::connect(&window, SIGNAL(resetSimulation()),
                     &simulation, SLOT(resetSimulation()));
    QObject::connect(&window, SIGNAL(stepSimulation(int)),
                     &simulation, SLOT(stepSimulation(int)));

    QObject::connect(&simulation, SIGNAL(drawInput(double)),
                     &window, SLOT(drawInput(double)));
    QObject::connect(&simulation, SIGNAL(drawOutput(double)),
                     &window, SLOT(drawOutput(double)));
    QObject::connect(&simulation, SIGNAL(drawError(double)),
                     &window, SLOT(drawError(double)));
    QObject::connect(&simulation, SIGNAL(drawControl(double)),
                     &window, SLOT(drawControl(double)));

    QObject::connect(&simulation, SIGNAL(setObjectsList(std::vector<std::string>)),
                     &window, SLOT(setObjectsList(std::vector<std::string>)));


    window.show();



    /*YamlConfigParser ycp;
    ycp.parseFile("model.yaml");
    ycp.saveFile("sdassd");*/
    return a.exec();
}
