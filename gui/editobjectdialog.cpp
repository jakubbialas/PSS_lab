#include "editobjectdialog.h"
#include "ui_editobjectdialog.h"

EditObjectDialog::EditObjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditObjectDialog)
{
    ui->setupUi(this);
}

EditObjectDialog::~EditObjectDialog()
{
    delete ui;
}

void EditObjectDialog::setObjectData(ObjectData od){
    ui->lineEdit_name->setText(od.getName().c_str());
    //TODO: set ModelData values
}

ObjectData EditObjectDialog::getObjectData(){
    ObjectData od;
    od.setName(ui->lineEdit_name->text().toStdString());
    //TODO: create std::vector<ModelData> md
    //od.setModels(md);
    return od;
}
