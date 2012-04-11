#ifndef SINUSSOURCE_H
#define SINUSSOURCE_H

#include "source.h"
#include "math.h"

/**
 * @brief Klasa Źródła sinus o zadanej amplitudzie i czestotliwości
 *
 */
class SinusSource : public Source
{
public:
    double amplitude; /**< amplituda sinusa */
    double frequency; /**< czestotliwosc sinusa */

public:
    /**
     * @brief Konstruktor
     *
     */
    SinusSource();

    /**
     * @brief funkcja ustawiająca parametr źródła
     *
     * @param std::string nazwa parametru (możliwe wartości: "amlplitude", "frequency");
     * @param double wartosc paramatru
     */
    void setParameter(std::string, double);

    /**
     * @brief funkcja zwraca sygnał wyjsciowy
     *
     */
    double getSample();
};

#endif // SINUSSOURCE_H
