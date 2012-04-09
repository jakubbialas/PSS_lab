#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->plot1->addPen("input", new QwtSymbol( QwtSymbol::XCross, Qt::NoBrush, QPen( Qt::red ), QSize( 4, 4 ) ) );
    ui->plot1->addPen("output", new QwtSymbol( QwtSymbol::Ellipse, Qt::NoBrush, QPen( Qt::blue ), QSize( 3, 3 ) ) );
    ui->plot2->addPen("error", new QwtSymbol( QwtSymbol::XCross, Qt::NoBrush, QPen( Qt::cyan ), QSize( 4, 4 ) ) );
    ui->plot2->addPen("control", new QwtSymbol( QwtSymbol::Ellipse, Qt::NoBrush, QPen( Qt::green ), QSize( 3, 3 ) ) );

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
        }else{
            emit startSimulation();
            isSimulationStarted = true;
            ui->simBtn->setText("Pause simulation");
        }
    }
}

void MainWindow::on_resetBtn_clicked()
{
    emit resetSimulation();
    ui->plot1->resetPen("input");
    ui->plot1->resetPen("output");
    ui->plot2->resetPen("error");
    ui->plot2->resetPen("control");
}


void MainWindow::drawInput(double y){
    ui->plot1->drawPoint(y, "input");
}

void MainWindow::drawOutput(double y){
    ui->plot1->drawPoint(y, "output");
}

void MainWindow::drawError(double y){
    ui->plot2->drawPoint(y, "error");
}

void MainWindow::drawControl(double y){
    ui->plot2->drawPoint(y, "control");
}

void MainWindow::retObjectsList(std::vector<std::string> names){
    //delete ui->listWidget_sources->item(i-1);
    ui->listWidget_Objects->clear();
    std::vector<std::string>::iterator it;
    for(it = names.begin(); it < names.end(); it++){
        ui->listWidget_Objects->addItem(QString((*it).c_str()));
    }
}

void MainWindow::retObjectData(ObjectData){
    //TODO
}

void MainWindow::retActiveObject(std::string){
    //TODO
}

void MainWindow::retAdjustmentsList(std::map<std::string, ControllerData> controllers){
    controllersData = controllers;
    updateAdjustmentsList();
}

void MainWindow::updateAdjustmentsList(){
    ui->listWidget_adjustments->clear();
    QString ctype = ui->comboBox_controllerType->currentText();
    if(controllersData.find(ctype.toStdString()) != controllersData.end()){
        std::vector<AdjustmentData> adjustments = controllersData[ctype.toStdString()].getAdjustments();
        std::vector<AdjustmentData>::iterator it;
        for(it = adjustments.begin(); it!= adjustments.end(); it++){
            ui->listWidget_adjustments->addItem(QString((*it).getName().c_str()));
        }
    }
    if(ctype.compare("P") == 0){
        ui->stackedWidget_controllerValues->setCurrentIndex(0);
    }
    if(ctype.compare("PID") == 0){
        ui->stackedWidget_controllerValues->setCurrentIndex(1);
    }
}





void MainWindow::on_actionNew_activated(){
    emit newConfig();
}

void MainWindow::on_actionOpen_activated(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("Config File (*.yaml);;All (*.*)"), 0, QFileDialog::DontUseNativeDialog);
    if(!fileName.isEmpty()){
        emit openConfig(fileName.toStdString());
    }
}

void MainWindow::on_actionSave_activated(){
    emit saveConfig(std::string(""));
}

void MainWindow::on_actionSave_As_activated(){
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("Config File (*.yaml);;All (*.*)"));
    dialog.setAcceptMode(QFileDialog::AcceptSave);

    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    if(fileNames.size()>0){
        emit saveConfig(fileNames.at(0).toStdString());
    }
}

void MainWindow::on_actionExit_activated(){
    close();
}

void MainWindow::on_pushButton_setObject_clicked(){
    emit setActiveObject(ui->listWidget_Objects->currentItem()->text().toStdString());
}

void MainWindow::on_comboBox_controllerType_currentIndexChanged(const QString &arg1){
    updateAdjustmentsList();

}

void MainWindow::on_listWidget_adjustments_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous){
    if(current){
        QString name = current->text();
        QString ctype = ui->comboBox_controllerType->currentText();
        std::vector<AdjustmentData> ad = controllersData[ctype.toStdString()].getAdjustments();
        std::vector<AdjustmentData>::iterator it;
        for(it = ad.begin(); it!= ad.end(); it++){
            if((*it).getName().compare(name.toStdString()) == 0){
                std::map<std::string, double> param = (*it).getParameters();

                if(ctype.compare("P") == 0){
                    ui->doubleSpinBox_controllerPP->setValue(param["P"]);
                }
                if(ctype.compare("PID") == 0){
                    ui->doubleSpinBox_controllerPIDP->setValue(param["P"]);
                    ui->doubleSpinBox_controllerPIDI->setValue(param["I"]);
                    ui->doubleSpinBox_controllerPIDD->setValue(param["D"]);
                }
            }
        }
    }
}

