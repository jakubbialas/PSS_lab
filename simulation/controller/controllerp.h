#ifndef CONTROLLERP_H
#define CONTROLLERP_H

#include "controller.h"

/**
 * @brief Klasa regulatora typu P dziedziczy po klasie Regulator
 *
 */
class ControllerP : public Controller
{
protected:
    double P; /**< parametr wzmocnienia regulatora */
public:
    /**
     * @brief Konstruktor
     *
     */
    ControllerP();
    /**
     * @brief Destruktor
     *
     */
    ~ControllerP();
    /**
     * @brief Konstruktor
     *
     * @param double wzmocnienie regulatora
     */
    ControllerP(double);

    /**
     * @brief funkcja ustawiająca parametr regulatora
     *
     * @param std::string nazwa parametru (dopuszczalne wartości: "P")
     * @param double wartość parametru
     */
    void setParameter(std::string, double);

    /**
     * @brief funkcja zwracająca wartość wyjściową regulatora na podstawie wartości wejściowej
     *
     * @param double wejście regulatora (uchyb)
     */
    double simulate(double);
};

#endif // CONTROLLERP_H
