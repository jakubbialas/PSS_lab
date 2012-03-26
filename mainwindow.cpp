#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->coercePlot->addPen("red", new QwtSymbol( QwtSymbol::XCross, Qt::NoBrush, QPen( Qt::red ), QSize( 4, 4 ) ) );
    ui->coercePlot->addPen("blue", new QwtSymbol( QwtSymbol::Ellipse, Qt::NoBrush, QPen( Qt::blue ), QSize( 3, 3 ) ));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(addingNewPoint()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLabelText(const QString str){
    ui->label->setText(str);
}

void MainWindow::setPlot1aData( double y){
    ui->coercePlot->drawPoint(y, "red");
}
void MainWindow::setPlot1bData( double y){
    ui->coercePlot->drawPoint(y, "blue");
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
    if(&object == NULL) return;

    double input = 0;

    if( ui->stepCoerceRadio->isChecked() ) coerce->setCoercionType(coerce->STEP);
    else if( ui->impCoerceRadio->isChecked() ) coerce->setCoercionType(coerce->IMP);
    else if( ui->nonCoercionRadio->isChecked() ) coerce->setCoercionType(coerce->NONE);
    else if( ui->manualCoerceRadio->isChecked() ){
        input = ui->coerceEdit->text().toInt();
        coerce->setCoercionType(coerce->CUSTOM);
    }else{
        QMessageBox msgBox;
        msgBox.setText("Choose coercion type!");
        msgBox.exec();
        return;
    }

    if( ui->stepSimRadio->isChecked() ){
        int steps = ui->stepNoEdit->text().toInt();

        for(int i = 0; i <steps; i++){
           setPlot1aData(object->Symuluj(  coerce->nextSample(input)));
        }

    }else{
        if(!timer->isActive()){
            ui->simBtn->setText("Stop simulation");
            timer->start(1000);

        }else{
            ui->simBtn->setText("Simulate");
            timer->stop();
        }
    }

}

void MainWindow::on_getConfigBtn_clicked()
{
    YamlConfigParser ymp;
    ymp.parseFile("model.yaml");

    //std::string name("inercja");
    //std::string name("calka");
    //std::string name("inercja z calka");
    std::string name("niestacjonarny1");

    if(ymp.hasKey(name)){
        object = new DiscreteObject(*ymp.getObject(name));
        cout << "dodano obiekt" << endl;
    }else{
        cout << "nie dodano obiektu" << endl;
    }
    coerce = new Coerce();
}

void MainWindow::on_manualCoerceRadio_toggled(bool checked)
{
    ui->coerceFrame->setEnabled(ui->manualCoerceRadio->isChecked());
}

void MainWindow::on_coerceEdit_textChanged(const QString &arg1)
{
    ui->coerceSilder->setValue(ui->coerceEdit->text().toDouble());
}

void MainWindow::on_coerceSilder_valueChanged(int value)
{
    std::stringstream convert;
    convert << ui->coerceSilder->value();
    ui->coerceEdit->setText((convert.str().c_str()));
}

void MainWindow::addingNewPoint(){
     double input = 0;
    if( ui->stepCoerceRadio->isChecked() ) coerce->setCoercionType(coerce->STEP);
    else if( ui->impCoerceRadio->isChecked() ) coerce->setCoercionType(coerce->IMP);
    else if( ui->nonCoercionRadio->isChecked() ) coerce->setCoercionType(coerce->NONE);
    else if( ui->manualCoerceRadio->isChecked() ){
        input = ui->coerceEdit->text().toInt();
        coerce->setCoercionType(coerce->CUSTOM);
    }

    setPlot1aData(object->Symuluj(  coerce->nextSample(input)));
}
