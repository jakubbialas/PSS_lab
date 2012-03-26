#include "coerce.h"

Coerce::Coerce(){
    type = STEP;
    impFlag = false;
}

Coerce::Coerce(CoercionType n_Type){
    type = n_Type;
    impFlag = false;
}

void Coerce::setCoercionType(CoercionType n_Type){
    type = n_Type;
    impFlag = false;
}

double Coerce::nextSample(double input = 0){
    switch(type){
        case STEP:
            return 1;
        case IMP:
            if(impFlag) return 0;
            else { impFlag = true; return 1;}
        case NONE:
            return 0;
        case CUSTOM:
            return input;
        default:
            return 0;
    }
}
