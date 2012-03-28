#include "discreteobject.h"

DiscreteObject::DiscreteObject(){
    counter = 0;
}

DiscreteObject::DiscreteObject(ObjectData n_data){
    data = n_data;
    ModelData model = data.models.at(0);
    B = model.B;
    A = model.A;
    k = model.k;
    counter = 0;
}

DiscreteObject::DiscreteObject(vector<double> n_B, vector<double> n_A, int n_k){
    B = n_B;
    A = n_A;
    k = n_k;
    counter = 0;

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
        double out = 0;

        updateModel();

        U.push_front(input);

        for(int i=1; i<A.size(); i++){
            if(Y.size() > i-1 ){
                out -= Y[i-1]*A[i];
            }else{
                //wstawiamy wartosc poczatkowa y(t=0-) = 0;
            }
        }
        for(int i=0; i<B.size(); i++){
            if(U.size() > i+k ){
                out += U[i+k]*B[i];
            }else{
                //wstawiamy wartosc poczatkowa u(t=0-) = 0;
            }
        }
        //out += e; TODO: e = random ale z jakiego przedziału ??

        out /= A[0]; //dzielimy y przez A[0] gdyby bylo rozne od 1

        Y.push_front(out);

        //usowanie ostatnich nieptrzebnych probek:
        //metoda prob i bledów wyszlo ze tyle probek potrzeba
        //mozna ustawic ich wiecej jezeli uklad ma byc niestacjonarny i moze zwiekszyc się jego rząd
        if(Y.size() > A.size()-1){
            Y.pop_back();
        }
        if(U.size() > B.size()+k-1){
            U.pop_back();
        }

        counter++;

        return out;
}
