#include "discreteobject.h"

DiscreteObject::DiscreteObject(){
    //A = null;
    //B = null;

}

double DiscreteObject::Symuluj(double input){
    return input;
}

DiscreteObject::DiscreteObject(vector<double> n_A, vector<double> n_B){
    A = n_A;
    B = n_B;

    //To trza by dać domyślnie ale coś mi lista inicjalizacyjna nie śmiga
    counter = 0;
    U.resize(1);
    U[0] = 1;

    Ap.resize(A.size());

    //ustaw wartości wielomianu pomocnicznego
    //ustaw wartości początkowe próbek na zero
    double multi = 1/A[0];
    for(int i = 0; i < Ap.size(); i++){
        Ap[i] = A[i]*(-multi);
        state.push_back(0);
    }

}

void DiscreteObject::setAB(vector<double> n_A, vector<double> n_B){
    A = n_A;
    B = n_B;
}

void DiscreteObject::setU(vector<double> n_U){
    U = n_U;
}

vector<double> DiscreteObject::getA(){
    return A;
}

vector<double> DiscreteObject::getB(){
    return B;
}

double DiscreteObject::Symuluj(){
        double Y = 0;

        cout << "state = ";

        for(int j = 1; j < Ap.size(); j++){
                Y += Ap[j]*state[Ap.size()-j];// Oblicz kolejną wartość Y
                cout << Ap[j] << " * " << state[Ap.size()-j];
        }


        int div = counter/U.size();
        double index = counter-div*U.size();

        for(int j = 0; j < B.size(); j++){
            if(counter > B.size()-1){
                Y += B[j]*U[index];
                cout << " + " << B[j] << " * " << U[index] << endl;
            }
            else{ Y += B[j]*0; } //Wykonaj gdy potrzebne jest wymuszenie sprzed chwili czasu równej zero
        }
        cout << "state= " << Y << endl;
        state.push_back(Y); //dodaj nową wartość do kolejki
        state.erase(state.begin()); //usuń nie potrzebną próbkę z kolejki
        counter++;
}
