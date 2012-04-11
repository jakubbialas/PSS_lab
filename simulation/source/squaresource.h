#ifndef SQUARESOURCE_H
#define SQUARESOURCE_H

#include "source.h"

/**
 * @brief
 *
 */
class SquareSource : public Source
{
private:
    double amplitude; /**< amplituda */
    double frequency; /**< częstotliwość */
    double dutycycle; /**< wypełnienie (0-100%) */

public:
    /**
     * @brief Konstruktor
     *
     */
    SquareSource();

    /**
     * @brief funkcja ustawiająca parametr źródła
     *
     * @param std::string nazwa parametru (możliwe wartości: "amlplitude", "frequency", "dutycycle");
     * @param double wartosc paramatru
     */
    void setParameter(std::string, double);

    /**
     * @brief funkcja zwraca sygnał wyjsciowy
     *
     */
    double getSample();
};

#endif // SQUARESOURCE_H
