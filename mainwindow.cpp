#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabelText(const QString str){
    ui->label->setText(str);
}

void MainWindow::setPlotData(double *x, double *y){
    /*long c = ui->qwtPlot->insertCurve("Trans Z");
    ui->qwtPlot->setCurveData(c,x,y);
    ui->qwtPlot->replot();*/
}
