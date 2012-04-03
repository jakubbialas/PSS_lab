#ifndef SQUARESOURCE_H
#define SQUARESOURCE_H

#include "source.h"

class SquareSource : public Source
{
private:
    double amplitude;
    double frequency;
    double dutycycle;

public:
    SquareSource();

    void setParameter(std::string, double);
    double getNextSample();
    double getSample();
};

#endif // SQUARESOURCE_H
