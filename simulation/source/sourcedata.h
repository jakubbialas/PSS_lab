#ifndef SOURCEDATA_H
#define SOURCEDATA_H

#include <string>
#include <map>
#include "tool.h"
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/emitter.h>
#include <yaml-cpp/stlemitter.h>
#include <yaml-cpp/stlnode.h>

/**
 * @brief Klasa SourceData zawiera dane potrzebne do utworzenia źródła podstawowego (sinus, step, impuls itd...)
 *
 */
class SourceData
{
public:
    /**
     * @brief Konstruktor
     *
     */
    SourceData();

    /**
     * @brief Konstruktor
     *
     * @param std::string typ źródła
     * @param std::map<std::string, double> mapa parametrów źródła
     */
    SourceData(std::string, std::map<std::string, double>);

    /**
     * @brief funkcja ustawiajaca typ źródła
     *
     * @param std::string
     */
    void setType(std::string);
    /**
     * @brief funkcja zwracająca typ źródła
     *
     */
    std::string getType() const;
    /**
     * @brief funkcja ustawiająca parametry źródła
     *
     * @param std::map<std::string, double>
     */
    void setParameters(std::map<std::string, double>);
    /**
     * @brief funkcja zwracająca parametry źródła
     *
     */
    std::map<std::string, double> getParameters() const;

private:
    std::string type; /**< typ źródła */
    std::map<std::string, double> parameters; /**< parametry źródła */

    /**
     * @brief deklaracja przyjaźni dla operatora strumienia
     *
     * @param node format parsera yaml
     * @param ad obiekt do którego sa zapisywane dane
     */
    friend void operator >> (const YAML::Node& node, SourceData &sd);
};

/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z obiektu SourceData do formatu parsera yaml
 *
 * @param emitter format parsera yaml
 * @param ad obiekt z którego dane sa zapisywane
 */
YAML::Emitter& operator << (YAML::Emitter &emitter, const SourceData &sd);
/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z obiektu SourceData do strumienia std::ostream
 *
 * @param stream obiekt std::ostream
 * @param ad obiekt z którego dane sa zapisywane
 */
std::ostream& operator << (std::ostream &stream, const SourceData &sd);
/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z formatu parsera yaml do obiektu SourceData
 *
 * @param node format parsera yaml
 * @param ad obiekt do którego sa zapisywane dane
 */
void operator >> (const YAML::Node& node, SourceData &sd);

#endif // SOURCEDATA_H
