#include "discreteobject.h"

DiscreteObject::DiscreteObject(){
    counter = 0;
    std::srand ( time(NULL) );
}

DiscreteObject::~DiscreteObject(){
}

DiscreteObject::DiscreteObject(std::vector<double> n_B, std::vector<double> n_A, int n_k){
    B = n_B;
    A = n_A;
    k = n_k;
    DiscreteObject();
}

DiscreteObject::DiscreteObject(ModelData md){
    DiscreteObject(md.getB(), md.getA(), md.getK());
}

void DiscreteObject::setModel(ModelData md){
    setBAk(md.getB(), md.getA(), md.getK());
}

ModelData DiscreteObject::getModel(){
    return ModelData(B, A, k);
}

void DiscreteObject::setBAk(std::vector<double> n_B, std::vector<double> n_A, int n_k){
    B = n_B;
    A = n_A;
    k = n_k;
}

std::vector<double> DiscreteObject::getB(){
    return B;
}

std::vector<double> DiscreteObject::getA(){
    return A;
}

int DiscreteObject::getk(){
    return k;
}

void DiscreteObject::reset(){
    counter = 0;
    U.clear();
    Y.clear();
}

double DiscreteObject::simulate(double input){
    double out;

    U.push_front(input);

    if(Y.size() >= A.size()-1){
        out = -std::inner_product(A.begin() + 1, A.end(), Y.begin(), 0.0);
    }else{
        out = -std::inner_product(Y.begin(), Y.end(), A.begin() + 1, 0.0);
    }

    if(U.size()+k >= B.size()){
        out = std::inner_product(B.begin(), B.end(), U.begin()+k, out);
    }else{
        out = std::inner_product(U.begin()+k, U.end(), B.begin(), out);
    }

    int r = std::rand();
    double e = r%32767; //0-32767
    e = (e/32767)*2 - 1; //(-1) - 1
    e = e*0.005*out; //+-5 promili outa;
    out += e;

    out /= A[0]; //dzielimy y przez A[0] gdyby bylo rozne od 1

    Y.push_front(out);

    if(Y.size() > A.size()-1){
        Y.pop_back();
    }
    if(U.size() > B.size()+k-1){
        U.pop_back();
    }

    counter++;

    return out;
}


double DiscreteObject::getLastValue(){
    return Y[0];
}
