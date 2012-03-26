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

    window.show();

    vector<double> B(2) ; //wielomian B
    vector<double> A(3) ; //wielomian A

    int k = 0; //opoznienie
    double D; //D = e^(-h/T)

    //calka:
/*
    B[0] = 1;
    A[0] = 1;
    A[1] = -1;
    k=1;
//*/
    //inercja:

/*    D = 0.95; //D = e^(-h/T)
    B[0] = D;
    A[0] = 1;
    A[1] = -D;
    k=1;
//*/
    //inercja z calka:

    D = 0.95; //D = e^(-h/T)
    B[0] = 1-D;
    A[0] = 1;
    A[1] = -1-D;
    A[2] = D;
    k = 1;
//*/

    DiscreteObject obiekt = DiscreteObject(B, A, k);
    double y;

    //sprawdzone dla tych przypadkow co my na TS robili na 1 zajeciach
    for(int i = 0; i < 50; i++){
        if(i==0){
            y = obiekt.Symuluj(1); //impuls w 1
        }else{
            y = obiekt.Symuluj(0); //potem 0
        }
       // window.setPlot1aData(i, y);
        //window.setPlot1bData(i, 0);
    }

    return a.exec();
}
