#ifndef MULTISOURCEDATA_H
#define MULTISOURCEDATA_H

#include <vector>
#include "sourcedata.h"

class MultiSourceData
{
public:
    MultiSourceData();

private:
    std::vector<SourceData> sources;
};

#endif // MULTISOURCEDATA_H
