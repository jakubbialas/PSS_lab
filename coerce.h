#ifndef COERCE_H
#define COERCE_H
#include "discreteobject.h"

class Coerce
{
public:
    enum CoercionType { STEP, IMP, NONE, CUSTOM };

    Coerce();
    Coerce(CoercionType n_Type);

    void setCoercionType(CoercionType);
    double nextSample(double);

private:
    CoercionType type;
    bool impFlag;
};

#endif // COERCE_H
