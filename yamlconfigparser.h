#ifndef YAMLMODELPARSER_H
#define YAMLMODELPARSER_H

#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "objectdata.h"
#include "modeldata.h"

/**
 * @brief Klasa odpowiedzialna za wczytywanie plikow konfiguracyjnych w formacie Yaml
 *
 */
class YamlConfigParser
{
public:
/**
 * @brief Konstruktor
 *
 */
    YamlConfigParser();

    /**
     * @brief  Wczytuje plik Yaml
     *
     * @param filename Sciezka do pliku
     */
    void parseFile(const char * filename);

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

private:
    std::map<std::string, ObjectData> objects; /**< Mapa zawierajaca obiekty wraz z ich nazwami */
};

#endif // YAMLMODELPARSER_H
