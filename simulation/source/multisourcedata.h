#ifndef MULTISOURCEDATA_H
#define MULTISOURCEDATA_H

#include <vector>
#include <string>
#include "sourcedata.h"
#include "tool.h"
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/emitter.h>
#include <yaml-cpp/stlemitter.h>
#include <yaml-cpp/stlnode.h>

/**
 * @brief Klasa MultiSourceData zawiera dane dotyczace źródła składającego sie z kilku źródeł podstawowych
 * Źródło takie może być zapisane w pliku konfiguracji
 *
 */
class MultiSourceData
{
public:
    /**
     * @brief Konstruktor
     *
     */
    MultiSourceData();
    /**
     * @brief Konstruktor
     *
     * @param std::string nazwa źródła
     * @param std::vector<SourceData> wektor składowych źródeł podstawowych
     */
    MultiSourceData(std::string, std::vector<SourceData>);

    /**
     * @brief funkcja ustawia nazwe źródła
     *
     * @param std::string
     */
    void setName(std::string);
    /**
     * @brief funkcja zwraca nazwę źródła
     *
     */
    std::string getName() const;
    /**
     * @brief funkcja ustawia wektor źródeł składowych
     *
     * @param std::vector<SourceData>
     */
    void setSources(std::vector<SourceData>);
    /**
     * @brief funkcja zwraca wektor źródeł składowych
     *
     */
    std::vector<SourceData> getSources() const;

private:
    std::string name; /**< nazwa źródła */
    std::vector<SourceData> sources; /**< vektor źródeł podstawowych */

    /**
     * @brief deklaracja przyjaźni dla operatora strumienia
     *
     * @param node format parsera yaml
     * @param msd obiekt do którego sa zapisywane dane
     */
    friend void operator >> (const YAML::Node& node, MultiSourceData &msd);
};

/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z obiektu MultiSourceData do formatu parsera yaml
 *
 * @param emitter format parsera yaml
 * @param msd obiekt z którego dane sa zapisywane
 */
YAML::Emitter& operator << (YAML::Emitter &emitter, const MultiSourceData &msd);
/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z obiektu MultiSourceData do strumienia std::ostream
 *
 * @param stream obiekt std::ostream
 * @param msd obiekt z którego dane sa zapisywane
 */
std::ostream& operator << (std::ostream &stream, const MultiSourceData &msd);
/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z formatu parsera yaml do obiektu MultiSourceData
 *
 * @param node format parsera yaml
 * @param msd obiekt do którego sa zapisywane dane
 */
void operator >> (const YAML::Node& node, MultiSourceData &msd);

#endif // MULTISOURCEDATA_H
