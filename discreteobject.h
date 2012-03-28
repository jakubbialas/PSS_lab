#ifndef DISCRETEOBJECT_H
#define DISCRETEOBJECT_H

#include "objectsiso.h"

#include <vector>
#include <deque>
#include <iostream>
#include <cstdlib>
#include <numeric>
#include "objectdata.h"

using namespace std;

/**
 * @brief Klasa dziedziczaca po ObjectSISO, implementuje obiekt typu ARX
 *
 */
class DiscreteObject : public ObjectSISO
{
private:
    vector<double> A; /**< wielomian A - ten na dole... */
    vector<double> B; /**< /wielomian B - ten na gorze */
    deque<double> U;  /**< kolejka wymuszeń */
    deque<double> Y;  /**< kolejka stanu (poprzednie wartości) */
    int k;            /**< opoznienie wejscia */

    ObjectData data;  /**< TODO */
    int counter;      /**< aktualny numer próbki */

    /**
     * @brief Ustawia aktualne parametry(A,B,k) dla obiektu, obsluguje takze niestacjonarnosc
     *
     */
    void updateModel();

public:
/**
 * @brief Konstruktor bez parametrowy, parametry obiektu nie sa ustawione
 *
 */
    DiscreteObject();
/**
 * @brief Konstruktor tworzacy obiekt
 *
 * @param ObjectData Wprowadzany obiekt
 */
    DiscreteObject(ObjectData);
/**
 * @brief Konstruktor tworzący obiekt
 *
 * @param vector<double> Wielomian A
 * @param vector<double> Wielomian B
 * @param int Parametr k
 */
    DiscreteObject(vector<double>, vector<double>, int);

    /**
     * @brief Ustawia wielomiany A i B, oraz parametr k
     *
     * @param vector<double> Wielomian A
     * @param vector<double> Wielomian B
     * @param int Parametr k
     */
    void setBAk(vector<double>, vector<double>, int);
    /**
     * @brief Ustawia aktualny obiekt, zeruje czas
     *
     * @param ObjectData
     */
    void setData(ObjectData);
    /**
     * @brief Resetuje obiekt i jego wielomiany, ustawia probke czasu na 0
     *
     */
    void reset();

    /**
     * @brief Zwraca vector B
     *
     */
    vector<double> getB();
    /**
     * @brief Zwraca vector A
     *
     */
    vector<double> getA();
    /**
     * @brief Zwraca parametr k
     *
     */
    int getk();

    /**
     * @brief Okresla wartosc wyjsciowa symulowanego obiektu
     *
     * @param double Wartosc wejscia
     */
    double Symuluj(double);

};

#endif // DISCRETEOBJECT_H
