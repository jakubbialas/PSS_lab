#include "nonstationarydiscreteobject.h"

NonStationaryDiscreteObject::NonStationaryDiscreteObject()
{
}

NonStationaryDiscreteObject::~NonStationaryDiscreteObject()
{
}

NonStationaryDiscreteObject::NonStationaryDiscreteObject(ObjectData n_data){
    data = n_data;
    setModel(data.getModels().at(0));
}

void NonStationaryDiscreteObject::setData(ObjectData n_data){
    data = n_data;
    setModel(data.getModels().at(0));
}

void NonStationaryDiscreteObject::updateModel(){
    if(data.getModels().size()>1){
        ModelData model;
        for(int i=0; i<data.getModels().size(); i++){
             model = data.getModels().at(i);
             if(model.getT() == counter){
                 setModel(model);
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
