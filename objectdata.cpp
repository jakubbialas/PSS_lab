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

std::string  ObjectData::getName() const{
    return name;
}

void ObjectData::setModels(std::vector<ModelData> n_models){
    models = n_models;
}


std::vector<ModelData> ObjectData::getModels() const{
    return models;
}

void ObjectData::addModel(ModelData model){
    models.push_back(model);
}

YAML::Emitter& operator << (YAML::Emitter &emitter, const ObjectData &md ){

    emitter << YAML::BeginMap;
    emitter << YAML::Key << "name" << YAML::Value << static_cast<std::string>(md.getName());

    emitter << YAML::Key <<  "models";
    emitter << YAML::Value;
    emitter << YAML::BeginSeq;

    emitter << md.getModels();

    emitter << YAML::EndSeq;
    emitter << YAML::EndMap;
    return emitter;
}

YAML::Emitter& operator << (YAML::Emitter &emitter, std::vector<ObjectData> &md ){

    emitter << YAML::BeginMap << YAML::Key << "objects" << YAML::Value;
    emitter << YAML::BeginSeq;

    for(unsigned int i = 0; i < md.size(); i ++){
        emitter << md.at(i);
    }

    emitter << YAML::EndSeq;
    emitter<< YAML::EndMap;

    return emitter;
}
