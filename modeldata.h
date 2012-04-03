#ifndef MODELDATA_H
#define MODELDATA_H

#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>
#include <iostream>
#include <fstream>

/**
 * @brief Klasa przechowujaca parametru obiektu
 *
 */
class ModelData
{
public:
    /**
     * @brief Konstruktor
     *
     */
    ModelData();

    std::vector<double> B; /**< Wielomian B */
    std::vector<double> A; /**< Wielomian A */
    int k; /**< Parametr k */
    int t; /**< Czas przelaczenia parametrow(nie stacjonarnosc) */

    friend void operator<<(std::ofstream &stream, ModelData &md);
    void saveKey(YAML::Emitter * emitter, int t, std::vector<double> A, std::vector<double> B, int k);
private:

};

#endif // MODELDATA_H
