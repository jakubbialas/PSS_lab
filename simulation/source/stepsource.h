#ifndef STEPSOURCE_H
#define STEPSOURCE_H

#include "source.h"

class StepSource : public Source
{
private:
    double amplitude;

public:
    StepSource();

    void setParameter(std::string, double);
    double getNextSample();
    double getSample();
};

#endif // STEPSOURCE_H
