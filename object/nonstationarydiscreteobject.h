#ifndef NONSTATIONARYDISCRETEOBJECT_H
#define NONSTATIONARYDISCRETEOBJECT_H

#include "discreteobject.h"
#include "objectdata.h"

class NonStationaryDiscreteObject : public DiscreteObject
{
private:
    ObjectData data;  /**< TODO */

    void updateModel();

public:
    NonStationaryDiscreteObject();
    ~NonStationaryDiscreteObject();
    NonStationaryDiscreteObject(ObjectData);

    void setData(ObjectData);

    void reset();
    double simulate(double);
};

#endif // NONSTATIONARYDISCRETEOBJECT_H
