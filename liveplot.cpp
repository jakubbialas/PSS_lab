#include "liveplot.h"

LivePlot::LivePlot(QWidget *parent) :
    QwtPlot(parent)
{

}

void LivePlot::addPen(std::string name, QwtSymbol *symbol){
    QVector<double> *X = new QVector<double>();
    QVector<double> *Y = new QVector<double>();
    QwtPlotCurve *curve = new QwtPlotCurve();

    m_X[name] = X;
    m_Y[name] = Y;
    m_curves[name] = curve;

    curve->setSymbol( symbol );
    curve->setStyle( QwtPlotCurve::NoCurve );

    curve->setSamples(*X, *Y);
    curve->attach(this);
}

void LivePlot::removePen(std::string name){

}

void LivePlot::drawPoint(double x, double y, std::string pen){
    m_X[pen]->push_back(x);
    m_Y[pen]->push_back(y);

    m_curves[pen]->setSamples(*m_X[pen], *m_Y[pen]);
    this->replot();
}

void LivePlot::drawPoint(double y, std::string pen){
    double x = m_X[pen]->last() + 1;
    drawPoint(x, y, pen);
}


double LivePlot::getLastX(){
    //return m_X.at()
return 1;
}
