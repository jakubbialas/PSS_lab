#ifndef OBJECTDATA_H
#define OBJECTDATA_H

#include "modeldata.h"
#include <vector>

class ObjectData
{
public:
    ObjectData();
    std::vector<ModelData*> models;

    std::string name;
};

#endif // OBJECTDATA_H
