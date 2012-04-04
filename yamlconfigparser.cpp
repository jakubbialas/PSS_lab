#include "yamlconfigparser.h"

YamlConfigParser::YamlConfigParser(){
}

YamlConfigParser::~YamlConfigParser(){
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
    std::vector<double> B, A;
    int k, t;
    node["B"] >> B;
    node["A"] >> A;
    node["k"] >> k;
    node["t"] >> t;
    md.setB(B);
    md.setA(A);
    md.setK(k);
    md.setT(t);
}

void operator >> (const YAML::Node& node, ObjectData &od) {
    std::string name;
    for(unsigned int i=0;i<node["models"].size();i++) {
        ModelData modelData = ModelData();
        node["models"][i] >> modelData;
        od.addModel(modelData);
    }
    node["name"] >> name;
    od.setName(name);
}

void YamlConfigParser::parseFile(const char * filename){
    std::ifstream fin(filename);
    YAML::Parser parser(fin);
    YAML::Node node;
    parser.GetNextDocument(node);

    for(unsigned int i=0;i<node["objects"].size();i++) {
        ObjectData objectData = ObjectData();
        node["objects"][i] >> objectData;
        objects[objectData.getName()] = objectData;
    }
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

void YamlConfigParser::saveFile(const char *filename){
    std::map<std::string, ObjectData>::iterator it;
    YAML::Emitter emitter;

    for(it = objects.begin(); it != objects.end(); it++){
        emitter << (*it).second;
    }

    std::cout << emitter.c_str();
}
