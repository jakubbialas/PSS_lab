#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../object/discreteobject.h"
#include <string>
#include <map>
#include "simulation/source/source.h"

/**
 * @brief Klasa podstawowa Regulatora, dziedziczy po klasie obiektu dyskretnego
 *
 */
class Controller : public DiscreteObject
{
public:

    /**
     * @brief Konstruktor
     *
     */
    Controller();

    /**
     * @brief virtualna funkcja ustawiająca wybrany parametr regulatora
     *
     * @param std::string nazwa parametru
     * @param double wartość parametru
     */
    virtual void setParameter(std::string, double)=0;

    Source *source;

    void setSource(Source*);
    double getSP();
    void reset();

};
#endif // CONTROLLER_H
