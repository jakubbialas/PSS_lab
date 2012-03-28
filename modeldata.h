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

    std::vector<double> B; /**< Wielomian B */
    std::vector<double> A; /**< Wielomian A */
    int k; /**< Parametr k */
    int t; /**< Czas przelaczenia parametrow(nie stacjonarnosc) */
};

#endif // MODELDATA_H
