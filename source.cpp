#include "source.h"

Source::Source(){
    type = STEP;
    time = 0;
}

Source::Source(SourceType n_Type){
    type = n_Type;
    time = 0;
}

void Source::setSourceType(SourceType n_Type){
    type = n_Type;
}

void Source::setSourceValue(double n_value){
    value = n_value;
}

void Source::reset(){
    time = 0;
}

double Source::nextSample(){
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
