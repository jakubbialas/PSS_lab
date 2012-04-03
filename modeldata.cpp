#include "modeldata.h"


void ModelData::saveKey(YAML::Emitter * emitter, int t, std::vector<double> A, std::vector<double> B, int k){

    *emitter << YAML::BeginSeq <<YAML::BeginMap;

    *emitter << YAML::Key << "t" << YAML::Value << t;

    *emitter << YAML::Key << "A";
    *emitter << YAML::Value<<YAML::Flow;
    *emitter << YAML::BeginSeq;
    for(unsigned int i = 0; i < A.size(); i++ ){
        *emitter << A.at(i);
    }
    *emitter << YAML::EndSeq;

    *emitter << YAML::Key << "B";
    *emitter << YAML::Value << YAML::Flow;
    *emitter << YAML::BeginSeq;
    for(unsigned int i = 0; i < B.size(); i++ ){
        *emitter << B.at(i);
    }
    *emitter << YAML::EndSeq;

    *emitter << YAML::Key << "K" << YAML::Value << k;
    *emitter << YAML::EndMap;
    *emitter << YAML::EndSeq;

}

void operator<<(std::ofstream &stream, ModelData &md){

    YAML::Emitter emitter;
    emitter << YAML::BeginMap << YAML::Key << "objects" << YAML::Value;

    emitter << YAML::BeginSeq;
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "name" << YAML::Value << "default";


    emitter << YAML::Key <<  "models";
    emitter << YAML::Value;

    md.saveKey(&emitter, md.t,md.A,md.B,md.k);

    emitter << YAML::EndSeq << YAML::EndMap;;

    stream << emitter.c_str();
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

std::vector<double> ModelData::getB(){
    return B;
}

void ModelData::setA(std::vector<double> n_A){
    A = n_A;
}

std::vector<double> ModelData::getA(){
    return A;
}

void ModelData::setK(int n_k){
    k = n_k;
}

int ModelData::getK(){
    return k;
}

void ModelData::setT(int n_t){
    t = n_t;
}

int ModelData::getT(){
    return t;
}



