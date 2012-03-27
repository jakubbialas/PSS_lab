#ifndef COERCE_H
#define COERCE_H

class Coerce
{
public:
    enum CoercionType { STEP, IMP, NONE, CUSTOM };

    Coerce();
    Coerce(CoercionType n_Type);

    void setCoercionType(CoercionType);
    void setCoercionValue(double);
    void reset();
    double nextSample();

private:
    CoercionType type;
    double value; //value for custom coerce;
    int time;
};

#endif // COERCE_H
