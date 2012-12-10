#include "controllergpc.h"\

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
    if(source == NULL){
        throw PSSDiscreteObjectSorceNotDefinedException();
    }
    double u = 0;
    double w = source->getNextSample();

    U.push_front(y);

    //identyfi new model:
    ModelData md;
    if(Y.size()==0){
        md = arx.identify(0, y);
    }else{
        md = arx.identify(Y.front(), y);
    }

    //DiscreteObject obj;
    obj1.reset();
    obj1.setParameters(md.getB(), md.getA(), 0, 0);

    boost::numeric::ublas::matrix<double> h(H,1);
    for(int i=0; i<H; i++){
        h(i,0) = (obj1.simulate(1));
    }

//    Q = boost::numeric::ublas::compressed_matrix<double, boost::numeric::ublas::column_major, 0,
//            boost::numeric::ublas::unbounded_array<int>, boost::numeric::ublas::unbounded_array<double> >(H,L,12);

    boost::numeric::ublas::matrix<double> Q(H,L);

    for(int i=0; i<H; i++){
        for(int j=0; j<L; j++){
            if(i-j<0){
                Q(i,j) = 0;
            }else{
                Q(i,j) = h(i-j,0);
            }
        }
    }

       //odwracanie macierzy: moze byc niestabilne, dziala w matlabie
            boost::numeric::ublas::matrix<double> otemp(L,L);

            otemp = prod(trans(Q), Q);
            otemp = otemp + boost::numeric::ublas::identity_matrix<double>(L)*p;
            //otemp = trans(otemp);

            boost::numeric::ublas::matrix<double> otemp2(L,L);
            otemp2.assign(boost::numeric::ublas::identity_matrix<double>(L));
            boost::numeric::ublas::permutation_matrix<> pm(L);
            lu_factorize(otemp,pm);
            lu_substitute(otemp,pm,otemp2);


            boost::numeric::ublas::matrix<double> q(1,H);
            boost::numeric::ublas::matrix<double> otemp3(1,L,1);

            boost::numeric::ublas::matrix<double> otemp4(L,1);
            otemp4 = prod(otemp3, otemp2);

            q = prod(otemp4, trans(Q));
        //koniec odwracania macierzy


          //rozwiązywanie układu równań: (dziala dobrze) - nie dziala w matlabie.....
    /*        boost::numeric::ublas::compressed_matrix<double, boost::numeric::ublas::column_major, 0,
                    boost::numeric::ublas::unbounded_array<int>, boost::numeric::ublas::unbounded_array<double> > temp(L,L);

            temp = prod(trans(Q), Q);
            temp = temp + boost::numeric::ublas::identity_matrix<double>(L)*p;

            B = boost::numeric::ublas::vector<double> (L);
            X = boost::numeric::ublas::vector<double> (L);
            for(int i=0; i<L; i++){ B(i) = 1; X(i) = 0; }

            //boost::numeric::bindings::umfpack::symbolic_type<double> Symbolic;
            //boost::numeric::bindings::umfpack::numeric_type<double> Numeric;
            boost::numeric::bindings::umfpack::symbolic (temp, Symbolic);
            boost::numeric::bindings::umfpack::numeric (temp, Symbolic, Numeric);
            boost::numeric::bindings::umfpack::solve (temp, X, B, Numeric);

            boost::numeric::bindings::umfpack::free(Symbolic);
            boost::numeric::bindings::umfpack::free(Numeric);

            boost::numeric::ublas::matrix<double> X2(L, 1);
            for(int i=0; i<L; i++) X2(i,0) = X(i);
            boost::numeric::ublas::matrix<double> q(1,H);

            q = prod(trans(X2), trans(Q));*/
          //koniec

    boost::numeric::ublas::matrix<double> W0(H,1);
    boost::numeric::ublas::matrix<double> Y0(H,1);

    std::vector<double> wB;
    std::vector<double> wA;
    wB.push_back(1-a);
    wA.push_back(1);
    wA.push_back(-a);
    //DiscreteObject obj3;
    obj3.reset();
    obj3.setParameters(wB, wA, 0, 0);
    obj3.setU(Y);
    obj3.setY(U);

    //DiscreteObject obj2;
    obj2.reset();
    obj2.setParameters(md.getB(), md.getA(), 0, 0);
    obj2.setU(Y);
    obj2.setY(U);

    if(Y.size() == 0){
        obj2.simulate(0);
    }else{
        obj2.simulate(Y.front());
    }

    obj3.simulate(w);

    for(int i=0; i<H; i++){
        W0(i,0) = obj3.simulate(w);
        if(Y.size() == 0){
            Y0(i,0) = obj2.simulate(0);
        }else{
            Y0(i,0) = obj2.simulate(Y.front());
        }
    }
    boost::numeric::ublas::matrix<double> temp4(1,1);
    temp4 = prod(q, W0-Y0);

    if(Y.size() == 0){
        u = temp4(0,0);
    }else{
        u = Y.front() + temp4(0,0);
    }
    Y.push_front(u);

    return u;
}

void ControllerGPC::reset(){
    Controller::reset();
    arx.reset();
    obj1.reset();
    obj2.reset();
    obj3.reset();
    obj2 = DiscreteObject();
}
