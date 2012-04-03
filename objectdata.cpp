#include "objectdata.h"

ObjectData::ObjectData(){
}

ObjectData::ObjectData(std::string n_name, std::vector<ModelData> n_models){
    name = n_name;
    models = n_models;
}

ObjectData::~ObjectData(){
}

void ObjectData::setName(std::string n_name){
    name = n_name;
}

std::string ObjectData::getName(){
    return name;
}

void ObjectData::setModels(std::vector<ModelData> n_models){
    models = n_models;
}

std::vector<ModelData> ObjectData::getModels(){
    return models;
}

void ObjectData::addModel(ModelData model){
    models.push_back(model);
}
