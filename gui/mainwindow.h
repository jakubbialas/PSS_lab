#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>
#include <QtGui/QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <iostream>
#include <sstream>

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
    void newConfig();
    void openConfig(std::string);
    void saveConfig(std::string);

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

    void addSource(std::string type);
    void setLastSourceParameter(std::string name, double value);
    void removeLastSource();
    void setControllerType(std::string);
    void setControllerParameter(std::string, double);
    void setFeedback(bool);

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

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_source_currentIndexChanged(const QString &arg1);

    void on_pushButton_addSource_clicked();

    void on_pushButton_removeSource_clicked();

    void on_checkBox_feedback_toggled(bool checked);

    void on_doubleSpinBox_P_P_valueChanged(double arg1);

    void on_actionNew_activated();
    void on_actionOpen_activated();
    void on_actionSave_activated();
    void on_actionSave_As_activated();
    void on_actionExit_activated();

private:
    Ui::MainWindow *ui; /**< UI zawierajace informacje o oknie programu */

    bool isSimulationStarted; /**< Okresla czy symulacja jest aktulanie wykonywana */
};

#endif // MAINWINDOW_H
