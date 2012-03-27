#include "coerce.h"

Coerce::Coerce(){
    type = STEP;
    time = 0;
}

Coerce::Coerce(CoercionType n_Type){
    type = n_Type;
    time = 0;
}

void Coerce::setCoercionType(CoercionType n_Type){
    type = n_Type;
}

void Coerce::setCoercionValue(double n_value){
    value = n_value;
}

void Coerce::reset(){
    time = 0;
}

double Coerce::nextSample(){
    double v;
    switch(type){
        case STEP:
            v = 1;
            break;
        case IMP:
            if(time == 0 ){ v = 1; }
            else { v = 0; }
            break;
        case NONE:
            v = 0;
            break;
        case CUSTOM:
            v = value;
            break;
        default:
            v = 0;
    }
    time++;
    return v;
}
