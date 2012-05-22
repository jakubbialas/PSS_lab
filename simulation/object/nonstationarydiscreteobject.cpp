#include "nonstationarydiscreteobject.h"

NonStationaryDiscreteObject::NonStationaryDiscreteObject()
{
}

NonStationaryDiscreteObject::~NonStationaryDiscreteObject()
{
}

NonStationaryDiscreteObject::NonStationaryDiscreteObject(ObjectData n_data):
    data(n_data)
{
    setModel(data.getModels().at(0));
}

void NonStationaryDiscreteObject::setData(ObjectData n_data){
    data = n_data;
    setModel(data.getModels().at(0));
}

void NonStationaryDiscreteObject::updateModel(){
    if(data.getModels().size()>1){
        for(int i=0; i<data.getModels().size(); i++){
            if(data.getModels().at(i).getT() == counter){
                setModel(data.getModels().at(i));
            }
        }
    }
}

void NonStationaryDiscreteObject::reset(){
    DiscreteObject::reset();
    updateModel();
}

double NonStationaryDiscreteObject::simulate(double input){
    updateModel();
    return DiscreteObject::simulate(input);
}
