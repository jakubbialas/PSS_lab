#include "source.h"

Source::Source(){
    time = -1;
}

int Source::getTime(){
    return time;
}

void Source::setTime(int n_time){
    time = n_time;
}

int Source::incrementTime(){
    return ++time;
}

void Source::reset(){
    time = -1;
}

double Source::getNextSample(){
    incrementTime();
    return getSample();
}
