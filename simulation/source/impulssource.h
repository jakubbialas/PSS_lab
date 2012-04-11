#ifndef IMPULSSOURCE_H
#define IMPULSSOURCE_H

#include "source.h"

/**
 * @brief Klasa Źródła impulsowego odpowiedzią jest impuls o zadanej amplitudzie w chwili czasu t=0
 *
 */
class ImpulsSource : public Source
{
private:
    double amplitude; /**< amplituda impulsu */

public:
    /**
     * @brief Konstruktor
     *
     */
    ImpulsSource();

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

#endif // IMPULSSOURCE_H
