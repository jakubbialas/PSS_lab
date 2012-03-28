#include "discreteobject.h"

DiscreteObject::DiscreteObject(){
    counter = 0;
    std::srand ( time(NULL) );
}

DiscreteObject::DiscreteObject(ObjectData n_data){
    data = n_data;
    ModelData model = data.models.at(0);
    B = model.B;
    A = model.A;
    k = model.k;
    counter = 0;
    srand ( time(NULL) );
}

DiscreteObject::DiscreteObject(vector<double> n_B, vector<double> n_A, int n_k){
    B = n_B;
    A = n_A;
    k = n_k;
    counter = 0;
    srand ( time(NULL) );

    /* TODO:
    if(k < 0){
        //wyrzuc wyjatek
    }
    if(A.size() == 0){
        //wyrzuc wyjatek
    }
    if(B.size() == 0){
        //wyrzuc wyjatek
    }
    if(A[0] == 0){
        //wyrzuc wyjatek
    }*/
    //jesli A[0] != 1 ty dzielenie wykonujemy w funkcji symulacji, nie w konstruktorze...
}

void DiscreteObject::setBAk(vector<double> n_B, vector<double> n_A, int n_k){
    B = n_B;
    A = n_A;
    k = n_k;
}

void DiscreteObject::setData(ObjectData n_data){
    data = n_data;
    ModelData model = data.models.at(0);
    B = model.B;
    A = model.A;
    k = model.k;
    counter = 0;
}

vector<double> DiscreteObject::getA(){
    return A;
}

vector<double> DiscreteObject::getB(){
    return B;
}

int DiscreteObject::getk(){
    return k;
}

void DiscreteObject::updateModel(){
    if(data.models.size()>1){
         ModelData model;
         for(int i=0; i<data.models.size(); i++){
            model = data.models.at(i);
            if(model.t == counter){
                B = model.B;
                A = model.A;
                k = model.k;
             }
         }
     }
}

void DiscreteObject::reset(){
    counter = 0;
    U.clear();
    Y.clear();
    updateModel();
}

double DiscreteObject::Symuluj(double input){
    double out;

    updateModel();

    U.push_front(input);

    /*for(int i=1; i<A.size(); i++){
        if(Y.size() > i-1 ){
            out -= Y[i-1]*A[i];
        }else{
            //wstawiamy wartosc poczatkowa y(t=0-) = 0;
        }
    }*/
    if(Y.size() >= A.size()-1){
        out = -std::inner_product(A.begin() + 1, A.end(), Y.begin(), 0.0);
    }else{
        out = -std::inner_product(Y.begin(), Y.end(), A.begin() + 1, 0.0);
    }

    /*for(int i=0; i<B.size(); i++){
        if(U.size() > i+k ){
            out += U[i+k]*B[i];
        }else{
            //wstawiamy wartosc poczatkowa u(t=0-) = 0;
        }
    }*/
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
