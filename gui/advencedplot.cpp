#include "advencedplot.h"
#include "ui_advencedplot.h"

const unsigned int AdvencedPlot::maxMemory = 64000;

AdvencedPlot::AdvencedPlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdvencedPlot)
{
    ui->setupUi(this);

    sizeX = 200;
    posX = -1;
    howX = 0;
}

AdvencedPlot::~AdvencedPlot()
{
    delete ui;
}

void AdvencedPlot::addPen(std::string name, QwtSymbol *symbol, int plot){
    QVector<double> *X = new QVector<double>();
    QVector<double> *Y = new QVector<double>();
    QVector<double> *dX = new QVector<double>(sizeX);
    QVector<double> *dY = new QVector<double>(sizeX);
    QwtPlotCurve *curve = new QwtPlotCurve();

    m_X[name] = X;
    m_Y[name] = Y;
    d_X[name] = dX;
    d_Y[name] = dY;
    m_curves[name] = curve;

    curve->setSymbol( symbol );
    curve->setStyle( QwtPlotCurve::NoCurve );

    curve->setSamples(*X, *Y);
    if(plot == 1){
        curve->attach(ui->qwtPlot_1);
    }else{
        curve->attach(ui->qwtPlot_2);
    }

}

void AdvencedPlot::removePen(std::string name){

}

void AdvencedPlot::resetPen(std::string pen){
    m_X[pen]->clear();
    m_Y[pen]->clear();

    m_curves[pen]->setSamples(*m_X[pen], *m_Y[pen]);
    ui->qwtPlot_1->replot();
    ui->qwtPlot_2->replot();
}

void AdvencedPlot::reset(){
    std::map<std::string, QVector<double>*>::iterator it;
    for(it = m_X.begin(); it != m_X.end(); it++){
        m_X[(*it).first]->clear();
        m_Y[(*it).first]->clear();
        delete d_X[(*it).first];
        delete d_Y[(*it).first];
        QVector<double> *dX = new QVector<double>(sizeX);
        QVector<double> *dY = new QVector<double>(sizeX);
        d_X[(*it).first] = dX;
        d_Y[(*it).first] = dY;
        //d_X[(*it).first]->clear();
        //d_Y[(*it).first]->clear();

        m_curves[(*it).first]->setSamples(*d_X[(*it).first], *d_Y[(*it).first]);
    }
    if(posX != -1) posX = 0;
    howX = 0;
    ui->horizontalScrollBarXPos->setMaximum(0);
    ui->horizontalScrollBarXPos->setValue(0);

    ui->qwtPlot_1->replot();
    ui->qwtPlot_2->replot();
}

void AdvencedPlot::drawPoint(double x, double y, std::string pen){
    m_X[pen]->push_back(x);
    m_Y[pen]->push_back(y);
    if(m_X[pen]->size() > maxMemory){
        m_X[pen]->pop_front();
        m_Y[pen]->pop_front();
    }

    if(m_X[pen]->size() > howX){
        howX = m_X[pen]->size();
        if(howX-sizeX > 0){
            ui->horizontalScrollBarXPos->setMaximum(howX-sizeX);
        }
    }

    if(m_X[pen]->size() <= sizeX){
        std::copy(m_X[pen]->begin(), m_X[pen]->end(), d_X[pen]->begin());
        std::copy(m_Y[pen]->begin(), m_Y[pen]->end(), d_Y[pen]->begin());

        m_curves[pen]->setSamples(*d_X[pen], *d_Y[pen]);
        ui->qwtPlot_1->replot();
        ui->qwtPlot_2->replot();
    }else if(posX == -1){
        std::copy(m_X[pen]->end()-sizeX, m_X[pen]->end(), d_X[pen]->begin());
        std::copy(m_Y[pen]->end()-sizeX, m_Y[pen]->end(), d_Y[pen]->begin());

        m_curves[pen]->setSamples(*d_X[pen], *d_Y[pen]);
        ui->qwtPlot_1->replot();
        ui->qwtPlot_2->replot();

        ui->horizontalScrollBarXPos->setValue(ui->horizontalScrollBarXPos->maximum());
    }
}

void AdvencedPlot::drawPoint(double y, std::string pen){
    double x;
    if(m_X[pen]->empty()){
        x = 0;
    }else{
        x = m_X[pen]->last() + 1;
    }
    drawPoint(x, y, pen);
}

void AdvencedPlot::on_horizontalScrollBarXPos_valueChanged(int value)
{
    posX = value;
    std::map<std::string, QVector<double>*>::iterator it;

    if(posX == ui->horizontalScrollBarXPos->maximum()){
        posX=-1;
    }else{
        for(it = m_X.begin(); it != m_X.end(); it++){
            std::copy(m_X[(*it).first]->begin()+posX, m_X[(*it).first]->begin()+sizeX+posX, d_X[(*it).first]->begin());
            std::copy(m_Y[(*it).first]->begin()+posX, m_Y[(*it).first]->begin()+sizeX+posX, d_Y[(*it).first]->begin());

            m_curves[(*it).first]->setSamples(*d_X[(*it).first], *d_Y[(*it).first]);
        }
        ui->qwtPlot_1->replot();
        ui->qwtPlot_2->replot();
    }
}

void AdvencedPlot::on_pushButton_3_clicked()
{
    this->reset();
}

void AdvencedPlot::on_pushButton_savAll_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("CSV File (*.csv);;All (*.*)"));
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    QStringList fileNames;
    if (dialog.exec()){
        fileNames = dialog.selectedFiles();
        if(fileNames.size()>0){
            std::fstream file(fileNames.at(0).toStdString().c_str());

            std::map<std::string, QVector<double>*>::iterator it;

            int size = m_Y[(*(m_Y.begin())).first]->size();
            for(int i=0; i<size; i++){
                for(it = m_Y.begin(); it!=m_Y.end(); it++){
                    file << m_Y[(*it).first]->at(i) << ";";
                }
                file << "\n";
            }
            file.close();
        }
    }
}

void AdvencedPlot::on_pushButton_saveCurrent_clicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setNameFilter(tr("CSV File (*.csv);;All (*.*)"));
    dialog.setAcceptMode(QFileDialog::AcceptOpen);

    QStringList fileNames;
    if (dialog.exec()){
        fileNames = dialog.selectedFiles();
        if(fileNames.size()>0){
            std::ofstream file(fileNames.at(0).toStdString().c_str());

            std::map<std::string, QVector<double>*>::iterator it;

            int size = d_Y[(*(d_Y.begin())).first]->size();
            for(int i=0; i<size; i++){
                for(it = d_Y.begin(); it!=d_Y.end(); it++){
                    file << d_Y[(*it).first]->at(i) << ";";
                }
                file << "\n";
            }
            file.close();
        }
    }
}
