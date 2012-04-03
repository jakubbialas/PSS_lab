#include "modeldata.h"

ModelData::ModelData()
{

}

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



