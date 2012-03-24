#include <QtGui/QApplication>
#include "mainwindow.h"
#include <iostream>
#include <stdlib.h>
#include <QLabel>
#include <discreteobject.h>

using namespace std;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;// = new MainWindow();

    vector<double> A(3) ; //wielomian A
    vector<double> B(1) ; //wielomian B

    A[0] =1;
    A[1] =-0.5;
    A[2] = -1;

    B[0] = 1;

    DiscreteObject *obiekt = new DiscreteObject(A, B);

    //Sprawdziłem dla kilku przypadków i śmiga;
    //Wymuszeniem jest aktulanie skok
    for(int i = 0; i < 10; i++){
        obiekt->Symuluj();
    }


/*
    cout << "Wchodze || Ap.size = " << Ap.size() << " || B.size = " << B.size() << endl;

    multi = 1/Ap[0];
    cout << "Multi : "<<multi << endl;

    for(int i = 0; i < Ap.size(); i++){
        Ap[i] = Ap[i]*(-multi);
        Y[i] = 0;
    }

    for(int i = 0; i < 10; i++){
        Y[i] = 0;
        cout << "Y["<<i<<"] = ";

        for(int j = 1; j < Ap.size(); j++){
            if(i-j >= 0){
                cout<<"(if)" ;
                Y[i] += Ap[j]*Y[i-j];
                cout << Ap[j] << " * " << Y[i-j];
            }else{
                cout << "(else)";
                Y[i] += Ap[j]*0;
                cout << Ap[j] << " * 0";
            }

        }

        for(int j = 0; j < B.size(); j++){
            Y[i] += B[j]*U;
            cout << " + " << B[j] << " * " << U << endl;

        }
        cout << "Y["<<i <<"]= " << Y[i] << endl;
    }
*/


    return a.exec();
}
