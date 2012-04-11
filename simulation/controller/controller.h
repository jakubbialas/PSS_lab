#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../object/discreteobject.h"
#include <string>
#include <map>

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

};
#endif // CONTROLLER_H
