#ifndef STEPSOURCE_H
#define STEPSOURCE_H

#include "source.h"

/**
 * @brief
 *
 */
class StepSource : public Source
{
private:
    double amplitude; /**< amplituda */

public:
    /**
     * @brief Konstruktor
     *
     */
    StepSource();

    /**
     * @brief funkcja ustawiająca parametr źródła
     *
     * @param std::string nazwa parametru (możliwe wartości: "amlplitude");
     * @param double wartosc paramatru
     */
    void setParameter(std::string, double);

    /**
     * @brief funkcja zwraca sygnał wyjsciowy
     *
     */
    double getSample();
};

#endif // STEPSOURCE_H
