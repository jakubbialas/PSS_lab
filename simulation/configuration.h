#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include "tool.h"

#include "controller/adjustmentdata.h"
#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "object/nonstationarydiscreteobject.h"
#include "controller/controllerp.h"
#include "controller/controllerpid.h"
#include "source/multisource.h"
#include "object/objectdata.h"
#include "object/modeldata.h"
#include <string>


/**
 * @brief Klasa odpowiedzialna za wczytywanie plikow konfiguracyjnych w formacie Yaml
 *
 */
class Configuration : public QObject
{
    Q_OBJECT
public:
    explicit Configuration(QObject *parent = 0);
    /**
     * @brief Destruktor
     *
     */
    ~Configuration();

signals:
    void setObject(ObjectSISO*);
    void setController(ObjectSISO*);
    void setSource(Source*);

    void retObjectsList(std::vector<std::string>);
    void retObjectData(ObjectData);
    void retActiveObject(std::string);

    void retAdjustmentsList(std::vector<AdjustmentData>);
    void retActiveAdjustment(std::string, std::string);

public slots:
    void newConfig();
    void openConfig(std::string);
    void saveConfig(std::string);

    void getObjectsList();
    void getObjectData(std::string);
    void editObject(std::string, ObjectData);
    void removeObject(std::string);
    void setActiveObject(std::string);

    void getAdjustmentsList();
    void removeAdjustment(std::string, std::string);
    void saveAdjustment(AdjustmentData);
    void setActiveAdjustment(AdjustmentData);

    void setActiveSimpleSource(std::string, std::map<std::string, double>);

private:
    std::vector<std::string> getObjectsKeys();
    std::vector<AdjustmentData> getAdjustments();
    std::vector<AdjustmentData>::iterator findAdjustment(std::string, std::string);

private:
    std::map<std::string, ObjectData> objects; /**< Mapa zawierajaca obiekty wraz z ich nazwami */
    std::vector<AdjustmentData> adjustments;
    //std::map<std::string, MultiSourceData> sources;

    std::string filename;

    Controller *controller;
    std::string currentControllerType;
    NonStationaryDiscreteObject *object;
    Source *source;
};

#endif // CONFIGURATION_H
