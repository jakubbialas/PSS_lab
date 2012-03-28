#ifndef SIMULATION_H
#define SIMULATION_H

#include <QObject>
#include <QTimer>
#include "discreteobject.h"
#include "coerce.h"
#include "yamlconfigparser.h"

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
     * @brief Gniazdo odbierajace sygnal  by ustawic typ wymuszenia
     *
     * @param Coerce::CoercionType Typ wymuszenia
     */
    void setCoercionType(Coerce::CoercionType);
    /**
     * @brief Gniazdo odbierajace sygnal by ustawic wartosc wymuszenia
     *
     * @param double Wartosc wymuszenia
     */
    void setCoercionValue(double);
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

    YamlConfigParser ymp; /**< Parser plikow Yaml */

    DiscreteObject object; /**< Symulowany obiekt  */
    Coerce coerce; /**< Obiekt odpowiedzialny za wymuszenie */

    int samplingTime; /**< Czas probkowania wykresu */
};

#endif // SIMULATION_H
