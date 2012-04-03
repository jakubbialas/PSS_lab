#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>
#include <QtGui/QApplication>
#include <QMessageBox>
#include <sstream>
#include <QTimer>
#include "source.h"
#include "discreteobject.h"
#include "yamlconfigparser.h"

using namespace std;
namespace Ui {
    class MainWindow;
}

/**
 * @brief Klasa okna programu
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor okna
     *
     * @param parent Rodzic
     */
    explicit MainWindow(QWidget *parent = 0);
    /**
     * @brief Destruktor
     *
     */
    ~MainWindow();

signals:

//signals to simulation object (setings):
    /**
     * @brief Sygnał emitowany przy załadowaniu pliku konfiguracyjnego
     *
     * @param Sciezka do pliku konfiguracyjnego
     */
    void loadConfig(const char *);
    /**
     * @brief Sygnał emitowany przy wyborze nowego obiektu
     *
     * @param std::string Nazwa obiektu
     */
    void setObject(std::string);
    /**
     * @brief Sygnał emitowany przy zmianie czasu probkowania wykresow
     *
     * @param int czas odswiezania[ms]
     */
    void setSamplingTime(int);
    /**
     * @brief Sygnał emitowany po wyborze typu wymuszenia
     *
     * @param Source::SourceType Typ wymuszenia
     */
    void setSourceType(Source::SourceType);
    /**
     * @brief Sygnał emitowany przy zmianie wartosci wymuszenia
     *
     * @param double Wartosc wymuszenia
     */
    void setSourceValue(double);
    /**
     * @brief
     *
     * @param std::string
     */
    void setControllerType(std::string);

//signals to simulation object (simulate):
    /**
     * @brief Sygnał emitowany aby rozpoczac ciagla symulacje
     *
     */
    void startSimulation();
    /**
     * @brief Sygnał emitowany aby zatrzymac ciagla symulacje
     *
     */
    void stopSimulation();
    /**
     * @brief Sygnał emitowany  aby zresetowac wykresy i symulacje
     *
     */
    void resetSimulation();
    /**
     * @brief Sygnał emitowany aby rozpoczac symulacje krokowa
     *
     * @param int Liczba krokow
     */
    void stepSimulation(int);

private slots:

//signals from simulation object:
  //draw:
    /**
     * @brief Gniazdo odbierajace sygnal rysowania wejscia
     *
     * @param y Wartosc wejscia
     */
    void drawInput(double y);
    /**
     * @brief Gniazdo odbierajace sygnal rysowania wyjscia
     *
     * @param y Wartosc wyjscia
     */
    void drawOutput(double y);
    /**
     * @brief Gniazdo odbierajace sygnal bledu(nie zaimplementowane)
     *
     * @param y Wartosc bledu
     */
    void drawError(double y);
    /**
     * @brief Gniazdo odbierajace sygnal kontrolujacy(nie zaimplementowane)
     *
     * @param y wartosc sygnalu
     */
    void drawControl(double y);
  //infos:
    /**
     * @brief Gniazdo odbierajace sygnal ustawiajacy liste dostepnych obiektow
     *
     * @param std::vector<std::string> Lista obiektow
     */
    void setObjectsList(std::vector<std::string>);

//buttons:
    /**
     * @brief
     *
     */
    void on_simBtn_clicked();
    /**
     * @brief
     *
     */
    void on_getConfigBtn_clicked();
    /**
     * @brief
     *
     */
    void on_resetBtn_clicked();

//sliders:
    /**
     * @brief
     *
     * @param value
     */
    void on_samplingSlider_valueChanged(int value);


//radios simulation:
    /**
     * @brief
     *
     * @param checked
     */
    void on_contSimRadio_toggled(bool checked);
    /**
     * @brief
     *
     * @param checked
     */
    void on_stepSimRadio_toggled(bool checked);


//object set:
    /**
     * @brief
     *
     * @param arg1
     */
    void on_comboBoxObject_currentIndexChanged(const QString &arg1);

    /**
     * @brief
     *
     * @param checked
     */
    void on_stepSourceRadio_toggled(bool checked);

    /**
     * @brief
     *
     * @param checked
     */
    void on_impSourceRadio_toggled(bool checked);

    /**
     * @brief
     *
     * @param checked
     */
    void on_nonSourceRadio_toggled(bool checked);

    /**
     * @brief
     *
     * @param checked
     */
    void on_manualSourceRadio_toggled(bool checked);

    /**
     * @brief
     *
     * @param arg1
     */
    void on_sourceValueEdit_textChanged(const QString &arg1);

    /**
     * @brief
     *
     * @param value
     */
    void on_sourceValueSilder_valueChanged(int value);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui; /**< UI zawierajace informacje o oknie programu */

    bool isSimulationStarted; /**< Okresla czy symulacja jest aktulanie wykonywana */
};

#endif // MAINWINDOW_H
