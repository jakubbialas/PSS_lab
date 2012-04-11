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

/**
 * @brief Klasa przechowująca nastawę regulatora o wybranym typie
 *
 */
class AdjustmentData
{
public:

    /**
     * @brief Konstruktor
     *
     */
    AdjustmentData();

    /**
     * @brief Konstruktor
     *
     * @param std::string typ regulatora
     * @param std::string nazwa nastawy
     * @param std::map<std::string, double> mapa z parametrami nastawy
     */
    AdjustmentData(std::string, std::string, std::map<std::string, double>);
    /**
     * @brief Destruktor
     *
     */
    ~AdjustmentData();

    /**
     * @brief funkcja ustawia nazwę nastawy
     *
     * @param std::string nazwa
     */
    void setName(std::string);
    /**
     * @brief funkcja zwraca nazwę nastawy
     *
     */
    std::string getName() const;
    /**
     * @brief funkcja ustawia typ regulatora dla ktorego jest ta nastawa
     *
     * @param std::string typ regulatora
     */
    void setType(std::string);
    /**
     * @brief funkcja zwraca typ regulatora
     *
     */
    std::string getType() const;
    /**
     * @brief funkcja ustawia parametry nastawy
     *
     * @param std::map<std::string, double> mapa z parametrami nastawy
     */
    void setParemeters(std::map<std::string, double>);
    /**
     * @brief funkcja zwraca parametry nastawy
     *
     */
    std::map<std::string, double> getParameters() const;

private:
    std::string type; /**< typ regulatora dla ktorego jest ta nastawa */
    std::string name; /**< nazwa nastawy */
    std::map<std::string, double> parameters; /**< mapa z parametrami nastawy */

    /**
     * @brief deklaracja przyjaźni dla operatora strumienia
     *
     * @param node format parsera yaml
     * @param ad obiekt do którego sa zapisywane dane
     */
    friend void operator >> (const YAML::Node& node, AdjustmentData &ad);
};

/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z obiektu AdjustmentData do formatu parsera yaml
 *
 * @param emitter format parsera yaml
 * @param ad obiekt z którego dane sa zapisywane
 */
YAML::Emitter& operator << (YAML::Emitter &emitter, const AdjustmentData &ad);
/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z obiektu AdjustmentData do strumienia std::ostream
 *
 * @param stream obiekt std::ostream
 * @param ad obiekt z którego dane sa zapisywane
 */
std::ostream& operator << (std::ostream &stream, const AdjustmentData &ad);
/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z formatu parsera yaml do obiektu AdjustmentData
 *
 * @param node format parsera yaml
 * @param ad obiekt do którego sa zapisywane dane
 */
void operator >> (const YAML::Node& node, AdjustmentData &ad);

#endif // ADJUSTMENTDATA_H
