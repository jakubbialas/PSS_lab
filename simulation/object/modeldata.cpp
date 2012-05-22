#include "modeldata.h"

ModelData::ModelData():
    B(std::vector<double>(0)),
    A(std::vector<double>(0)),
    k(0),
    t(0),
    noiseRatio(0){}

ModelData::ModelData(std::vector<double> n_B, std::vector<double> n_A, unsigned int n_k, unsigned int n_t, double n_noiseRatio):
    B(n_B),
    A(n_A),
    k(n_k),
    t(n_t),
    noiseRatio(n_noiseRatio){}

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

void ModelData::setK(unsigned int n_k){
    k = n_k;
}

unsigned int ModelData::getK() const{
    return k;
}

void ModelData::setT(unsigned int n_t){
    t = n_t;
}

unsigned int ModelData::getT() const{
    return t;
}

void ModelData::setNoiseRatio(double n_nr){
    if(n_nr<0) n_nr = 0;
    noiseRatio = n_nr;
}

double ModelData::getNoiseRatio() const{
    return noiseRatio;
}


YAML::Emitter& operator << (YAML::Emitter &emitter, const ModelData &md){
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "t" << YAML::Value << md.getT();
    emitter << YAML::Key << "A" << YAML::Value << YAML::Flow << md.getA();
    emitter << YAML::Key << "B" << YAML::Value << YAML::Flow << md.getB();
    emitter << YAML::Key << "k" << YAML::Value << md.getK();
    emitter << YAML::Key << "nr" << YAML::Value << md.getNoiseRatio();
    emitter << YAML::EndMap;
    return emitter;
}

std::ostream& operator << (std::ostream &stream, const ModelData &md){
    stream << "[ ";
    stream << "t: " << md.getT() << ", ";
    stream << "A: " << md.getA() << ", ";
    stream << "B: " << md.getB() << ", ";
    stream << "k: " << md.getK() << ", ";
    stream << "nr: " << md.getNoiseRatio() << "";
    stream << "]";
    return stream;
}

void operator >> (const YAML::Node& node, ModelData &md) {
    try{
        node["B"] >> md.B;
        node["A"] >> md.A;
        node["k"] >> md.k;
        node["t"] >> md.t;
        node["nr"] >> md.noiseRatio;
    }catch(std::exception& e){
        throw PSSYAMLParserParameterNotFoundException();
    }
}
