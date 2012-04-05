#ifndef YAMLMODELPARSER_H
#define YAMLMODELPARSER_H

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
class Configuration
{
public:


    /**
     * @brief Konstruktor
     *
     */
    Configuration();
    /**
     * @brief Destruktor
     *
     */
    ~Configuration();

    /**
     * @brief  Wczytuje plik Yaml
     *
     * @param filename Sciezka do pliku
     */
    void parseFile(const char * filename);
    void yamlEmitter(std::string name, int t, std::vector<double> A, std::vector<double> B, int k );
    /**
     * @brief Zwraca obiekt o podanej nazwie
     *
     * @param std::string Nazwa obiektu
     */
    ObjectData getObject(std::string);
    /**
     * @brief Zwraca wektor z nazwami obiektów
     *
     */
    std::vector<std::string> getKeys();
    /**
     * @brief Sprawdza czy istnieje obiekt o zadaniej nazwie
     *
     * @param std::string
     */
    bool hasKey(std::string);

    void saveFile(const char *filename);

private:
    std::map<std::string, ObjectData> objects; /**< Mapa zawierajaca obiekty wraz z ich nazwami */
    void saveKey(YAML::Emitter *emitter, int t, std::vector<double> A, std::vector<double> B, int k);

};

#endif // YAMLMODELPARSER_H
