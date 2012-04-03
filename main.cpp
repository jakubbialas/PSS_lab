#include <QtGui/QApplication>
#include <iostream>
#include <stdlib.h>
#include <QLabel>
#include <QTimer>
#include "mainwindow.h"
#include "discreteobject.h"
#include "yamlconfigparser.h"
#include "simulation.h"
#include "modeldata.h"
#include <fstream>
using namespace std;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;

    Simulation simulation;

    QObject::connect(&window, SIGNAL(loadConfig(const char * )),
                     &simulation, SLOT(loadConfig(const char * )));
    QObject::connect(&window, SIGNAL(setSourceType(Source::SourceType)),
                     &simulation, SLOT(setSourceType(Source::SourceType)));
    QObject::connect(&window, SIGNAL(setSourceValue(double)),
                     &simulation, SLOT(setSourceValue(double)));
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


    YamlConfigParser  yaml;
    std::vector<double> A(3);
    std::vector<double> B(2);
    std::vector<ModelData> models(3);
    A.at(0) = 1;
    A.at(1) = 2;
    A.at(2) = 4;
    B.at(0) = 15;
    B.at(1) = 20;

    ModelData md;
    md.setA( A);
    md.setB(B);
    md.setT(20);
    md.setK(50);
    ModelData md1;
    md1.setA( A);
    md1.setB(B);
    md1.setT(19);
    md1.setK(5044);
    ModelData md2;
    md2.setA( A);
    md2.setB(B);
    md2.setT(25);
    md2.setK(450);
    models.at(0) = md;
    models.at(1) = md1;
    models.at(2) = md2;

    ObjectData od;
    od.setName("nazwa");
    od.addModel(md);
    od.addModel(md1);
    od.addModel(md2);

    std::vector<ObjectData> odv(3);
    odv.at(0) = od;
    odv.at(1) = od;
    odv.at(2) = od;

    std::ofstream fs("pliczek");
    //fs << md;
    fs << odv;
    //yaml.yamlEmitter("Obiekt_nazwa", 10,A, B, 50 );
    return a.exec();
}
