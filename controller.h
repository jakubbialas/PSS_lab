#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "source.h"
#include "discreteobject.h"
#include <string>
#include <map>

class Controller : public DiscreteObject
{
public:
    Controller();
    ~Controller();

    Source source;

protected:
    std::map<std::string, double> parameter;

public:
    void setSourceType(Source::SourceType);
    void setSourceValue(double);
    virtual void setParameter(std::string, double)=0;

    double getSetPoint();
    double getError();
};

#endif // CONTROLLER_H
