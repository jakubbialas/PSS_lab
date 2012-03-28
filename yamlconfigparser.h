#ifndef YAMLMODELPARSER_H
#define YAMLMODELPARSER_H

#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "objectdata.h"
#include "modeldata.h"

class YamlConfigParser
{
public:
    YamlConfigParser();

    void parseFile(const char * filename);

    ObjectData getObject(std::string);
    std::vector<std::string> getKeys();
    bool hasKey(std::string);

private:
    std::map<std::string, ObjectData> objects;
};

#endif // YAMLMODELPARSER_H
