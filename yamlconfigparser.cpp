#include "yamlconfigparser.h"

YamlConfigParser::YamlConfigParser()
{
}

void operator >> (const YAML::Node& node, std::vector<double> &v) {
    double a;
    v.resize(node.size());
    for(int i=0; i<node.size(); i++){
        node[i] >> a;
        std::cout << a << " ";
        v[i] = a;
    }
    std::cout << "\n";
}

void operator >> (const YAML::Node& node, ModelData *md) {
    node["B"] >> md->B;
    node["A"] >> md->A;
    node["k"] >> md->k;
    node["t"] >> md->t;
}

void operator >> (const YAML::Node& node, std::vector<ModelData*> &mdv) {

    for(unsigned i=0;i<node.size();i++) {
        ModelData *modelData = new ModelData();
        node[i] >> modelData;
        mdv.push_back(modelData);
    }
}

void operator >> (const YAML::Node& node, ObjectData *md) {
    node["name"] >> md->name;
    node["models"] >> md->models;
}

void YamlConfigParser::parseFile(const char * filename){
    std::ifstream fin(filename);
    YAML::Parser parser(fin);
    YAML::Node doc;
    parser.GetNextDocument(doc);

    for(unsigned i=0;i<doc.size();i++) {
        ObjectData *objectData = new ObjectData();
        doc[i] >> objectData;
        objects[objectData->name] = objectData;

        //std::cout << modelData->name << " " << modelData->B.size() << " " << modelData->A.size() << " " << modelData->k << "\n";
    }
}

ObjectData* YamlConfigParser::getObject(std::string name){
    return objects[name];
}

bool YamlConfigParser::hasKey(std::string name){
    return (objects.find(name) != objects.end());
}
