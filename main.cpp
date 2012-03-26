#include <QtGui/QApplication>
#include <iostream>
#include <stdlib.h>
#include <QLabel>
#include <QTimer>
#include "mainwindow.h"
#include "discreteobject.h"
#include "yamlconfigparser.h"

using namespace std;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow window;

    window.show();

    return a.exec();
}
