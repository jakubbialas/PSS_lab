#include "multisourcedata.h"

MultiSourceData::MultiSourceData(){
}

MultiSourceData::MultiSourceData(std::string n_name, std::vector<SourceData> n_sources){
    name = n_name;
    sources = n_sources;

}

void MultiSourceData::setName(std::string n_name){
    name = n_name;
}

std::string MultiSourceData::getName() const{
    return name;
}

void MultiSourceData::setSources(std::vector<SourceData> n_sources){
    sources = n_sources;
}

std::vector<SourceData> MultiSourceData::getSources() const{
    return sources;
}


YAML::Emitter& operator << (YAML::Emitter &emitter, const MultiSourceData &msd){
    emitter << YAML::BeginMap;
    emitter << YAML::Key << "name" << YAML::Value << msd.getName();
    emitter << YAML::Key << "sources" << YAML::Value << msd.getSources();
    emitter << YAML::EndMap;
    return emitter;
}

std::ostream& operator << (std::ostream &stream, const MultiSourceData &msd){
    stream << "[ ";
    stream << "name: " << msd.getName() << ", ";
    stream << "sources: " << msd.getSources() << "";
    stream << " ]";
    return stream;
}

void operator >> (const YAML::Node& node, MultiSourceData &msd) {
    node["name"] >> msd.name;
    node["sources"] >> msd.sources;
}
