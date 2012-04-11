#ifndef OBJECTDATA_H
#define OBJECTDATA_H

#include "modeldata.h"
#include "tool.h"

#include <vector>
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/emitter.h>
#include <yaml-cpp/stlemitter.h>

/**
 * @brief Klasa przechowujaca zbior parametrow obiektu i jego nazwe
 *(zbior poniewaz jesli obiekt jest niestacjonarny to moze miec np. kilka wielomianow A oraz B)
 */
class ObjectData
{
public:

    /**
     * @brief Konstruktor
     *
     */
    ObjectData();
    /**
     * @brief Konstruktor
     *
     * @param std::string nazwa obiektu dyskretnego
     * @param std::vector<ModelData> Vector obiektow ModelData
     */
    ObjectData(std::string, std::vector<ModelData>);
    /**
     * @brief Destruktor
     *
     */
    ~ObjectData();

private:
    std::vector<ModelData> models; /**< Vector obiektow ModelData(parametrow obiektu) */
    std::string name; /**< Nazwa obiektu */

public:
    /**
     * @brief funkcja ustawia nazwę obiektu
     *
     * @param std::string nazwa obiektu
     */
    void setName(std::string);
    /**
     * @brief funkcja zwraca nazwę obiektu
     *
     */
    std::string getName() const;
    /**
     * @brief funkcja ustawia modele obiektu
     *
     * @param std::vector<ModelData> modele obiektu
     */
    void setModels(std::vector<ModelData>);
    /**
     * @brief funkcja zwraca modele obiektu
     *
     */
    std::vector<ModelData> getModels() const;

    /**
     * @brief funkcja dodająca model do zbioru modeli
     *
     * @param ModelData model obiektu
     */
    void addModel(ModelData);

    /**
     * @brief deklaracja przyjaźni dla operatora strumienia
     *
     * @param node format parsera yaml
     * @param od obiekt do którego sa zapisywane dane
     */
    friend void operator >> (const YAML::Node& node, ObjectData &od);
};

/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z obiektu ObjectData do formatu parsera yaml
 *
 * @param emitter format parsera yaml
 * @param od obiekt z którego dane sa zapisywane
 */
YAML::Emitter& operator << (YAML::Emitter &emitter, const ObjectData &od);
/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z obiektu ObjectData do strumienia std::ostream
 *
 * @param stream obiekt std::ostream
 * @param od obiekt z którego dane sa zapisywane
 */
std::ostream& operator << (std::ostream &stream, const ObjectData &od);
/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z formatu parsera yaml do obiektu ObjectData
 *
 * @param node format parsera yaml
 * @param od obiekt do którego sa zapisywane dane
 */
void operator >> (const YAML::Node& node, ObjectData &od);

#endif // OBJECTDATA_H
