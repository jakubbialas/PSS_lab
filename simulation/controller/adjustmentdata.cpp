#include "adjustmentdata.h"

AdjustmentData::AdjustmentData(){
}

AdjustmentData::AdjustmentData(std::string n_type, std::string n_name, std::map<std::string, double> n_parameters){
    type = n_type;
    name = n_name;
    parameters = n_parameters;
}

AdjustmentData::~AdjustmentData(){
}

void AdjustmentData::setName(std::string n_name){
    name = n_name;
}

std::string AdjustmentData::getName() const{
    return name;
}

void AdjustmentData::setType(std::string n_type){
    type = n_type;
}

std::string AdjustmentData::getType() const{
    return type;
}

void AdjustmentData::setParemeters(std::map<std::string, double> n_parameters){
    parameters = n_parameters;
}

std::map<std::string, double> AdjustmentData::getParameters() const{
    return parameters;
}

YAML::Emitter& operator << (YAML::Emitter &emitter, const AdjustmentData &ad ){
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "type" << YAML::Value << ad.getType();
    emitter << YAML::Key << "name" << YAML::Value << ad.getName();
    emitter << YAML::Key << "parameters" << YAML::Value << ad.getParameters();
    emitter << YAML::EndMap;
    return emitter;
}

std::ostream& operator << (std::ostream &stream, const AdjustmentData &ad){
    stream << "[ ";
    stream << "type: " << ad.getType() << ", ";
    stream << "name: " << ad.getName() << ", ";
    stream << "parameters: " << ad.getParameters() << "";
    stream << " ]";
    return stream;
}

void operator >> (const YAML::Node& node, AdjustmentData &ad) {
    node["type"] >> ad.type;
    node["name"] >> ad.name;
    node["parameters"] >> ad.parameters;
}
