#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plot1->addPen("input", new QwtSymbol( QwtSymbol::XCross, Qt::NoBrush, QPen( Qt::red ), QSize( 4, 4 ) ) );
    ui->plot1->addPen("output", new QwtSymbol( QwtSymbol::Ellipse, Qt::NoBrush, QPen( Qt::blue ), QSize( 3, 3 ) ) );

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
            ui->sourceTypeFrame->setEnabled(true);
            ui->simFrame->setEnabled(true);
            ui->getConfigBtn->setEnabled(true);
            ui->comboBoxObject->setEnabled(true);
            ui->resetBtn->setEnabled(true);
        }else{
            emit startSimulation();
            isSimulationStarted = true;
            ui->simBtn->setText("Pause simulation");
            ui->sourceTypeFrame->setEnabled(false);
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
    ui->plot1->resetPen("input");
    ui->plot1->resetPen("output");
}

void MainWindow::on_getConfigBtn_clicked()
{
    emit loadConfig("model.yaml");
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
    ui->samplingFrame->setEnabled(checked);
}

void MainWindow::on_stepSimRadio_toggled(bool checked)
{
    ui->stepFrame->setEnabled(checked);
    if(checked){

    }
}

void MainWindow::drawInput(double y){
    ui->plot1->drawPoint(y, "input");
}

void MainWindow::drawOutput(double y){
    ui->plot1->drawPoint(y, "output");
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

void MainWindow::on_stepSourceRadio_toggled(bool checked)
{
    if(checked){
        emit setSourceType(Source::STEP);
    }
}

void MainWindow::on_impSourceRadio_toggled(bool checked)
{
    if(checked){
        emit setSourceType(Source::IMP);
    }
}

void MainWindow::on_nonSourceRadio_toggled(bool checked)
{
    if(checked){
        emit setSourceType(Source::NONE);
    }
}

void MainWindow::on_manualSourceRadio_toggled(bool checked)
{
    ui->sourceValueFrame->setEnabled(ui->manualSourceRadio->isChecked());
    if(checked){
        emit setSourceType(Source::CUSTOM);
        emit setSourceValue(ui->sourceValueEdit->text().toDouble());
    }
}

void MainWindow::on_sourceValueEdit_textChanged(const QString &arg1)
{
    ui->sourceValueSilder->setValue(ui->sourceValueEdit->text().toDouble() * 10);
    emit setSourceValue(ui->sourceValueEdit->text().toDouble());
}

void MainWindow::on_sourceValueSilder_valueChanged(int value)
{
    double v2 = 0.1 * value;
    std::stringstream convert;
    convert << v2;
    ui->sourceValueEdit->setText((convert.str().c_str()));
}
