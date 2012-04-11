#ifndef NOISESOURCE_H
#define NOISESOURCE_H

#include "source.h"
#include <cstdlib>

/**
 * @brief Klasa Źródła szumu odpowiedzią jest szum z przedziału (-amplitude, +amplitude)
 *
 */
class NoiseSource : public Source
{
private:
    double amplitude; /**< amplituda szumu */

public:
    /**
     * @brief Konstruktor
     *
     */
    NoiseSource();

    /**
     * @brief funkcja ustawiająca parametr źródła
     *
     * @param std::string nazwa parametru (możliwe wartości: "amlplitude"
     * @param double wartosc paramatru
     */
    void setParameter(std::string, double);

    /**
     * @brief funkcja zwraca sygnał wyjsciowy
     *
     */
    double getSample();
};

#endif // NOISESOURCE_H
