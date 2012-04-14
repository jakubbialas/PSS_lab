#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QTimer>
#include "object/objectsiso.h"
#include "source/source.h"
#include <vector>
#include <fstream>
#include <iostream>

/**
 * @brief Klasa posredniczaca w komunikacji z GUI za pomoca gniazd i sygnalow, jest tez odpowedzialna za symulacje
 *
 */
class Simulation : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor
     *
     * @param parent Rodzic
     */
    explicit Simulation(QObject *parent = 0);

    ~Simulation();
signals:
//signals to draw on plots:
    /**
     * @brief Sygnał emitowany przy rysowaniu wejscia
     *
     * @param y Wartosc wejscia
     */
    void drawInput(double y);
    /**
     * @brief Sygnał emitowany przy rysowaniu wyjscia
     *
     * @param y Wartosc wyjscia
     */
    void drawOutput(double y);
    /**
     * @brief Sygnał emitowany przy wystapieniu bledu(nie zaimplementowane)
     *
     * @param y Wartosc bledu
     */
    void drawError(double y);
    /**
     * @brief Sygnał emitowany prz rysowaniu sygnalu sterujacego
     *
     * @param y Wartosc sygnalu
     */
    void drawControl(double y);
  //settings:
    /**
     * @brief Sygnał emitowany przy ustawianou listy mozliwych do wyboru obiektow
     *
     * @param std::vector<std::string> Lista dostepnych obiektow
     */
    void setObjectsList(std::vector<std::string>);

    /**
     * @brief Sygnał emitowane gdy symulacja zostala z jakiegos powodu zatrzymana
     *
     * @param std::string
     */
    void simulationStopped(std::string);
public slots:

    /**
     * @brief Gniazdo odbierajace sygnal by ustawic nowy czas probkowania wykresu
     *
     * @param int czas probkowania wykresu[ms]
     */
    void setSamplingTime(int);
    /**
     * @brief Gniazdo odbierajace sygnal zamykający bądz otwierający sprzężenie zwrotne
     *
     * @param bool
     */
    void setFeedback(bool);

    /**
     * @brief Gniazdo odbierajace sygnal by rozpoczac symulacje ciagla
     *
     */
    void startSimulation();
    /**
     * @brief Gniazdo odbierajace sygnal by zatrzymac symulacje ciagla
     *
     */
    void stopSimulation();
    /**
     * @brief Gniazdo odbierajace sygnal by zresetowac symulacje
     *
     */
    void resetSimulation();
    /**
     * @brief Gniazdo odbierajace sygnal by ustawic symulacje krokowa
     *
     * @param int Liczba krokow
     */
    void stepSimulation(int);

    /**
     * @brief Gniazdo odbierajace sygnal by wykonac nastepny krok symulacji
     *
     */
    void nextStep();


    /**
     * @brief Gniazdo odbierajace sygnal ustawiający symulowany obiekt
     *
     * @param wskaźnik na obiektSISO w najprostrzej postaci
     */
    void setObject(ObjectSISO*);
    /**
     * @brief Gniazdo odbierajace sygnal ustawiający symulowany regulator
     *
     * @param wskaźnik na obiektSISO w najprostrzej postaci
     */
    void setController(ObjectSISO*);
    /**
     * @brief Gniazdo odbierajace sygnal ustawiający symulowane źródło
     *
     * @param wskaźnik na Źródło w najprostrzej postaci
     */
    void setSource(Source*);

    void saveSignalsToFile(bool, std::string);

public:
    //ObjectSISO* getObject();
    //ObjectSISO* getController();
    //Source* getSource();

private:
    ObjectSISO *object; /**< wskaźnik na symulowany obiekt dyskretny */
    ObjectSISO *controller; /**< wskaxnik na symulowany regulator */
    Source *source; /**< wskaźnik na symulowane źródło */

    QTimer * timer; /**< Timer odpowiedzialny za wygenerowanie kolejnych wartości symulacji */

    int samplingTime; /**< Czas probkowania wykresu */
    bool feedback; /**< sprzężenie zwrotne */

    bool toFile; /**< Save signals to file */
    std::string filePath; /**< File path */

    void openFile();
    void printFile(double, double, double, double);
    void closeFile();

    std::fstream file;
};

#endif // SIMULATION_H
