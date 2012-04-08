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
#include "simulation/object/objectdata.h"

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

    void startSimulation();
    void stopSimulation();
    void resetSimulation();
    void stepSimulation(int);
    void setSamplingTime(int);
    void setFeedback(bool);

    void setActiveObject(std::string);
    void getObjectData(std::string);
    void getObjectsList();
    void editObjectData(std::string, ObjectData);



    void addSource(std::string type);
    void setLastSourceParameter(std::string name, double value);
    void removeLastSource();
    void setControllerType(std::string);
    void setControllerParameter(std::string, double);

private slots:
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

    void retObjectsList(std::vector<std::string>);
    void retObjectData(ObjectData);
    void retActiveObject(std::string);

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
