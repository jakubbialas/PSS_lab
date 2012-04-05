#ifndef NOISESOURCE_H
#define NOISESOURCE_H

#include "source.h"
#include <cstdlib>

class NoiseSource : public Source
{
private:
    double amplitude;

public:
    NoiseSource();

    void setParameter(std::string, double);
    double getNextSample();
    double getSample();
};

#endif // NOISESOURCE_H