void MainWindow::on_pushButton_setAdjustment_clicked(){
    QString ctype = ui->comboBox_controllerType->currentText();
    AdjustmentData ad = AdjustmentData();
    std::map<std::string, double> param;

    if(ctype.compare("P") == 0){
        param["P"] = ui->doubleSpinBox_controllerPP->value();
    }
    if(ctype.compare("PID") == 0){
        param["P"] = ui->doubleSpinBox_controllerPIDP->value();
        param["I"] = ui->doubleSpinBox_controllerPIDI->value();
        param["D"] = ui->doubleSpinBox_controllerPIDD->value();
    }
    ad.setParemeters(param);
    emit setActiveController(ctype.toStdString(), ad);
}

void MainWindow::on_pushButton_removeAdjustment_clicked(){
    QString ctype = ui->comboBox_controllerType->currentText();
    QString name = ui->listWidget_adjustments->currentItem()->text();
    emit removeAdjustment(ctype.toStdString(), name.toStdString());
}

void MainWindow::on_pushButton_saveAdjustment_clicked(){
    QDialog dialog;
    dialog.setModal(true);
    dialog.exec();
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

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1.compare(QString("P")) == 0){

    }
    if(arg1.compare(QString("PID")) == 0){

    }
}

void MainWindow::on_comboBox_source_currentIndexChanged(const QString &arg1)
{
    if(arg1.compare(QString("Step")) == 0){
        ui->stackedWidget->setCurrentIndex(0);
    }else if(arg1.compare(QString("Impuls")) == 0){
        ui->stackedWidget->setCurrentIndex(0);
    }else if(arg1.compare(QString("Sinus")) == 0){
        ui->stackedWidget->setCurrentIndex(1);
    }else if(arg1.compare(QString("Square")) == 0){
        ui->stackedWidget->setCurrentIndex(2);
    }else if(arg1.compare(QString("Triangle")) == 0){
        ui->stackedWidget->setCurrentIndex(1);
    }else if(arg1.compare(QString("Noise")) == 0){
        ui->stackedWidget->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton_addSource_clicked()
{
    QString arg1 = ui->comboBox_source->currentText();
    if(arg1.compare(QString("Step")) == 0){
        double amplitude = ui->doubleSpinBox_amplitude1->value();
        emit addSource("step");
        emit setLastSourceParameter("amplitude", amplitude);
        ui->listWidget_sources->addItem(QString("Step: a=").append(QString::number(amplitude, 'f', 2)));
    }else if(arg1.compare(QString("Impuls")) == 0){
        double amplitude = ui->doubleSpinBox_amplitude1->value();
        emit addSource("impuls");
        emit setLastSourceParameter("amplitude", amplitude);
        ui->listWidget_sources->addItem(QString("Impuls: a=").append(QString::number(amplitude, 'f', 2)));
    }else if(arg1.compare(QString("Noise")) == 0){
        double amplitude = ui->doubleSpinBox_amplitude1->value();
        emit addSource("noise");
        emit setLastSourceParameter("amplitude", amplitude);
        ui->listWidget_sources->addItem(QString("Noise: a=").append(QString::number(amplitude, 'f', 2)));
    }else if(arg1.compare(QString("Sinus")) == 0){
        double amplitude = ui->doubleSpinBox_amplitude2->value();
        double frequency = ui->doubleSpinBox_frequency2->value();
        emit addSource("sinus");
        emit setLastSourceParameter("amplitude", amplitude);
        emit setLastSourceParameter("frequency", frequency);
        ui->listWidget_sources->addItem(QString("Sinus: a=").append(QString::number(amplitude, 'f', 2)).append(" f=").append(QString::number(frequency, 'f', 2)));
    }else if(arg1.compare(QString("Triangle")) == 0){
        double amplitude = ui->doubleSpinBox_amplitude2->value();
        double frequency = ui->doubleSpinBox_frequency2->value();
        emit addSource("triangle");
        emit setLastSourceParameter("amplitude", amplitude);
        emit setLastSourceParameter("frequency", frequency);
        ui->listWidget_sources->addItem(QString("Triangle: a=").append(QString::number(amplitude, 'f', 2)).append(" f=").append(QString::number(frequency, 'f', 2)));
    }else if(arg1.compare(QString("Square")) == 0){
        double amplitude = ui->doubleSpinBox_amplitude3->value();
        double frequency = ui->doubleSpinBox_frequency3->value();
        double dutycycle = ui->doubleSpinBox_dutycycle3->value();
        emit addSource("square");
        emit setLastSourceParameter("amplitude", amplitude);
        emit setLastSourceParameter("frequency", frequency);
        emit setLastSourceParameter("dutycycle", dutycycle);
        ui->listWidget_sources->addItem(QString("Square: a=").append(QString::number(amplitude, 'f', 2)).append(" f=").append(QString::number(frequency, 'f', 2)).append(" d=").append(QString::number(dutycycle, 'f', 2)));
    }
}

void MainWindow::on_pushButton_removeSource_clicked(){
    emit removeLastSource();
    int i = ui->listWidget_sources->count();
    if(i>0){
        delete ui->listWidget_sources->item(i-1);
    }
}

void MainWindow::on_checkBox_feedback_toggled(bool checked)
{
    emit setFeedback(checked);
}

void MainWindow::on_doubleSpinBox_P_P_valueChanged(double arg1)
{
    //emit setControllerParameter("P", arg1);
}








