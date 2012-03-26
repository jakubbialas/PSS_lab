#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->coercePlot->addPen("red", new QwtSymbol( QwtSymbol::XCross, Qt::NoBrush, QPen( Qt::red ), QSize( 4, 4 ) ) );
    ui->coercePlot->addPen("blue", new QwtSymbol( QwtSymbol::Ellipse, Qt::NoBrush, QPen( Qt::blue ), QSize( 3, 3 ) ));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabelText(const QString str){
    ui->label->setText(str);
}

void MainWindow::setPlot1aData( double y){
    ui->coercePlot->drawPoint(y, "red");
}
void MainWindow::setPlot1bData( double y){
    ui->coercePlot->drawPoint(y, "blue");
}

void MainWindow::on_stepSimRadio_clicked()
{

}

void MainWindow::on_stepSimRadio_toggled(bool checked)
{
    ui->stepFrame->setEnabled(ui->stepSimRadio->isChecked());
}

void MainWindow::on_simBtn_clicked()
{
    if(&Object == NULL) return;

    double input = 0;

    if( ui->stepCoerceRadio->isChecked() ) coerce->setCoercionType(coerce->STEP);
    else if( ui->impCoerceRadio->isChecked() ) coerce->setCoercionType(coerce->IMP);
    else if( ui->nonCoercionRadio->isChecked() ) coerce->setCoercionType(coerce->NONE);
    else if( ui->manualCoerceRadio->isChecked() ){
        input = ui->coerceEdit->text().toInt();
        coerce->setCoercionType(coerce->CUSTOM);
    }else{
        QMessageBox msgBox;
        msgBox.setText("Choose coercion type!");
        msgBox.exec();
        return;
    }

    if( ui->stepSimRadio->isChecked() ){
        int steps = ui->stepNoEdit->text().toInt();
        double y;
        for(int i = 0; i <steps; i++){
           setPlot1aData(Object->Symuluj(  coerce->nextSample(input)));
        }
    }
}

void MainWindow::on_getConfigBtn_clicked()
{
    vector<double> B(2) ; //wielomian B
    vector<double> A(3) ; //wielomian A

    int k = 0; //opoznienie
    double D; //D = e^(-h/T)
    D = 0.95; //D = e^(-h/T)
    B[0] = 1-D;
    A[0] = 1;
    A[1] = -1-D;
    A[2] = D;
    k = 1;
//*/

    Object = new DiscreteObject(B, A, k);
    coerce = new Coerce();
    cout << "stworzono obiekt" << endl;
}

void MainWindow::on_manualCoerceRadio_toggled(bool checked)
{
    ui->coerceFrame->setEnabled(ui->manualCoerceRadio->isChecked());
}

void MainWindow::on_coerceEdit_textChanged(const QString &arg1)
{
    ui->coerceSilder->setValue(ui->coerceEdit->text().toDouble());
}

void MainWindow::on_coerceSilder_valueChanged(int value)
{
    std::stringstream convert;
    convert << ui->coerceSilder->value();
    ui->coerceEdit->setText((convert.str().c_str()));
}
