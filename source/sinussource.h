#ifndef SINUSSOURCE_H
#define SINUSSOURCE_H

#include "source.h"
#include "math.h"

class SinusSource : public Source
{
public:
    double amplitude;
    double frequency;

public:
    SinusSource();

    void setParameter(std::string, double);
    double getNextSample();
    double getSample();
};

#endif // SINUSSOURCE_H
