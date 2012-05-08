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

class ControllerGPC : public Controller
{
public:
    ControllerGPC();
    ControllerGPC(int, int, double, double);

    void setParameter(std::string, double);
    double simulate(double);

    void reset();

private:
    ARXIdentification arx;

    int H;
    int L;
    double a;
    double p;

    int dB;
    int dA;
    int k;
    double l;
};

#endif // CONTROLLERGPC_H
