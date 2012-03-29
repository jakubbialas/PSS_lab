#include "yamlconfigparser.h"

YamlConfigParser::YamlConfigParser(){
}

YamlConfigParser::~YamlConfigParser(){
}

void operator >> (const YAML::Node& node, std::vector<double> &v) {
    double a;
    v.resize(node.size());
    for(int i=0; i<node.size(); i++){
        node[i] >> v[i];
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
