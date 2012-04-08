#include "configuration.h"

Configuration::Configuration(QObject *parent) :
    QObject(parent)
{
    controller = new ControllerP(1);
    source = new MultiSource();
    object = new NonStationaryDiscreteObject();

    emit setController(controller);
    emit setObject(object);
    emit setSource(source);
}

Configuration::~Configuration(){
    delete source;
    delete object;
    delete controller;
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

    emit retObjectsList(getObjectsKeys());
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

std::vector<std::string> Configuration::getObjectsKeys(){
    std::vector<std::string> objectList;
    std::map<std::string, ObjectData>::iterator it;

    for(it = objects.begin(); it != objects.end(); it++){
        objectList.push_back((*it).first);
    }
    return objectList;
}






void Configuration::getObjectsList(){
    emit retObjectsList(getObjectsKeys());
}

void Configuration::getObjectData(std::string name){
    emit retObjectData(objects[name]);
}

void Configuration::editObjectData(std::string name, ObjectData od){
    objects[name] = od;
    if(od.getName() != name){
        //TODO: change name;
    }
}

void Configuration::setActiveObject(std::string name){
    emit setObject(new NonStationaryDiscreteObject(objects[name]));
    emit retActiveObject(name);
}






void Configuration::addSource(std::string type){
    source->addSource(type);
}

void Configuration::setLastSourceParameter(std::string name, double value){
    source->setLastSourceParameter(name, value);
}

void Configuration::removeLastSource(){
    source->removeLastSource();
}

void Configuration::setControllerType(std::string type){
    if(type.compare("P") == 0){
        delete controller;
        controller = new ControllerP();
    }
}

void Configuration::setControllerParameter(std::string name, double value){
    this->controller->setParameter(name, value);
}
