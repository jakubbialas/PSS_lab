#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QTimer>
#include "object/nonstationarydiscreteobject.h"
#include "controller/controller.h"
#include "controller/controllerp.h"
#include "source/source.h"
#include "source/multisource.h"
#include "configuration.h"

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

public slots:
//slots to set config:
    /**
     * @brief Gniazdo odbierajace sygnal by zaladowac liste plikow
     *
     * @param filename Nazwa pliku
     */
    void loadConfig(const char * filename);
    /**
     * @brief Gniazdo odbierajace sygnal by ustawic nowy czas probkowania wykresu
     *
     * @param int czas probkowania wykresu[ms]
     */
    void setSamplingTime(int);
    /**
     * @brief Gniazdo odbierajace sygnal by ustawic nowy obiekt
     *
     * @param std::string Nazwa obiektu
     */
    void setObject(std::string);

    void addSource(std::string type);
    void setLastSourceParameter(std::string name, double value);
    void removeLastSource();

    void setControllerType(std::string);
    void setControllerParameter(std::string, double);

    void setFeedback(bool);

//slots to simulate:
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

private:
    QTimer * timer; /**< Timer generujacy nowe punkty na wykresie co okreslony czas probkowania */

    Configuration ymp; /**< Parser plikow Yaml */

    NonStationaryDiscreteObject *object; /**< Symulowany obiekt  */
    Controller *controller;
    MultiSource *source; /**< Obiekt odpowiedzialny za wymuszenie */

    int samplingTime; /**< Czas probkowania wykresu */
    bool feedback;
};

#endif // SIMULATION_H
