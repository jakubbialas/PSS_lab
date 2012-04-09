#include "controllerdata.h"

ControllerData::ControllerData(){
}

ControllerData::ControllerData(std::string n_type, std::vector<AdjustmentData> n_adjustments){
    type = n_type;
    adjustments = n_adjustments;
}

ControllerData::~ControllerData(){
}

void ControllerData::setType(std::string n_type){
    type = n_type;
}

std::string ControllerData::getType() const{
    return type;
}

void ControllerData::setAdjustment(std::vector<AdjustmentData> n_adjustments){
    adjustments = n_adjustments;
}

std::vector<AdjustmentData> ControllerData::getAdjustments() const{
    return adjustments;
}

std::vector<std::string> ControllerData::getAdjustmentsNames(){
    std::vector<std::string> names;
    std::vector<AdjustmentData>::iterator it;
    for(it = adjustments.begin(); it != adjustments.end(); it++){
        names.push_back((*it).getName());
    }
    return names;
}
void ControllerData::removeAdjustment(std::string name){
    std::vector<AdjustmentData>::iterator it;
    std::vector<AdjustmentData>::iterator it2;
    for(it = adjustments.begin(); it != adjustments.end(); it++){
        if(name.compare((*it).getName()) == 0){
            it2 = it;
        }
    }
    adjustments.erase(it2);
}

void ControllerData::addAdjustment(AdjustmentData ad){
    adjustments.push_back(ad);
}

YAML::Emitter& operator << (YAML::Emitter &emitter, const ControllerData &cd ){
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "type" << YAML::Value << cd.getType();
    emitter << YAML::Key << "adjustments" << YAML::Value << cd.getAdjustments();
    emitter << YAML::EndMap;
    return emitter;
}

std::ostream& operator << (std::ostream &stream, const ControllerData &cd){
    stream << "[ ";
    stream << "type: " << cd.getType() << ", ";
    stream << "adjustments: " << cd.getAdjustments() << "";
    stream << " ]";
    return stream;
}

void operator >> (const YAML::Node& node, ControllerData &cd) {
    node["type"] >> cd.type;
    node["adjustments"] >> cd.adjustments;
}
