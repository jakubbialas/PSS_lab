#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <vector>
#include <QtGui/QApplication>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QFileDialog>
#include <iostream>
#include <sstream>
#include "simulation/object/objectdata.h"
#include "simulation/controller/adjustmentdata.h"
#include "simulation/source/multisourcedata.h"

#include "saveadjustmentdialog.h"
#include "editobjectdialog.h"
#include "editcustomsourcedialog.h"

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
    /**
     * @brief Sygnał emitowany w celu zresetowania konfiguracji
     *
     */
    void newConfig();
    /**
     * @brief Sygnał emitowany w celu wczytania konfiguracji z pliku
     *
     * @param std::string ścierzka do pliku
     */
    void openConfig(std::string);
    /**
     * @brief Sygnał emitowany w celu zapisania konfiguracji do pliku
     *
     * @param std::string ścierzka do pliku
     */
    void saveConfig(std::string);

    /**
     * @brief Sygnał emitowany w celu rozpoczęcia symulacji ciągłej
     *
     */
    void startSimulation();
    /**
     * @brief Sygnał emitowany w celu zatrzymania symulacji ciągłej
     *
     */
    void stopSimulation();
    /**
     * @brief Sygnał emitowany w celu zresetowania symulaji
     *
     */
    void resetSimulation();
    /**
     * @brief Sygnał emitowany w celu wykonania n kroków symulacji
     *
     * @param int liczba kroków
     */
    void stepSimulation(int);
    /**
     * @brief Sygnał emitowany w celu ustawiania czasu próbkowania
     *
     * @param int czas próbkowania
     */
    void setSamplingTime(int);
    /**
     * @brief Sygnał emitowany w celu ustawiania sprzężenia zwrotnego
     *
     * @param bool
     */
    void setFeedback(bool);
    /**
     * @brief Sygnał emitowany w celu ustawiania zapisu sygnałów do pliku
     *
     * @param bool flaga czy zapisywać
     * @param std::string ścierzka do pliku
     */
    void saveSignalsToFile(bool, std::string);

    /**
     * @brief Sygnał emitowany w celu wysłania obiektu o podajen nazwie do klasy symulacji
     *
     * @param std::string
     */
    void setActiveObject(std::string);
    /**
     * @brief Sygnał emitowany w celu pobrania pełnych danych obiektu o danaj nazwie
     *
     * @param std::string
     */
    void getObjectData(std::string);
    /**
     * @brief Sygnał emitowany w celu poprania pełnej listy obiektów zapisanych w konfiguracji
     *
     */
    void getObjectsList();
    /**
     * @brief Sygnał emitowany w celu usunięcia obiektu o podanaj nazwie z konfiguracji
     *
     * @param std::string
     */
    void removeObject(std::string);
    /**
     * @brief Sygnał emitowany w celu zmodyfikowania obiektu o podanaj nazwie w konfiguracji
     *
     * @param std::string
     * @param ObjectData
     */
    void editObject(std::string, ObjectData);


    void getAdjustmentsList();
    /**
     * @brief Sygnał emitowany w celu wysłania regulatora o podajenych parametrach do klasy symulacji
     *
     * @param AdjustmentData dane nastawy
     */
    void setActiveAdjustment(AdjustmentData);
    /**
     * @brief Sygnał emitowany w celu usunięcia zdefiniowanej nastawy z konfiguracji
     *
     * @param std::string typ regulatora
     * @param std::string nazwa nastawy
     */
    void removeAdjustment(std::string, std::string);
    /**
     * @brief Sygnał emitowany w celu zapisaniu nastawy w konfiguracji
     *
     * @param AdjustmentData dane nastawy
     */
    void saveAdjustment(AdjustmentData);


    /**
     * @brief Sygnał emitowany w celu wysłania źródła o podajenych parametrach do klasy symulacji
     *
     * @param std::string typ źródła
     * @param std::map<std::string, double> parametry źródła
     */
    void setActiveSimpleSource(std::string, std::map<std::string, double>);


    /**
     * @brief Sygnał emitowany w celu poprania pełnej listy źródeł zapisanych w konfiguracji
     *
     */
    void getCustomSourcesList();
    /**
     * @brief Sygnał emitowany w celu zmodyfikowania źródła o podanaj nazwie w konfiguracji
     *
     * @param std::string nazwa źródła
     * @param MultiSourceData dane
     */
    void editCustomSource(std::string, MultiSourceData);
    /**
     * @brief Sygnał emitowany w celu usunięcia z konfiguracji źródła o podanej nazwie
     *
     * @param std::string nazwa
     */
    void removeCustomSource(std::string);
    /**
     * @brief Sygnał emitowany w celu poprania szczegółowych informacji o źródle
     *
     * @param std::string nazwa źródła
     */
    void getCustomSourceData(std::string);
    /**
     * @brief Sygnał emitowany w celu wysłania źródła o podajen nazwie do klasy symulacji
     *
     * @param std::string nazwa źródła
     */
    void setActiveCustomSource(std::string);

