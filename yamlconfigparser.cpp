#include "yamlconfigparser.h"

YamlConfigParser::YamlConfigParser()
{
}

void operator >> (const YAML::Node& node, std::vector<double> &v) {
    double a;
    v.resize(node.size());
    for(int i=0; i<node.size(); i++){
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
