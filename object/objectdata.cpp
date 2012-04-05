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
    emitter << YAML::Key << "name"   << YAML::Value << md.getName();
    emitter << YAML::Key << "models" << YAML::Value << md.getModels();
    emitter << YAML::EndMap;
    return emitter;
}

std::ostream& operator << (std::ostream &stream, const ObjectData &md){
    stream << "[ ";
    stream << "name: " << md.getName() << ", ";
    stream << "models: " << md.getModels() << "";
    stream << " ]";
    return stream;
}

void operator >> (const YAML::Node& node, ObjectData &od) {
    node["models"] >> od.models;
    node["name"] >> od.name;
}