private slots:
    void simulationStopped(std::string);
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
     * @brief Gniazdo odbierajace sygnal rysowania sterowania
     *
     * @param y wartosc sygnalu
     */
    void drawControl(double y);

    /**
     * @brief Gniazdo odbierajace sygnal z listą obiektów wczytanych z pliku konfiguracyjnego
     *
     * @param std::vector<std::string> waktor z nazwami obiektów
     */
    void retObjectsList(std::vector<std::string>);
    /**
     * @brief Gniazdo odbierajace sygnal z szczegółami o obiekcie
     *
     * @param ObjectData dane obiektu
     */
    void retObjectData(ObjectData);
    /**
     * @brief Gniazdo odbierajace sygnal z nazwą symulowanego obiektu
     *
     * @param std::string nazwa obiektu
     */
    void retActiveObject(std::string);

    /**
     * @brief Gniazdo odbierajace sygnal z listą nastaw odczytanych z pliku konfiguracyjnego
     *
     * @param std::vector<AdjustmentData>
     */
    void retAdjustmentsList(std::vector<AdjustmentData>);
    /**
     * @brief Gniazdo odbierajace sygnal z rodzajem symulowanego reguratora oraz jego nastawami
     *
     * @param std::string typ regulatora
     * @param std::string nastawy
     */
    void retActiveAdjustment(std::string, std::string);

    /**
     * @brief Gniazdo odbierajace sygnal z listą źródeł odczytanych z pliku konfiguracyjnego
     *
     * @param std::vector<std::string> wektor z nazwami zdefiniowanych źródeł
     */
    void retCustomSourcesList(std::vector<std::string>);
    /**
     * @brief Gniazdo odbierajace sygnal z szczegółowymi danymi o źródle
     *
     * @param MultiSourceData
     */
    void retCustomSourceData(MultiSourceData);
    /**
     * @brief Gniazdo odbierajace sygnal z nazwą symulowanego źródła
     *
     * @param std::string
     */
    void retActiveSource(std::string);




    void on_simBtn_clicked();

    void on_resetBtn_clicked();

    void on_samplingSlider_valueChanged(int value);

    void on_contSimRadio_toggled(bool checked);

    void on_stepSimRadio_toggled(bool checked);

    void on_checkBox_feedback_toggled(bool checked);

    void on_actionNew_activated();

    void on_actionOpen_activated();

    void on_actionSave_activated();

    void on_actionSave_As_activated();

    void on_actionExit_activated();

    void on_pushButton_setObject_clicked();

    void on_comboBox_controllerType_currentIndexChanged(const QString &arg1);

    void on_listWidget_adjustments_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_pushButton_setAdjustment_clicked();

    void on_pushButton_removeAdjustment_clicked();

    void on_pushButton_saveAdjustment_clicked();

    void on_pushButton_removeObject_clicked();

    void on_pushButton_editObject_clicked();

    void on_pushButton_newObject_clicked();

    void on_listWidget_simpleSources_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_pushButton_setSimpleSource_clicked();

    void on_pushButton_addCustomSource_clicked();

    void on_pushButton_removeCustomSource_clicked();

    void on_pushButton_editCustomSource_clicked();

    void on_pushButton_setCustomSource_clicked();

    void on_checkBox_saveSignals_toggled(bool checked);

    void on_pushButton_setOutputFile_clicked();

private:
    Ui::MainWindow *ui; /**< UI zawierajace informacje o oknie programu */

    bool isSimulationStarted; /**< Okresla czy symulacja jest aktulanie wykonywana */

    std::vector<AdjustmentData> adjustmentsData; /**< tablica przechowywująca zapisane nastawy */

    /**
     * @brief Funkcja odświerza listę z zdefiniowanymi nastawami
     *
     */
    void updateAdjustmentsList();
    /**
     * @brief Funkcja odświerza stan okntrolek
     *
     */
    void updateButtons();
};

#endif // MAINWINDOW_H
