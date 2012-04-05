#include "modeldata.h"

ModelData::ModelData(){
}

ModelData::ModelData(std::vector<double> n_B, std::vector<double> n_A, int n_k, int n_t){
    B = n_B;
    A = n_A;
    k = n_k;
    t = n_t;
}

ModelData::~ModelData(){
}

void ModelData::setB(std::vector<double> n_B){
    B = n_B;
}

std::vector<double> ModelData::getB() const{
    return B;
}

void ModelData::setA(std::vector<double> n_A){
    A = n_A;
}

std::vector<double> ModelData::getA() const{
    return A;
}

void ModelData::setK(int n_k){
    k = n_k;
}

int ModelData::getK() const{
    return k;
}

void ModelData::setT(int n_t){
    t = n_t;
}

int ModelData::getT() const{
    return t;
}

YAML::Emitter& operator << (YAML::Emitter &emitter, const ModelData &md){
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "t" << YAML::Value << md.getT();
    emitter << YAML::Key << "A" << YAML::Value << YAML::Flow << md.getA();
    emitter << YAML::Key << "B" << YAML::Value << YAML::Flow << md.getB();
    emitter << YAML::Key << "k" << YAML::Value << md.getK();
    emitter << YAML::EndMap;
    return emitter;
}

std::ostream& operator << (std::ostream &stream, const ModelData &md){
    stream << "[ ";
    stream << "t: " << md.getT() << ", ";
    stream << "A: " << md.getA() << ", ";
    stream << "B: " << md.getB() << ", ";
    stream << "k: " << md.getK() << "";
    stream << "]";
    return stream;
}

void operator >> (const YAML::Node& node, ModelData &md) {
    node["B"] >> md.B;
    node["A"] >> md.A;
    node["k"] >> md.k;
    node["t"] >> md.t;
}
