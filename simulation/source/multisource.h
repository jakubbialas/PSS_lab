#ifndef MULTISOURCE_H
#define MULTISOURCE_H

#include "source.h"

#include "stepsource.h"
#include "impulssource.h"
#include "trianglesource.h"
#include "sinussource.h"
#include "noisesource.h"
#include "squaresource.h"

#include <vector>

class MultiSource : public Source
{
public:
    MultiSource();

    void setParameter(std::string, double);
    double getSample();

    void addSource(std::string);
    void removeLastSource();
    void setLastSourceParameter(std::string, double);

private:
    std::vector<Source*> sources;
};

#endif // MULTISOURCE_H
