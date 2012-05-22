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
     * @brief Destruktor
     *
     */
    ~Controller();

    /**
     * @brief virtualna funkcja ustawiająca wybrany parametr regulatora
     *
     * @param std::string nazwa parametru
     * @param double wartość parametru
     */
    virtual void setParameter(std::string, double)=0;

    Source *source; /**< TODO */

    /**
     * @brief funkcja ustalajaca wymuszenie
     *
     * @param
     */
    void setSource(Source*);
    /**
     * @brief funkcja zwracajaca wartosc zadana
     *
     */
    double getSP();
    /**
     * @brief funkcja resetujaca regulator
     *
     */
    void reset();
    /**
     * @brief funkcja zwracajaca wymuszenie
     *
     */
    Source* getSource();

};
#endif // CONTROLLER_H
