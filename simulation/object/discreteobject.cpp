#include "discreteobject.h"


DiscreteObject::~DiscreteObject(){
}

DiscreteObject::DiscreteObject(std::vector<double> n_B, std::vector<double> n_A, unsigned int n_k, double n_noiseRatio = 0.0):
    B(n_B),
    A(n_A),
    k(n_k),
    noiseRatio(n_noiseRatio),
    counter(0)
{
    std::srand ( time(NULL) );
}

DiscreteObject::DiscreteObject(){
    DiscreteObject(std::vector<double>(0), std::vector<double>(0), 0);
}

DiscreteObject::DiscreteObject(ModelData md){
    DiscreteObject(md.getB(), md.getA(), md.getK(), md.getNoiseRatio());
}

void DiscreteObject::setModel(ModelData md){
    setParameters(md.getB(), md.getA(), md.getK(), md.getNoiseRatio());
}

ModelData DiscreteObject::getModel(){
    return ModelData(B, A, k, noiseRatio);
}

void DiscreteObject::setParameters(std::vector<double> n_B, std::vector<double> n_A, unsigned int n_k){
    B = n_B;
    A = n_A;
    k = n_k;
}

void DiscreteObject::setParameters(std::vector<double> n_B, std::vector<double> n_A, unsigned int n_k, double n_noiseRatio){
    DiscreteObject::setParameters(n_B, n_A, n_k);
    noiseRatio = n_noiseRatio;
}

std::vector<double> DiscreteObject::getB(){
    return B;
}

std::vector<double> DiscreteObject::getA(){
    return A;
}

unsigned int DiscreteObject::getk(){
    return k;
}

double DiscreteObject::getNoiseRatio(){
    return noiseRatio;
}

void DiscreteObject::reset(){
    counter = 0;
    U.clear();
    Y.clear();
}

double DiscreteObject::simulate(double input){
    if(B.size() == 0 || A.size() == 0){
        throw PSSDiscreteObjectParameterNotSetException();
    }

    double out = 0.0;

    U.push_front(input);

    if(Y.size() >= A.size()-1){
        out = - std::inner_product(A.begin() + 1, A.end(), Y.begin(), 0.0);
    }else{
        out = - std::inner_product(Y.begin(), Y.end(), A.begin() + 1, 0.0);
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
    double e = r%32767; //<0;-32767>
    e = ((e/32767)*2 - 1); //<-1;1>
    e = e*out*noiseRatio; //
    out += e;

    out /= A[0]; //dzielimy y przez A[0] gdyby bylo rozne od 1

    Y.push_front(out);

    //usuwamy niepotrzebną historię (pozostawiamy jednek lekki zapas)
    int b = 5;
    if(Y.size() > A.size()-1 + b){
        Y.pop_back();
    }
    if(U.size() > B.size()+k-1 + b){
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

void DiscreteObject::setNoiseRatio(double n_noiseRatio){
    noiseRatio = n_noiseRatio;
}

void DiscreteObject::setU(std::deque<double> n_U){
    U = n_U;
}

void DiscreteObject::setY(std::deque<double> n_Y){
    Y = n_Y;
}
