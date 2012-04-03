#include "yamlconfigparser.h"

YamlConfigParser::YamlConfigParser()
{
}

void operator >> (const YAML::Node& node, std::vector<double> &v) {
    double a;
    v.resize(node.size());
    for(unsigned int i=0; i<node.size(); i++){
        node[i] >> a;
        v[i] = a;
    }
}

void operator >> (const YAML::Node& node, ModelData &md) {
    node["B"] >> md.B;
    node["A"] >> md.A;
    node["k"] >> md.k;
    node["t"] >> md.t;
}

void operator >> (const YAML::Node& node, std::vector<ModelData> &mdv) {

    for(unsigned i=0;i<node.size();i++) {
        ModelData modelData = ModelData();
        node[i] >> modelData;
        mdv.push_back(modelData);
    }
}

void operator >> (const YAML::Node& node, ObjectData &md) {
    node["name"] >> md.name;
    node["models"] >> md.models;
}

void operator >> (const YAML::Node& node, std::map<std::string, ObjectData> &md) {
    for(unsigned i=0;i<node.size();i++) {
        ObjectData objectData = ObjectData();
        node[i] >> objectData;
        md[objectData.name] = objectData;
    }
}

void YamlConfigParser::parseFile(const char * filename){
    std::ifstream fin(filename);
    YAML::Parser parser(fin);
    YAML::Node doc;
    parser.GetNextDocument(doc);

    doc["objects"] >> objects;
}


void operator << (std::ofstream filestream, ObjectData &md ){

    YAML::Emitter emitter;
    emitter << YAML::BeginMap << YAML::Key << "objects" << YAML::Value;

    emitter << YAML::BeginSeq;
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "name" << YAML::Value << md.name;


    emitter << YAML::Key <<  "models";
    emitter << YAML::Value;

    for(unsigned int j = 0; j < md.models.size(); j++ ){
        md.models.at(j).saveKey(&emitter, md.models.at(j).t,md.models.at(j).A,md.models.at(j).B,md.models.at(j).k);
    }
    emitter << YAML::EndSeq << YAML::EndMap;;

    filestream << emitter.c_str();
    std::cout << "emitter : " << emitter.c_str() << std::endl;
}


void operator <<(std::ofstream filestream, std::vector<ModelData> &mdv ){

    YAML::Emitter emitter;
    emitter << YAML::BeginMap << YAML::Key << "objects" << YAML::Value;

    emitter << YAML::BeginSeq;
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "name" << YAML::Value << "default";


    emitter << YAML::Key <<  "models";
    emitter << YAML::Value;

    for(unsigned int j = 0; j < mdv.size(); j++ ){
        mdv.at(j).saveKey(&emitter, mdv.at(j).t,mdv.at(j).A,mdv.at(j).B,mdv.at(j).k);
    }
    emitter << YAML::EndSeq << YAML::EndMap;;

    filestream << emitter.c_str();
    std::cout << "emitter : " << emitter.c_str() << std::endl;
}


void operator <<(std::ofstream filestream, ModelData &md ){

    YAML::Emitter emitter;
    emitter << YAML::BeginMap << YAML::Key << "objects" << YAML::Value;

    emitter << YAML::BeginSeq;
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "name" << YAML::Value << "default";

    emitter << YAML::Key <<  "models";
    emitter << YAML::Value;

    md.saveKey(&emitter, md.t,md.A,md.B,md.k);

    emitter << YAML::EndSeq << YAML::EndMap;;

    filestream << emitter.c_str();
    std::cout << "emitter : " << emitter.c_str() << std::endl;
}

void YamlConfigParser::yamlEmitter(std::string name, int t, std::vector<double> A, std::vector<double> B, int k ){

    YAML::Emitter emitter;
    emitter << YAML::BeginMap << YAML::Key << "objects" << YAML::Value;

    emitter << YAML::BeginSeq;
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "name" << YAML::Value << name;

    emitter << YAML::Key <<  "models";
    emitter << YAML::Value;

    saveKey(&emitter, t,A,B,k);

    emitter << YAML::EndSeq;

    emitter << YAML::EndMap;
    std::ofstream fout("file.txt");
    fout << emitter.c_str();
    std::cout << "emitter : " << emitter.c_str() << std::endl;
}

ObjectData YamlConfigParser::getObject(std::string name){
    return objects[name];
}

bool YamlConfigParser::hasKey(std::string name){
    return (objects.find(name) != objects.end());
}

std::vector<std::string> YamlConfigParser::getKeys(){
    std::vector<std::string> objectList;
    std::map<std::string, ObjectData>::iterator it;

    for(it = objects.begin(); it != objects.end(); it++){
        objectList.push_back((*it).first);
    }
    return objectList;
}


void YamlConfigParser::saveKey(YAML::Emitter * emitter, int t, std::vector<double> A, std::vector<double> B, int k){

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
