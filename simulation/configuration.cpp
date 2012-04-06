#include "configuration.h"

Configuration::Configuration(QObject *parent) :
    QObject(parent)
{
}

Configuration::~Configuration(){
}

void Configuration::newConfig(){
    filename = "";
    //objects = NULL;
}

void Configuration::openConfig(std::string n_filename){
    filename = n_filename;
    std::ifstream file(filename.c_str());
    YAML::Parser parser(file);
    YAML::Node node;
    parser.GetNextDocument(node);
    file.close();

    //node["objects"] >> objects; //nie mozna, bo w pliku yaml jest wektor ktory jest parsowany do mapy
    for(unsigned int i=0;i<node["objects"].size();i++) {
        ObjectData objectData = ObjectData();
        node["objects"][i] >> objectData;
        objects[objectData.getName()] = objectData;
    }

    emit setObjectsList(getKeys());
}

void Configuration::saveConfig(std::string n_filename){
    if(!n_filename.empty()){
        filename = n_filename;
    }

    YAML::Emitter emitter;

    // emitter << objects; //nie mozna, bo mapa musi byc zapisana jak wektor a nie jak mapa.
    emitter << YAML::BeginMap << YAML::Key << "objects" << YAML::Value;
    emitter << YAML::BeginSeq;
    std::map<std::string, ObjectData>::iterator it;
    for(it = objects.begin(); it != objects.end(); it++){
        emitter << (*it).second;
    }
    emitter << YAML::EndSeq << YAML::EndMap;

    std::ofstream file(filename.c_str());
    file << emitter.c_str();
    file.close();

}

void Configuration::setObject(std::string name){
    emit setObject(objects[name]);
}

bool Configuration::hasKey(std::string name){
    return (objects.find(name) != objects.end());
}

std::vector<std::string> Configuration::getKeys(){
    std::vector<std::string> objectList;
    std::map<std::string, ObjectData>::iterator it;

    for(it = objects.begin(); it != objects.end(); it++){
        objectList.push_back((*it).first);
    }
    return objectList;
}
