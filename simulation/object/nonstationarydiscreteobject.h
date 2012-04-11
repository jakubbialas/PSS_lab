#ifndef NONSTATIONARYDISCRETEOBJECT_H
#define NONSTATIONARYDISCRETEOBJECT_H

#include "discreteobject.h"
#include "objectdata.h"

/**
 * @brief Klasa implementująca niestacjonarność obiektu dyuskretnego
 *
 */
class NonStationaryDiscreteObject : public DiscreteObject
{
private:
    ObjectData data;  /**< dane niestacjonarnego obiektu dyskretnego */

    /**
     * @brief funkcja ustawiająca model obiektu dyskretnego w zależności od chwili czasu w której się znajduje
     *
     */
    void updateModel();

public:
    /**
     * @brief Konstruktor
     *
     */
    NonStationaryDiscreteObject();
    /**
     * @brief Destruktor
     *
     */
    ~NonStationaryDiscreteObject();
    /**
     * @brief Konstruktor
     *
     * @param ObjectData dane niestacjonarnego obiektu dyskretnego
     */
    NonStationaryDiscreteObject(ObjectData);

    /**
     * @brief funkcja ustawia dane niestacjonarnego obiektu dyskretnego
     *
     * @param ObjectData dane niestacjonarnego obiektu dyskretnego
     */
    void setData(ObjectData);

    /**
     * @brief funkcja resetuje obiekt
     *
     */
    void reset();
    /**
     * @brief funkcja odpowiedzialna za jeden krok symulacji
     *
     * @param double
     */
    double simulate(double);
};

#endif // NONSTATIONARYDISCRETEOBJECT_H
