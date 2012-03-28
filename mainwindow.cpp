#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->coercePlot->addPen("input", new QwtSymbol( QwtSymbol::XCross, Qt::NoBrush, QPen( Qt::red ), QSize( 4, 4 ) ) );
    ui->coercePlot->addPen("output", new QwtSymbol( QwtSymbol::Ellipse, Qt::NoBrush, QPen( Qt::blue ), QSize( 3, 3 ) ) );

    isSimulationStarted = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_simBtn_clicked()
{
    if( ui->stepSimRadio->isChecked() ){
        int i = ui->stepNoEdit->text().toInt();
        emit stepSimulation( i );
    }else{
        if(isSimulationStarted){
            emit stopSimulation();
            isSimulationStarted = false;
            ui->simBtn->setText("Start simulation");
            ui->setCoercionFrame->setEnabled(true);
            ui->simFrame->setEnabled(true);
            ui->getConfigBtn->setEnabled(true);
            ui->comboBoxObject->setEnabled(true);
            ui->resetBtn->setEnabled(true);
        }else{
            emit startSimulation();
            isSimulationStarted = true;
            ui->simBtn->setText("Pause simulation");
            ui->setCoercionFrame->setEnabled(false);
            ui->simFrame->setEnabled(false);
            ui->getConfigBtn->setEnabled(false);
            ui->comboBoxObject->setEnabled(false);
            ui->resetBtn->setEnabled(false);
        }
    }
}

void MainWindow::on_resetBtn_clicked()
{
    emit resetSimulation();
    ui->coercePlot->resetPen("input");
    ui->coercePlot->resetPen("output");
}

void MainWindow::on_getConfigBtn_clicked()
{
    emit loadConfig("model.yaml");
}

void MainWindow::on_coerceSilder_valueChanged(int value)
{
    double v2 = 0.1 * value;
    std::stringstream convert;
    convert << v2;
    ui->coerceEdit->setText((convert.str().c_str()));
}

void MainWindow::on_coerceEdit_textChanged(const QString &arg1)
{
    ui->coerceSilder->setValue(ui->coerceEdit->text().toDouble() * 10);
    emit setCoercionValue(ui->coerceEdit->text().toDouble());
}


void MainWindow::on_samplingSlider_valueChanged(int value)
{
    std::stringstream convert;
    convert << value;
    ui->samplingLabel->setText((convert.str().c_str()));

    emit setSamplingTime(value);
}


void MainWindow::on_contSimRadio_toggled(bool checked)
{
    ui->samplingFrame->setEnabled(ui->contSimRadio->isChecked());
}

void MainWindow::on_stepSimRadio_toggled(bool checked)
{
    ui->stepFrame->setEnabled(ui->stepSimRadio->isChecked());
    if(checked){

    }
}

void MainWindow::on_stepCoerceRadio_toggled(bool checked)
{
    if(checked){
        emit setCoercionType(Coerce::STEP);
    }
}

void MainWindow::on_impCoerceRadio_toggled(bool checked)
{
    if(checked){
        emit setCoercionType(Coerce::IMP);
    }
}

void MainWindow::on_nonCoerceRadio_toggled(bool checked)
{
    if(checked){
        emit setCoercionType(Coerce::NONE);
    }
}

void MainWindow::on_manualCoerceRadio_toggled(bool checked)
{
    ui->coerceFrame->setEnabled(ui->manualCoerceRadio->isChecked());
    if(checked){
        emit setCoercionType(Coerce::CUSTOM);
        emit setCoercionValue(ui->coerceEdit->text().toDouble());
    }
}

void MainWindow::drawInput(double y){
    ui->coercePlot->drawPoint(y, "input");
}

void MainWindow::drawOutput(double y){
    ui->coercePlot->drawPoint(y, "output");
}

void MainWindow::drawError(double y){

}

void MainWindow::drawControl(double y){

}

void MainWindow::on_comboBoxObject_currentIndexChanged(const QString &arg1){
    setObject(arg1.toStdString());
}

void MainWindow::setObjectsList(std::vector<std::string> names){
    ui->comboBoxObject->clear();
    std::vector<std::string>::iterator it;
    for(it = names.begin(); it < names.end(); it++){
        ui->comboBoxObject->addItem(QString((*it).c_str()));
    }
}

