#include "modeldata.h"


YAML::Emitter& operator << (YAML::Emitter &emitter, const ModelData &md){

    emitter<<YAML::BeginMap;

    emitter << YAML::Key << "t" << YAML::Value << md.getT();

    emitter << YAML::Key << "A";
    emitter << YAML::Value<<YAML::Flow;
    emitter << YAML::BeginSeq;
    for(unsigned int i = 0; i < md.getA().size(); i++ ){
        emitter << md.getA().at(i);
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "B";
    emitter << YAML::Value << YAML::Flow;
    emitter << YAML::BeginSeq;
    for(unsigned int i = 0; i < md.getB().size(); i++ ){
        emitter << md.getB().at(i);
    }
    emitter << YAML::EndSeq;

    emitter << YAML::Key << "K" << YAML::Value << md.getK();

    emitter << YAML::EndMap;
    return emitter;
}

YAML::Emitter& operator <<(YAML::Emitter &emitter, const std::vector<ModelData> &mdv ){
    for(unsigned int j = 0; j < mdv.size(); j++ ){
        emitter << mdv.at(j);
    }
    return emitter;

}

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



