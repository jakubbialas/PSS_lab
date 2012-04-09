#ifndef CONTROLLERDATA_H
#define CONTROLLERDATA_H

#include "adjustmentdata.h"

class ControllerData
{
public:
    ControllerData();
    ControllerData(std::string, std::vector<AdjustmentData>);
    ~ControllerData();

    void setType(std::string);
    std::string getType() const;
    void setAdjustment(std::vector<AdjustmentData>);
    std::vector<AdjustmentData> getAdjustments() const;

    std::vector<std::string> getAdjustmentsNames();

    void removeAdjustment(std::string);
    void addAdjustment(AdjustmentData);
private:
    std::string type;
    std::vector<AdjustmentData> adjustments;

    friend void operator >> (const YAML::Node& node, ControllerData &cd);
};

YAML::Emitter& operator << (YAML::Emitter &emitter, const ControllerData &cd);
std::ostream& operator << (std::ostream &stream, const ControllerData &cd);
void operator >> (const YAML::Node& node, ControllerData &cd);

#endif // CONTROLLERDATA_H
