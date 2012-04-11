#include "editcustomsourcedialog.h"
#include "ui_editcustomsourcedialog.h"

EditCustomSourceDialog::EditCustomSourceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCustomSourceDialog)
{
    ui->setupUi(this);
}

EditCustomSourceDialog::~EditCustomSourceDialog()
{
    delete ui;
}

void EditCustomSourceDialog::setCustomSourceData(MultiSourceData msd){
    ui->lineEdit_name->setText(msd.getName().c_str());
    sources = msd.getSources();
    updateSourceList();
}

MultiSourceData EditCustomSourceDialog::getCustomSourceData(){
    MultiSourceData msd;
    msd.setName(ui->lineEdit_name->text().toStdString());
    msd.setSources(sources);
    return msd;
}

void EditCustomSourceDialog::updateSourceList(){
    ui->listWidget_sources->clear();
    std::vector<SourceData>::iterator it;
    for(it = sources.begin(); it != sources.end(); it++){
        std::ostringstream buf;
        buf << (*it).getType() << ":";
        std::map<std::string, double>::iterator it2;
        std::map<std::string, double> param = (*it).getParameters();
        for(it2 = param.begin(); it2 != param.end(); it2++){
            if((*it2).first.compare("amplitude") == 0){
                buf << " A = " << (*it2).second;
            }else if((*it2).first.compare("frequency") == 0){
                buf << " f = " << (*it2).second;
            }else if((*it2).first.compare("dutycycle") == 0){
                buf << " d = " << (*it2).second;
            }
        }
        ui->listWidget_sources->addItem(buf.str().c_str());
    }
}

void EditCustomSourceDialog::on_pushButton_addSource_clicked(){
    SourceData sd;
    sd.setType(ui->comboBox_source->currentText().toStdString());
    std::map<std::string, double> param;
    if(sd.getType().compare("step") == 0 || sd.getType().compare("impuls") == 0 || sd.getType().compare("noise") == 0){
        param["amplitude"] = ui->doubleSpinBox_amplitude1->value();
    }
    if(sd.getType().compare("sinus") == 0 || sd.getType().compare("triangle") == 0){
        param["amplitude"] = ui->doubleSpinBox_amplitude2->value();
        param["frequency"] = ui->doubleSpinBox_frequency2->value();
    }
    if(sd.getType().compare("square") == 0){
        param["amplitude"] = ui->doubleSpinBox_amplitude3->value();
        param["frequency"] = ui->doubleSpinBox_frequency3->value();
        param["dutycycle"] = ui->doubleSpinBox_dutycycle3->value();
    }
    sd.setParameters(param);
    sources.push_back(sd);

    updateSourceList();
}

void EditCustomSourceDialog::on_pushButton_removeSource_clicked(){
    int index = ui->listWidget_sources->currentRow();
    std::vector<SourceData>::iterator it = sources.begin() + index;
    sources.erase(it);
    updateSourceList();
}

void EditCustomSourceDialog::on_comboBox_source_currentIndexChanged(const QString &arg1){
    if(arg1.compare("step") == 0 || arg1.compare("impuls") == 0 || arg1.compare("noise") == 0){
        ui->stackedWidget_sourceParam->setCurrentIndex(1);
    }else if(arg1.compare("sinus") == 0 || arg1.compare("triangle") == 0){
        ui->stackedWidget_sourceParam->setCurrentIndex(2);
    }else if(arg1.compare("square") == 0){
        ui->stackedWidget_sourceParam->setCurrentIndex(3);
    }else{
        ui->stackedWidget_sourceParam->setCurrentIndex(0);
    }
}
