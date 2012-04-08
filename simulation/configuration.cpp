#include "configuration.h"

Configuration::Configuration(QObject *parent) :
    QObject(parent)
{
    controller = new ControllerP(1);
    source = new MultiSource();
    object = new NonStationaryDiscreteObject();

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
//TOTO: przeniesc gdzies te emity.... gdziekolwiek ale nie tu! i nie w konstruktorze!
    emit setController(dynamic_cast<ObjectSISO*>(controller));
    emit setObject(object);
    emit setSource(source);

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
    //node["controllers"] >> controllers; //nie mozna, bo w pliku yaml jest wektor ktory jest parsowany do mapy
    for(unsigned int i=0;i<node["controllers"].size();i++) {
        ControllerData controllerData = ControllerData();
        node["controllers"][i] >> controllerData;
        controllers[controllerData.getType()] = controllerData;
    }

    emit retObjectsList(getObjectsKeys());
}

void Configuration::saveConfig(std::string n_filename){
    if(!n_filename.empty()){
        filename = n_filename;
    }

    YAML::Emitter emitter;

    // emitter << objects; //nie mozna, bo mapa musi byc zapisana jak wektor a nie jak mapa.
    emitter << YAML::BeginMap;

    emitter << YAML::Key << "objects" << YAML::Value;
    emitter << YAML::BeginSeq;
    std::map<std::string, ObjectData>::iterator it1;
    for(it1 = objects.begin(); it1 != objects.end(); it1++){
        emitter << (*it1).second;
    }
    emitter << YAML::EndSeq;

    // emitter << controllers; //nie mozna, bo mapa musi byc zapisana jak wektor a nie jak mapa.
    emitter << YAML::Key << "controllers" << YAML::Value;
    emitter << YAML::BeginSeq;
    std::map<std::string, ControllerData>::iterator it2;
    for(it2 = controllers.begin(); it2 != controllers.end(); it2++){
        emitter << (*it2).second;
    }
    emitter << YAML::EndSeq;

    emitter << YAML::EndMap;


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
    object->setData(objects[name]);
    //emit setObject(object);
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
