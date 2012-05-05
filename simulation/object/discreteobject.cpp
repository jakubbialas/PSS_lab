#include "discreteobject.h"

DiscreteObject::DiscreteObject():noiseRatio(0.01), counter(0){
    std::srand ( time(NULL) );
}

DiscreteObject::~DiscreteObject(){
}

DiscreteObject::DiscreteObject(std::vector<double> n_B, std::vector<double> n_A, int n_k):noiseRatio(0.01){
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

    std::deque<double>::iterator it = U.begin();
    it += k;
    if(U.size() >= B.size()+k){
        out = std::inner_product(B.begin(), B.end(), it, out);
    }else if(U.size() > k){
        out = std::inner_product(it, U.end(), B.begin(), out);
    }else{
        //do nothing
    }

    int r = std::rand();
    double e = r%32767; //0-32767
    e = ((e/32767)*2 - 1); //(-1) - 1
    e = e*out*noiseRatio; //+-5 promili outa;
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
    if(Y.size() > 0){
        return Y[0];
    }else{
        return 0;
    }
}

void DiscreteObject::setNoiseRatio(double noise){
    noiseRatio = noise;
}
