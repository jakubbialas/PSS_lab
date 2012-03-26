#ifndef LIVEPLOT_H
#define LIVEPLOT_H

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qvector.h>
#include <map>
#include <string>

//class QwtPlotCurve;

class LivePlot : public QwtPlot
{
    Q_OBJECT
public:
    explicit LivePlot(QWidget *parent = 0);

signals:

public slots:
    void drawPoint(double x, double y, std::string pen);
    void drawPoint(double y, std::string pen);
    void addPen(std::string, QwtSymbol*);
    void removePen(std::string);

private:
    std::map<std::string, QVector<double>*> m_X;
    std::map<std::string, QVector<double>*> m_Y;
    std::map<std::string, QwtPlotCurve*> m_curves;
};

#endif // LIVEPLOT_H
