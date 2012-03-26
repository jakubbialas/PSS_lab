#ifndef MODELDATA_H
#define MODELDATA_H

#include <string>
#include <vector>

class ModelData
{
public:
    ModelData();

    std::vector<double> B;
    std::vector<double> A;
    int k;
    int t;
};

#endif // MODELDATA_H
