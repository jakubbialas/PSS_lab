#ifndef IMPULSSOURCE_H
#define IMPULSSOURCE_H

#include "source.h"

class ImpulsSource : public Source
{
private:
    double amplitude;

public:
    ImpulsSource();

    void setParameter(std::string, double);
    double getNextSample();
    double getSample();
};

#endif // IMPULSSOURCE_H
