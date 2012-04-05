#ifndef MODELDATA_H
#define MODELDATA_H

#include "tool.h"

#include <string>
#include <vector>
#include <yaml-cpp/yaml.h>
#include <yaml-cpp/emitter.h>
#include <yaml-cpp/node.h>
#include <yaml-cpp/stlemitter.h>
#include <yaml-cpp/stlnode.h>
#include <iostream>

/**
 * @brief Klasa przechowujaca parametru obiektu
 *
 */
class ModelData
{

 private:
    std::vector<double> B;  /**< Wielomian B */
    std::vector<double> A;  /**< Wielomian A */
    int k;                  /**< Parametr k */
    int t;                  /**< Czas przelaczenia parametrow(nie stacjonarnosc) */

 public:
    /**
     * @brief Konstruktor
     *
     */
    ModelData();

    /**
     * @brief Konstruktor
     *
     */
    ModelData(std::vector<double>, std::vector<double>, int, int n_t=0);
    /**
     * @brief Destruktor;
     *
     */
    ~ModelData();

    void setB(std::vector<double>);
    std::vector<double> getB() const;
    void setA(std::vector<double>);
    std::vector<double> getA() const;
    void setK(int);
    int getK() const;
    void setT(int);
    int getT() const;

    friend void operator >> (const YAML::Node& node, ModelData &md);
};

YAML::Emitter& operator << (YAML::Emitter &emitter, const ModelData &md);
std::ostream& operator << (std::ostream &stream, const ModelData &md);
void operator >> (const YAML::Node& node, ModelData &md);

#endif // MODELDATA_H
