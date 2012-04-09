#include "saveadjustmentdialog.h"
#include "ui_saveadjustmentdialog.h"

SaveAdjustmentDialog::SaveAdjustmentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveAdjustmentDialog)
{
    ui->setupUi(this);
}

SaveAdjustmentDialog::~SaveAdjustmentDialog()
{
    delete ui;
}

std::string SaveAdjustmentDialog::getAdjustmentName(){
    return ui->lineEdit_name->text().toStdString();
}
