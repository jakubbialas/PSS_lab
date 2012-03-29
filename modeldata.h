#ifndef MODELDATA_H
#define MODELDATA_H

#include <string>
#include <vector>

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

 private:
    std::vector<double> B;  /**< Wielomian B */
    std::vector<double> A;  /**< Wielomian A */
    int k;                  /**< Parametr k */
    int t;                  /**< Czas przelaczenia parametrow(nie stacjonarnosc) */

public:
    void setB(std::vector<double>);
    std::vector<double> getB();
    void setA(std::vector<double>);
    std::vector<double> getA();
    void setK(int);
    int getK();
    void setT(int);
    int getT();

};

#endif // MODELDATA_H
