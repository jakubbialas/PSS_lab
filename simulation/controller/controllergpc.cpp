#include "controllergpc.h"

ControllerGPC::ControllerGPC()
{
    k = 0;
    dB = 0;
    dA = 0;
    l = 1;
    arx = ARXIdentification(0, 1, 2, 0.95);
}

ControllerGPC::ControllerGPC(int n_H, int n_L, double n_a, double n_p){
    H = n_H;
    L = n_L;
    a = n_a;
    p = n_p;
    k = 0;
    dB = 0;
    dA = 0;
    l = 1;
}

void ControllerGPC::setParameter(std::string name, double value){
    if(name.compare("H") == 0){
        H = value;
    }else if(name.compare("L") == 0){
        L = value;
    }else if(name.compare("a") == 0){
        a = value;
    }else if(name.compare("p") == 0){
        p = value;
    }else if(name.compare("dB") == 0){
        dB = value;
        arx = ARXIdentification(dB, dA, k, l);
    }else if(name.compare("dA") == 0){
        dA = value;
        arx = ARXIdentification(dB, dA, k, l);
    }else if(name.compare("k") == 0){
        k = value;
        arx = ARXIdentification(dB, dA, k, l);
    }else if(name.compare("l") == 0){
        l = value;
        arx = ARXIdentification(dB, dA, k, l);
    }else{
        throw "Undefined parameter " + name + ".";
    }
}

double ControllerGPC::simulate(double y){
    double u = 0;
    double w = source->getNextSample();

    U.push_front(y);

    ModelData md = arx.identify(Y.front(), y);
/*
    std::vector<double> Bb = md.getB();
    std::vector<double> Ab = md.getA();
    Ab[0] = 1;
    Ab[1] = -0.95;
    Bb[0] = 0.05;
    md.setA(Ab);
    md.setB(Bb);*/

    std::cout << "md: " << md << "\n";

    DiscreteObject obj;
    obj.setBAk(md.getB(), md.getA(), 0);
    obj.setNoiseRatio(0);

    boost::numeric::ublas::matrix<double> h(H,1);
    for(int i=0; i<H; i++){
        h(i,0) = (obj.simulate(1));
    }

    boost::numeric::ublas::compressed_matrix<double, boost::numeric::ublas::column_major, 0,
            boost::numeric::ublas::unbounded_array<int>, boost::numeric::ublas::unbounded_array<double> > Q(H,L,12);

    //boost::numeric::ublas::matrix<double> Q(H,L);
    for(int i=0; i<H; i++){
        for(int j=0; j<L; j++){
            if(i-j<0){
                Q(i,j) = 0;
            }else{
                Q(i,j) = h(i-j,0);
            }
        }
    }

    boost::numeric::ublas::compressed_matrix<double, boost::numeric::ublas::column_major, 0,
            boost::numeric::ublas::unbounded_array<int>, boost::numeric::ublas::unbounded_array<double> > temp(L,L);

    //boost::numeric::ublas::matrix<double> temp(L,L);
    temp = prod(trans(Q), Q);
    temp = temp + boost::numeric::ublas::identity_matrix<double>(L)*p;

/*  //odwracanie macierzy: (niestabilne czasem po 200 probkach sie wykrzacza czasem po 1)
    boost::numeric::ublas::matrix<double> temp2(L,L);
    boost::numeric::ublas::permutation_matrix<> pm(temp.size1());
    lu_factorize(temp,pm);
    lu_substitute(temp,pm,temp2);

    boost::numeric::ublas::matrix<double> qs(L,H);
    qs = prod(temp2, trans(Q));
    qs.resize(1,H);
    */

    //rozwiązywanie układu równań: (dziala dobrze)
    boost::numeric::ublas::vector<double> B (L), X (L);
    for(int i=0; i<L; i++){ B(i) = 1; X(i) = 0; }

    boost::numeric::bindings::umfpack::symbolic_type<double> Symbolic;
    boost::numeric::bindings::umfpack::numeric_type<double> Numeric;
    boost::numeric::bindings::umfpack::symbolic (temp, Symbolic);
    boost::numeric::bindings::umfpack::numeric (temp, Symbolic, Numeric);
    boost::numeric::bindings::umfpack::solve (temp, X, B, Numeric);

    boost::numeric::ublas::matrix<double> X2 (L, 1);
    for(int i=0; i<L; i++) X2(i,0) = X(i);
    boost::numeric::ublas::matrix<double> q(1,H);

    q = prod(trans(X2), trans(Q));

    boost::numeric::ublas::matrix<double> W0(H,1);
    boost::numeric::ublas::matrix<double> Y0(H,1);

    std::vector<double> wB;
    std::vector<double> wA;
    wB.push_back(1-a);
    wA.push_back(1);
    wA.push_back(-a);
    DiscreteObject obj3;
    obj3.setBAk(wB, wA, 0);
    obj3.setNoiseRatio(0);

    obj3.setU(Y);
    obj3.setY(U);

    DiscreteObject obj2;
    obj2.setBAk(md.getB(), md.getA(), 0);
    obj2.setNoiseRatio(0);

    obj2.setU(Y);
    obj2.setY(U);
    obj2.simulate(Y.front());

    for(int i=0; i<H; i++){
        W0(i,0) = obj3.simulate(w);
        Y0(i,0) = obj2.simulate(Y.front());
    }

    std::cout << "h: " << h << "\n";
    std::cout << "q: " << q << "\n";
    std::cout << "W0: " << W0 << "\n";
    std::cout << "Y0: " << Y0 << "\n";

    boost::numeric::ublas::matrix<double> temp4(1,1);
    temp4 = prod(q, W0-Y0);

    u = Y.front() + temp4(0,0);

    std::cout << "u: " << u << "\n";

    Y.push_front(u);

    return u;
}

void ControllerGPC::reset(){
    Controller::reset();

    arx = ARXIdentification(dB, dA, k, l);
}
