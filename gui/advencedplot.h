#ifndef ADVENCEDPLOT_H
#define ADVENCEDPLOT_H

#include <QWidget>

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qvector.h>
#include <map>
#include <string>

namespace Ui {
    class AdvencedPlot;
}

class AdvencedPlot : public QWidget
{
    Q_OBJECT

public:
    explicit AdvencedPlot(QWidget *parent = 0);
    ~AdvencedPlot();

public slots:
    /**
     * @brief
     *
     * @param x
     * @param y
     * @param pen
     */
    void drawPoint(double x, double y, std::string pen);
    /**
     * @brief
     *
     * @param y
     * @param pen
     */
    void drawPoint(double y, std::string pen);
    /**
     * @brief
     *
     * @param std::string
     * @param
     */
    void addPen(std::string, QwtSymbol*, int plot);
    /**
     * @brief
     *
     * @param std::string
     */
    void removePen(std::string);
    /**
     * @brief
     *
     * @param std::string
     */
    void resetPen(std::string);
    void reset();

private slots:
    void on_horizontalScrollBarXPos_valueChanged(int value);

private:
    std::map<std::string, QVector<double>*> m_X; /**< Mapa przechowująca wartosci X, dla Pena będacego kluczem */
    std::map<std::string, QVector<double>*> m_Y; /**< Mapa przechowująca wartosci Y, dla Pena będacego kluczem */
    std::map<std::string, QVector<double>*> d_X; /**< Mapa przechowująca wartosci X, dla Pena będacego kluczem */
    std::map<std::string, QVector<double>*> d_Y; /**< Mapa przechowująca wartosci Y, dla Pena będacego kluczem */
    std::map<std::string, QwtPlotCurve*> m_curves; /**< TODO */

private:
    Ui::AdvencedPlot *ui;

    int posX;
    int sizeX;
    int howX;
};

#endif // ADVENCEDPLOT_H
