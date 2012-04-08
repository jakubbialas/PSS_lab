#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include "tool.h"

#include "controller/controllerdata.h"
#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "object/nonstationarydiscreteobject.h"
#include "controller/controllerp.h"
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

public slots:
    void newConfig();
    void openConfig(std::string);
    void saveConfig(std::string);

    void getObjectsList();
    void getObjectData(std::string);
    void editObjectData(std::string, ObjectData);
    void setActiveObject(std::string);

    //TODO:
    void addSource(std::string);
    void setLastSourceParameter(std::string, double);
    void removeLastSource();
    void setControllerType(std::string);
    void setControllerParameter(std::string, double);

public:
    /**
     * @brief Sprawdza czy istnieje obiekt o zadaniej nazwie
     *
     * @param std::string
     */
    std::vector<std::string> getObjectsKeys();

private:
    std::map<std::string, ObjectData> objects; /**< Mapa zawierajaca obiekty wraz z ich nazwami */
    std::map<std::string, ControllerData> controllers;
    //std::map<std::string, MultiSourceData> sources;

    std::string filename;

    Controller *controller;
    NonStationaryDiscreteObject *object;
    MultiSource *source;
};

#endif // CONFIGURATION_H
