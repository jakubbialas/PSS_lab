#include "sourcedata.h"

SourceData::SourceData(){
}

SourceData::SourceData(std::string n_type, std::map<std::string, double> n_parameters){
    type = n_type;
    parameters = n_parameters;
}

void SourceData::setType(std::string n_type){
    type = n_type;
}

std::string SourceData::getType() const{
    return type;
}

void SourceData::setParameters(std::map<std::string, double> n_parameters){
    parameters = n_parameters;
}

std::map<std::string, double> SourceData::getParameters() const{
    return parameters;
}

YAML::Emitter& operator << (YAML::Emitter &emitter, const SourceData &sd){
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "type" << YAML::Value << sd.getType();
    emitter << YAML::Key << "parameters" << YAML::Value << sd.getParameters();
    emitter << YAML::EndMap;
    return emitter;
}

std::ostream& operator << (std::ostream &stream, const SourceData &sd){
    stream << "[ ";
    stream << "type: " << sd.getType() << ", ";
    stream << "parameters: " << sd.getParameters() << "";
    stream << " ]";
    return stream;
}

void operator >> (const YAML::Node& node, SourceData &sd) {
    node["type"] >> sd.type;
    node["parameters"] >> sd.parameters;
}
