#ifndef YAMLMODELPARSER_H
#define YAMLMODELPARSER_H

#include <QObject>
#include "object/tool.h"

#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
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
    void setObject(ObjectData);
    void setObjectsList(std::vector<std::string>);

public slots:
    void newConfig();
    void openConfig(std::string filename);
    void saveConfig(std::string filename);
    void setObject(std::string);

public:
    /**
     * @brief Sprawdza czy istnieje obiekt o zadaniej nazwie
     *
     * @param std::string
     */
    bool hasKey(std::string);
    std::vector<std::string> getKeys();

private:
    std::map<std::string, ObjectData> objects; /**< Mapa zawierajaca obiekty wraz z ich nazwami */
    //std::map<std::string, ControllerData> controllers;

    std::string filename;

};

#endif // YAMLMODELPARSER_H
