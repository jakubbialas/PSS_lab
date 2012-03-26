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

void MainWindow::setPlot1aData(double x, double y){
    ui->coercePlot->drawPoint(x, y, "red");
}
void MainWindow::setPlot1bData(double x, double y){
    ui->coercePlot->drawPoint(x, y, "blue");
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
    if(ui->stepSimRadio->isChecked()){
        int steps = ui->stepNoEdit->text().toInt();
        for(int i = 0; i <steps; i++){
           // ui->coercePlot->drawPoint(x, Object->Symuluj(), "red");
        }
    }
}
