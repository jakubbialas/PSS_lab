#ifndef DISCRETEOBJECT_H
#define DISCRETEOBJECT_H

#include "objectsiso.h"
#include "modeldata.h"
#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <numeric>

/**
 * @brief Klasa dziedziczaca po ObjectSISO, implementuje obiekt typu ARX
 *
 */
class DiscreteObject : public ObjectSISO
{
private:
    std::vector<double> B; /** wielomian B - ten na gorze */
    std::vector<double> A; /** wielomian A - ten na dole... */
    int k;                 /** opoznienie wejscia */
    std::deque<double> U;  /** kolejka wymuszeń */
    std::deque<double> Y;  /** kolejka stanu (poprzednie wartości) */
protected:
    int counter;           /** aktualny numer próbki */

public:
    /**
     * @brief Konstruktor bez parametrowy, parametry obiektu nie sa ustawione
     *
     */
    DiscreteObject();

    /**
     * @brief Destruktor
     *
     */
    ~DiscreteObject();

    /**
     * @brief Konstruktor tworzący obiekt
     *
     * @param vector<double> Wielomian B
     * @param vector<double> Wielomian A
     * @param int Parametr k
     */
    DiscreteObject(std::vector<double>, std::vector<double>, int);

    /**
     * @brief Konstruktor tworzący obiekt
     *
     * @param ModelData parametry obiektu
     */
    DiscreteObject(ModelData);

    /**
     * @brief Ustawia wielomiany B i A, oraz parametr k
     *
     * @param ModelData
     */
    void setModel(ModelData);

    /**
     * @brief Zwraca ModelData Objektu
     *
     */
    ModelData getModel();

    /**
     * @brief Ustawia wielomiany B i A, oraz parametr k
     *
     * @param vector<double> Wielomian B
     * @param vector<double> Wielomian A
     * @param int Parametr k
     */
    void setBAk(std::vector<double>, std::vector<double>, int);

    /**
     * @brief Zwraca vector B
     *
     */
    std::vector<double> getB();

    /**
     * @brief Zwraca vector A
     *
     */
    std::vector<double> getA();

    /**
     * @brief Zwraca parametr k
     *
     */
    int getk();

    /**
     * @brief Resetuje obiekt i jego wielomiany, ustawia probke czasu na 0
     *
     */
    void reset();

    /**
     * @brief Okresla wartosc wyjsciowa symulowanego obiektu
     *
     * @param double Wartosc wejscia
     */
    double simulate(double);

    /**
     * @brief Zwraca wartość wyjściową obiektu wyznaczaną po ostatnim wywołaniu funkcji simulate
     *
     */
    double getLastValue();

};

#endif // DISCRETEOBJECT_H
