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
    //TODO: set Sources values
}

MultiSourceData EditCustomSourceDialog::getCustomSourceData(){
    MultiSourceData msd;
    msd.setName(ui->lineEdit_name->text().toStdString());
    //TODO: create std::vector<SourceData> sd
    //msd.setSources(sd);
    return msd;
}
