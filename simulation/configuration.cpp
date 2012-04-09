#include "configuration.h"

Configuration::Configuration(QObject *parent) :
    QObject(parent)
{
    controller = new ControllerP(1);
    currentControllerType = "P";
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
    emit setController(controller);
    emit setObject(object);
    emit setSource(source);

    objects.clear();
    controllers.clear();

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
    emit retAdjustmentsList(getAdjustments());
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
    std::vector<std::string> keys;
    std::map<std::string, ObjectData>::iterator it;
    for(it = objects.begin(); it != objects.end(); it++){
        keys.push_back((*it).first);
    }
    return keys;
}

std::map<std::string, ControllerData> Configuration::getAdjustments(){
    /*std::map<std::string, std::vector<std::string> > keys;
    std::map<std::string, ControllerData>::iterator it;
    for(it = controllers.begin(); it != controllers.end(); it++){
        keys[(*it).first] = (*it).second.getAdjustmentsNames();
    }*/
    return controllers;
}





void Configuration::getObjectsList(){
    emit retObjectsList(getObjectsKeys());
}

void Configuration::getObjectData(std::string name){
    emit retObjectData(objects[name]);
}

void Configuration::removeObject(std::string name){
    std::map<std::string, ObjectData>::iterator it = objects.find(name);
    objects.erase(it);
    emit retObjectsList(getObjectsKeys());
}

void Configuration::editObject(std::string name, ObjectData od){
    if(od.getName().compare(name) != 0){
        removeObject(name);
        objects[od.getName()] = od;
    }else{
        objects[name] = od;
    }
    emit retObjectsList(getObjectsKeys());
}

void Configuration::setActiveObject(std::string name){
    object->setData(objects[name]);
    //emit setObject(object);
    emit retActiveObject(name);
}


void Configuration::getAdjustmentsList(){
    emit retAdjustmentsList(getAdjustments());
}

void Configuration::removeAdjustment(std::string ctype, std::string name){
    this->controllers[ctype].removeAdjustment(name);
    emit retAdjustmentsList(getAdjustments());
}

void Configuration::saveAdjustment(std::string ctype, AdjustmentData ad){
    this->controllers[ctype].addAdjustment(ad);
    emit retAdjustmentsList(getAdjustments());
}

void Configuration::setActiveController(std::string ctype, AdjustmentData ad){
    if(currentControllerType.compare(ctype) != 0){
        if(ctype.compare("P") == 0){
            delete controller;
            controller = new ControllerP();
            emit setController(controller);
            currentControllerType = "P";
        }
        if(ctype.compare("PID") == 0){
            delete controller;
            controller = new ControllerPID();
            emit setController(controller);
            currentControllerType = "PID";
        }
    }
    if(controller != NULL){
        std::ostringstream ret;
        std::map<std::string, double>::iterator it;
        std::map<std::string, double> param = ad.getParameters();
        for(it = param.begin(); it!=param.end(); it++){
            controller->setParameter((*it).first, (*it).second);
            ret << " " << (*it).first << ": " << (*it).second;
        }
        emit retActiveController(currentControllerType, ret.str());
    }
}



void Configuration::setActiveSimpleSource(std::string type, std::map<std::string, double> param){
    delete source;
    if(type.compare("step") == 0){
        source = new StepSource();
    }else if(type.compare("impuls") == 0){
        source = new ImpulsSource();
    }else if(type.compare("sinus") == 0){
        source = new SinusSource();
    }else if(type.compare("square") == 0){
        source = new SquareSource();
    }else if(type.compare("triangle") == 0){
        source = new TriangleSource();
    }else if(type.compare("noise") == 0){
        source = new NoiseSource();
    }
    if(source != NULL){
        std::map<std::string, double>::iterator it;
        for(it = param.begin(); it!=param.end(); it++){
            source->setParameter((*it).first, (*it).second);
        }
    }
    emit setSource(source);
}
