#include "configuration.h"

Configuration::Configuration(QObject *parent) :
    QObject(parent)
{
    controller = NULL;
    currentControllerType = "";
    source = NULL;
    object = new NonStationaryDiscreteObject();

}

Configuration::~Configuration(){
    delete source;
    delete object;
    delete controller;
}

void Configuration::newConfig(){
    filename = "";
    delete source;
    delete object;
    delete controller;
    object = new NonStationaryDiscreteObject();
    objects.clear();
    adjustments.clear();

}

void Configuration::openConfig(std::string n_filename){
//TOTO: przeniesc gdzies te emity.... gdziekolwiek ale nie tu! i nie w konstruktorze!
    emit setController(controller);
    emit setObject(object);
    emit setSource(source);

    objects.clear();
    adjustments.clear();

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
    node["adjustments"] >> adjustments;
    /*for(unsigned int i=0;i<node["controllers"].size();i++) {
        ControllerData controllerData = ControllerData();
        node["controllers"][i] >> controllerData;
        controllers[controllerData.getType()] = controllerData;
    }*/

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

    emitter << YAML::Key << "adjustments" << YAML::Value << adjustments;

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

std::vector<AdjustmentData> Configuration::getAdjustments(){
    /*std::map<std::string, std::vector<std::string> > keys;
    std::map<std::string, ControllerData>::iterator it;
    for(it = controllers.begin(); it != controllers.end(); it++){
        keys[(*it).first] = (*it).second.getAdjustmentsNames();
    }*/
    return adjustments;
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



std::vector<AdjustmentData>::iterator Configuration::findAdjustment(std::string ctype, std::string name){
    std::vector<AdjustmentData>::iterator it, it_r = adjustments.end();
    for(it = adjustments.begin(); it!=adjustments.end(); it++){
        if((*it).getName().compare(name) == 0 && (*it).getType().compare(ctype) == 0){
            it_r = it;
        }
    }
    return it_r;
}

void Configuration::getAdjustmentsList(){
    emit retAdjustmentsList(getAdjustments());
}

void Configuration::removeAdjustment(std::string ctype, std::string name){
    adjustments.erase(findAdjustment(ctype, name));
    emit retAdjustmentsList(getAdjustments());
}

void Configuration::saveAdjustment(AdjustmentData ad){
    std::vector<AdjustmentData>::iterator it = findAdjustment(ad.getType(), ad.getName());
    if(it != adjustments.end()){
        (*it) = ad;
    }else{
        adjustments.push_back(ad);
    }
    emit retAdjustmentsList(getAdjustments());
}

void Configuration::setActiveAdjustment(AdjustmentData ad){
    if(currentControllerType.compare(ad.getType()) != 0){
        delete controller;
        if(ad.getType().compare("P") == 0){
            controller = new ControllerP();
            currentControllerType = "P";
        }else if(ad.getType().compare("PID") == 0){
            controller = new ControllerPID();
            currentControllerType = "PID";
        }else{
            currentControllerType = "";
        }
        emit setController(controller);
    }
    if(controller != NULL){
        std::ostringstream ret;
        std::map<std::string, double>::iterator it;
        std::map<std::string, double> param = ad.getParameters();
        for(it = param.begin(); it!=param.end(); it++){
            controller->setParameter((*it).first, (*it).second);
            ret << " " << (*it).first << ": " << (*it).second;
        }
        emit retActiveAdjustment(currentControllerType, ret.str());
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
   // emit setActiveSimpleSource();
}
