#ifndef ARXIDENTIFICATION_H
#define ARXIDENTIFICATION_H

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <simulation/object/modeldata.h>
#include <vector>
#include <deque>
#include <numeric>
#include <algorithm>

/**
 * @brief Klasa słurząca do identyfikacji obiektu ARX
 *
 */
class ARXIdentification
{
public:
/**
 * @brief konstruktor domyślny
 *
 */
    ARXIdentification();
/**
 * @brief konstruktor
 *
 * @param n_dB
 * @param n_dA
 * @param n_k
 * @param n_l
 */
    ARXIdentification(int n_dB, int n_dA, int n_k, double n_l);
    /**
     * @brief kolejny krok identyfikacji
     *
     * @param in sygnal wchodzacy do identyfikowanego obiektu
     * @param out sygnal wychodzący z identyfikowanego obiektu
     */
    ModelData identify(double in, double out);

    /**
     * @brief funkcja zwraca bierzący wyznaczony model obiektu
     *
     */
    ModelData getModel();
    /**
     * @brief funkcja ustawia model obiektu
     *
     * @param ModelData
     */
    void setModel(ModelData);
    /**
     * @brief funkcja zwraca parametr lambda
     *
     */
    double getLambda();
    /**
     * @brief funkcja ustawia parametr lambda
     *
     * @param double
     */
    void setLambda(double);

private:
    int dB; /**< stopien wielomianu B */
    int dA; /**< stopien wielomianu A */
    double lambda; /**< wspólczynnik wazenia */

    ModelData md; /**< model obiektu */

    boost::numeric::ublas::matrix<double> covarMatrix; /**< macierz kowariancji */

    std::deque<double> inQueue; /**< wartosci wejsciowe */
    std::deque<double> outQueue; /**< wartosci wyjsciowe */
};

#endif // ARXIDENTIFICATION_H
