#ifndef LIVEPLOT_H
#define LIVEPLOT_H

#include <qwt_plot.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qvector.h>
#include <map>
#include <string>

//class QwtPlotCurve;

/**
 * @brief Widget odpowiedzialny za rysowanie wykresów, dziedziczy po QwtPlot
 *
 */
class LivePlot : public QwtPlot
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor(nie pozwalający na automatyczną konwersję), rodzicem obiektu moze byc dowolny obiekt dziediczacy po QWidget
     *rodzic moze byc tez rowny 0, co oznacza ze jest on "samodzielny"(Np. dodajac do MainWindow przycisk, podajemy MainWindow jako rodzica,
     *ale mozemy takze stworzyc sam przycisk bez podania rodzica i mimo wszystko aplikacja zadziala)
     *
     * @param parent Rodzic(np. MainWindow)
     */
    explicit LivePlot(QWidget *parent = 0);

signals:

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
    void addPen(std::string, QwtSymbol*);
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

private:
    std::map<std::string, QVector<double>*> m_X; /**< Mapa przechowująca wartosci X, dla Pena będacego kluczem */
    std::map<std::string, QVector<double>*> m_Y; /**< Mapa przechowująca wartosci Y, dla Pena będacego kluczem */
    std::map<std::string, QwtPlotCurve*> m_curves; /**< TODO */
};

#endif // LIVEPLOT_H
