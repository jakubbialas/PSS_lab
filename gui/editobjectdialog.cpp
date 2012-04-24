#include "editobjectdialog.h"
#include "ui_editobjectdialog.h"

EditObjectDialog::EditObjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditObjectDialog)
{
    ui->setupUi(this);

    frame = new QFrame();
    layout = new QGridLayout(frame);

    ui->scroll->setWidget(frame);
}

EditObjectDialog::~EditObjectDialog()
{
    delete ui;
}

void EditObjectDialog::setObjectData(ObjectData *od){
    ui->lineEdit_name->setText(od->getName().c_str());
    ui->objectBox->setValue(od->getModels().size());

    std::vector<ModelData> mdv = od->getModels();
    std::vector<ModelData>::iterator it_md = mdv.begin();
    for(std::vector<ModelComponent*>::iterator it_mc = mcVector.begin(); ((it_mc != mcVector.end()) || (it_md !=mdv.end())); it_mc++ ){
        (*it_mc)->setModelData(&(*it_md));
        it_md++;
    }
}

ObjectData EditObjectDialog::getObjectData(){
    ObjectData od;
    od.setName(ui->lineEdit_name->text().toStdString());
    std::vector<ModelData> mdv;

    for(std::vector<ModelComponent*>::iterator i = mcVector.begin(); i != mcVector.end(); i++){
        ModelData md = *((*i)->getModelData());
        mdv.push_back( md );
    }

    od.setModels(mdv);
    return od;
}

void EditObjectDialog::on_objectBox_valueChanged(int arg1)
{
    if(mcVector.size()>arg1){
        for(int i = mcVector.size(); i> arg1; i--){
            ModelComponent *mc = mcVector.at(i-1);
            layout->removeWidget(mc);
            mcVector.pop_back();
            delete mc;
        }
    }

    else if(mcVector.size()<arg1){
        for(int i = mcVector.size(); i< arg1; i++){
            ModelComponent *mc = new ModelComponent();
            mcVector.push_back(mc);
            layout->addWidget(mc);
        }
    }
}



void EditObjectDialog::on_buttonBox_accepted()
{

}
