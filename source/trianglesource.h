#ifndef TRIANGLESOURCE_H
#define TRIANGLESOURCE_H

#include "source.h"

class TriangleSource : public Source
{
private:
    double amplitude;
    double frequency;

public:
    TriangleSource();

    void setParameter(std::string, double);
    double getNextSample();
    double getSample();
};

#endif // TRIANGLESOURCE_H
