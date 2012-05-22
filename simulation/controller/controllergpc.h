#ifndef CONTROLLERGPC_H
#define CONTROLLERGPC_H

#include "simulation/controller/controller.h"
#include "simulation/identification/arxidentification.h"
#include "simulation/object/modeldata.h"
#include <boost/numeric/ublas/lu.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include <boost/numeric/bindings/traits/ublas_vector.hpp>
#include <boost/numeric/bindings/traits/ublas_sparse.hpp>
#include <boost/numeric/bindings/umfpack/umfpack.hpp>
#include <boost/numeric/ublas/io.hpp>

#include <umfpack.h>

/**
 * @brief Regulator GPC
 *
 */
class ControllerGPC : public Controller
{
public:
/**
 * @brief Konstruktor
 *
 */
    ControllerGPC();
/**
 * @brief Konstruktor
 *
 * @param int parametr H
 * @param int parametr L
 * @param double parametr a
 * @param double parametr p
 */
    ControllerGPC(int, int, double, double);

    /**
     * @brief Funkcja ustawiająca parametry regulatora
     *
     * @param std::string nazwa parametru
     * @param double nowa wartość
     */
    void setParameter(std::string, double);
    /**
     * @brief Symulacja regulatora
     *
     * @param double wyjscie z obiektu
     */
    double simulate(double);

    /**
     * @brief funkcja resetujaca regulator
     *
     */
    void reset();

private:
    ARXIdentification arx; /**< TODO */

    int H; /**< Horyzont predykcji */
    int L; /**< Horyzont sterowac */
    double a; /**< parametr alfa */
    double p; /**< parametr ro */

    int dB; /**< stopien wielomianu A (do identyfikacji ARX) */
    int dA; /**< stopien wielomianu B (do identyfikacji ARX) */
    int k; /**< opoznienie obiektu (do identyfikacji ARX) */
    double l; /**< wspolczynnik wazenia lambda (do identyfikacji ARX) */

    DiscreteObject obj1, obj2, obj3; /**< obiekty pomocnicze */

    boost::numeric::bindings::umfpack::symbolic_type<double> Symbolic;
    boost::numeric::bindings::umfpack::numeric_type<double> Numeric;

    boost::numeric::ublas::compressed_matrix<double, boost::numeric::ublas::column_major, 0,
            boost::numeric::ublas::unbounded_array<int>, boost::numeric::ublas::unbounded_array<double> > Q;
    boost::numeric::ublas::vector<double> B, X;
};

#endif // CONTROLLERGPC_H
