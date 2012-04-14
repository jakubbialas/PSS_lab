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
        }else{
            emit startSimulation();
            isSimulationStarted = true;
        }
        updateButtons();
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

void MainWindow::updateButtons(){
    if(isSimulationStarted){
        ui->simBtn->setText("Pause simulation");
    }else{
        ui->simBtn->setText("Start simulation");
    }
    ui->simFrame->setEnabled(!isSimulationStarted);
}

void MainWindow::simulationStopped(std::string msg){
    isSimulationStarted = false;
    updateButtons();
    QMessageBox::warning(this, "Simulation Stoped", QString(msg.c_str()));
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

void MainWindow::retObjectData(ObjectData od){
    EditObjectDialog *eod = new EditObjectDialog();
    eod->setObjectData(od);
    int status = eod->exec();
    if(status == QDialog::Accepted){
        emit this->editObject(od.getName(), eod->getObjectData());
    }
    delete eod;
}

void MainWindow::retActiveObject(std::string name){
    std::ostringstream msg;
    msg << "Simulation object: " << name << ".";
    ui->statusBar->showMessage(msg.str().c_str(), 5000);
}

void MainWindow::retAdjustmentsList(std::vector<AdjustmentData> adjustments){
    adjustmentsData = adjustments;
    updateAdjustmentsList();
}

void MainWindow::updateAdjustmentsList(){
    ui->listWidget_adjustments->clear();
    QString ctype = ui->comboBox_controllerType->currentText();

    std::vector<AdjustmentData>::iterator it;

    for(it = adjustmentsData.begin(); it!= adjustmentsData.end(); it++){
        if((*it).getType().compare(ctype.toStdString()) == 0){
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

void MainWindow::retActiveAdjustment(std::string type, std::string adj){
    std::ostringstream msg;
    msg << "Controller set to " << type << ", adjustments: " << adj << ".";
    ui->statusBar->showMessage(msg.str().c_str(), 5000);
}


void MainWindow::retCustomSourcesList(std::vector<std::string> names){
    ui->listWidget_customSources->clear();
    std::vector<std::string>::iterator it;
    for(it = names.begin(); it < names.end(); it++){
        ui->listWidget_customSources->addItem(QString((*it).c_str()));
    }
}

void MainWindow::retCustomSourceData(MultiSourceData msd){
    EditCustomSourceDialog *ecsd = new EditCustomSourceDialog();
    ecsd->setCustomSourceData(msd);
    int status = ecsd->exec();
    if(status == QDialog::Accepted){
        emit this->editCustomSource(msd.getName(), ecsd->getCustomSourceData());
    }
    delete ecsd;
}

void MainWindow::retActiveSource(std::string name){
    std::ostringstream msg;
    msg << "Simulation source: " << name << ".";
    ui->statusBar->showMessage(msg.str().c_str(), 5000);
}



//////////////////////////////////// CONFIG \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void MainWindow::on_actionNew_activated(){
    emit newConfig();
    ui->actionSave->setEnabled(false);
}

void MainWindow::on_actionOpen_activated(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath(), tr("Config File (*.yaml);;All (*.*)"), 0, QFileDialog::DontUseNativeDialog);
    if(!fileName.isEmpty()){
        emit openConfig(fileName.toStdString());
        ui->actionSave->setEnabled(true);
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

//////////////////////////////////// OBJECTS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void MainWindow::on_pushButton_setObject_clicked(){
    emit setActiveObject(ui->listWidget_Objects->currentItem()->text().toStdString());
}

void MainWindow::on_pushButton_removeObject_clicked(){
    emit removeObject(ui->listWidget_Objects->currentItem()->text().toStdString());
}

void MainWindow::on_pushButton_editObject_clicked(){
    emit this->getObjectData(ui->listWidget_Objects->currentItem()->text().toStdString());
}

void MainWindow::on_pushButton_newObject_clicked(){
    EditObjectDialog *eod = new EditObjectDialog();
    int status = eod->exec();
    if(status == QDialog::Accepted){
        emit this->editObject(eod->getObjectData().getName(), eod->getObjectData());
    }
    delete eod;
}




//////////////////////////////////// ADJUSTMENTS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void MainWindow::on_comboBox_controllerType_currentIndexChanged(const QString &arg1){
    updateAdjustmentsList();

}

void MainWindow::on_listWidget_adjustments_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous){
    if(current){
        QString name = current->text();
        QString ctype = ui->comboBox_controllerType->currentText();
        std::vector<AdjustmentData>::iterator it;

        //std::vector<AdjustmentData> ad = controllersData[ctype.toStdString()].getAdjustments();
        for(it = adjustmentsData.begin(); it!= adjustmentsData.end(); it++){
            if((*it).getName().compare(name.toStdString()) == 0 &&
                    (*it).getType().compare(ctype.toStdString()) == 0 ){

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
    ad.setType(ctype.toStdString());
    emit setActiveAdjustment(ad);
}

void MainWindow::on_pushButton_removeAdjustment_clicked(){
    QString ctype = ui->comboBox_controllerType->currentText();
    QString name = ui->listWidget_adjustments->currentItem()->text();
    emit removeAdjustment(ctype.toStdString(), name.toStdString());
}

void MainWindow::on_pushButton_saveAdjustment_clicked(){
    SaveAdjustmentDialog *sad = new SaveAdjustmentDialog();
    int status = sad->exec();
    if(status == QDialog::Accepted){
        std::string name = sad->getAdjustmentName();
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
        ad.setName(name);
        ad.setType(ctype.toStdString());
        emit saveAdjustment(ad);
    }
    delete sad;
}



//////////////////////////////////// SIMPLE SOURCES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void MainWindow::on_listWidget_simpleSources_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous){
    QString arg1 = current->text();

    if(arg1.compare(QString("Step")) == 0){
        ui->stackedWidget_simpleSourceParam->setCurrentIndex(2);
    }else if(arg1.compare(QString("Impuls")) == 0){
        ui->stackedWidget_simpleSourceParam->setCurrentIndex(1);
    }else if(arg1.compare(QString("Sinus")) == 0){
        ui->stackedWidget_simpleSourceParam->setCurrentIndex(3);
    }else if(arg1.compare(QString("Square")) == 0){
        ui->stackedWidget_simpleSourceParam->setCurrentIndex(4);
    }else if(arg1.compare(QString("Triangle")) == 0){
        ui->stackedWidget_simpleSourceParam->setCurrentIndex(3);
    }else if(arg1.compare(QString("Noise")) == 0){
        ui->stackedWidget_simpleSourceParam->setCurrentIndex(1);
    }else{
        ui->stackedWidget_simpleSourceParam->setCurrentIndex(0);
    }
}

void MainWindow::on_pushButton_setSimpleSource_clicked(){
    QString arg1 = ui->listWidget_simpleSources->currentItem()->text();

    std::map<std::string, double> param;
    std::string name;

    if(arg1.compare(QString("Step")) == 0){
        param["amplitude"] = ui->doubleSpinBox_amplitude1b->value();
        name = "step";
    }else if(arg1.compare(QString("Impuls")) == 0){
        param["amplitude"] = ui->doubleSpinBox_amplitude1->value();
        name = "impuls";
    }else if(arg1.compare(QString("Noise")) == 0){
        param["amplitude"] = ui->doubleSpinBox_amplitude1->value();
        name = "noise";
    }else if(arg1.compare(QString("Sinus")) == 0){
        param["amplitude"] = ui->doubleSpinBox_amplitude2->value();
        param["frequency"] = ui->doubleSpinBox_frequency2->value();
        name = "sinus";
    }else if(arg1.compare(QString("Triangle")) == 0){
        param["amplitude"] = ui->doubleSpinBox_amplitude2->value();
        param["frequency"] = ui->doubleSpinBox_frequency2->value();
        name = "triangle";
    }else if(arg1.compare(QString("Square")) == 0){
        param["amplitude"] = ui->doubleSpinBox_amplitude3->value();
        param["frequency"] = ui->doubleSpinBox_frequency3->value();
        param["dutycycle"] = ui->doubleSpinBox_dutycycle3->value();
        name = "square";
    }

    if(!name.empty()){
        emit setActiveSimpleSource(name, param);
    }
}


//////////////////////////////////// CUSTOM SOURCES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

void MainWindow::on_pushButton_addCustomSource_clicked(){
    EditCustomSourceDialog *ecsd = new EditCustomSourceDialog();
    int status = ecsd->exec();
    if(status == QDialog::Accepted){
        emit editCustomSource(ecsd->getCustomSourceData().getName(), ecsd->getCustomSourceData());
    }
    delete ecsd;
}

void MainWindow::on_pushButton_removeCustomSource_clicked(){
    emit removeCustomSource(ui->listWidget_customSources->currentItem()->text().toStdString());
}

void MainWindow::on_pushButton_editCustomSource_clicked(){
    emit getCustomSourceData(ui->listWidget_customSources->currentItem()->text().toStdString());
}

void MainWindow::on_pushButton_setCustomSource_clicked(){
    emit setActiveCustomSource(ui->listWidget_customSources->currentItem()->text().toStdString());
}


//////////////////////////////////// OTHERS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

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

void MainWindow::on_checkBox_feedback_toggled(bool checked)
{
    emit setFeedback(checked);
}


void MainWindow::on_checkBox_saveSignals_toggled(bool checked)
{
    ui->frame_saveSignalsParam->setEnabled(checked);
    if(!checked){
        emit saveSignalsToFile(false, "");
    }
}

void MainWindow::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("CSV File (*.csv);;All (*.*)"));
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    if(fileNames.size()>0){
        emit saveSignalsToFile(true, fileNames.at(0).toStdString());
    }
}
