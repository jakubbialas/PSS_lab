#ifndef TRIANGLESOURCE_H
#define TRIANGLESOURCE_H

#include "source.h"

/**
 * @brief Klasa Źródła fali trójkątnej
 *
 */
class TriangleSource : public Source
{
private:
    double amplitude; /**< amplituda */
    double frequency; /**< częstotliwość */

public:
    /**
     * @brief Konstruktor
     *
     */
    TriangleSource();

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

#endif // TRIANGLESOURCE_H
