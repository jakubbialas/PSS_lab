#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QTimer>
#include "discreteobject.h"
#include "coerce.h"
#include "yamlconfigparser.h"

class Simulation : public QObject
{
    Q_OBJECT
public:
    explicit Simulation(QObject *parent = 0);

signals:
//signals to draw on plots:
    void drawInput(double y);
    void drawOutput(double y);
    void drawError(double y);
    void drawControl(double y);

public slots:
//slots to set config:
    void loadConfig(const char * filename);
    void setCoercionType(Coerce::CoercionType);
    void setCoercionValue(double);
    void setSamplingTime(int);

//slots to simulate:
    void startSimulation();
    void stopSimulation();
    void resetSimulation();
    void stepSimulation(int);

    void nextStep();

private:

    QTimer *timer;

    YamlConfigParser ymp;

    DiscreteObject * object;
    Coerce * coerce;

    int samplingTime;
};

#endif // SIMULATION_H
