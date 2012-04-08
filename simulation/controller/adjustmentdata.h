#ifndef ADJUSTMENTDATA_H
#define ADJUSTMENTDATA_H

#include "tool.h"

#include <string>
#include <map>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/emitter.h>
#include <yaml-cpp/stlemitter.h>
#include <yaml-cpp/stlnode.h>

class AdjustmentData
{
public:
    AdjustmentData();
    AdjustmentData(std::string, std::map<std::string, double>);
    ~AdjustmentData();

    void setName(std::string);
    std::string getName() const;
    void setParemeters(std::map<std::string, double>);
    std::map<std::string, double> getParameters() const;
private:
    std::string name;
    std::map<std::string, double> parameters;

    friend void operator >> (const YAML::Node& node, AdjustmentData &ad);
};

YAML::Emitter& operator << (YAML::Emitter &emitter, const AdjustmentData &ad);
std::ostream& operator << (std::ostream &stream, const AdjustmentData &ad);
void operator >> (const YAML::Node& node, AdjustmentData &ad);

#endif // ADJUSTMENTDATA_H
