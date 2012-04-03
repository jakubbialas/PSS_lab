#include "objectdata.h"

ObjectData::ObjectData(){
}

ObjectData::ObjectData(std::string n_name, std::vector<ModelData> n_models){
    name = n_name;
    models = n_models;
}

ObjectData::~ObjectData(){
}

void ObjectData::setName(std::string n_name){
    name = n_name;
}

std::string ObjectData::getName(){
    return name;
}

void ObjectData::setModels(std::vector<ModelData> n_models){
    models = n_models;
}

std::vector<ModelData> ObjectData::getModels(){
    return models;
}

void ObjectData::addModel(ModelData model){
    models.push_back(model);
}

void operator << (std::ofstream &filestream, ObjectData &md ){

    YAML::Emitter emitter;
    emitter << YAML::BeginMap << YAML::Key << "objects" << YAML::Value;

    emitter << YAML::BeginSeq << YAML::BeginMap;
    emitter << YAML::Key << "name" << YAML::Value << md.getName();


    emitter << YAML::Key <<  "models";
    emitter << YAML::Value;
    emitter << YAML::BeginSeq;
    for(unsigned int j = 0; j < md.getModels().size(); j++ ){
        md.getModels().at(j).saveKey(&emitter, md.getModels().at(j).getT(),md.getModels().at(j).getA(),md.getModels().at(j).getB(),md.getModels().at(j).getK());
    }

    emitter << YAML::EndSeq;
    emitter << YAML::EndSeq << YAML::EndMap;

    filestream << emitter.c_str();
    std::cout << "emitter : " << emitter.c_str() << std::endl;
}

void operator << (std::ofstream &filestream, std::vector<ObjectData> &md ){

    YAML::Emitter emitter;
    emitter << YAML::BeginMap << YAML::Key << "objects" << YAML::Value;
    emitter << YAML::BeginSeq;

    std::cout << "wektorowy ObjectData, rozmiar " << md.size() << std::endl;

    for(unsigned int i = 0; i < md.size(); i ++){
        emitter << YAML::BeginMap;
        emitter << YAML::Key << "name" << YAML::Value << md.at(i).getName();

        emitter << YAML::Key <<  "models";
        emitter << YAML::Value;

        emitter << YAML::BeginSeq;
        for(unsigned int j = 0; j < md.at(i).getModels().size(); j++ ){
            md.at(i).getModels().at(j).saveKey(&emitter, md.at(i).getModels().at(j).getT(),md.at(i).getModels().at(j).getA(),md.at(i).getModels().at(j).getB(),md.at(i).getModels().at(j).getK());
        }
        emitter << YAML::EndSeq;

        emitter << YAML::EndMap;
    }

    emitter << YAML::EndSeq;
    emitter<< YAML::EndMap;

    filestream << emitter.c_str();
    std::cout << "emitter : " << emitter.c_str() << std::endl;
}
