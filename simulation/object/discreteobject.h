#ifndef DISCRETEOBJECT_H
#define DISCRETEOBJECT_H

#include "objectsiso.h"
#include "modeldata.h"
#include <cstdlib>
#include <numeric>
#include "exceptions/pss_discreteobject_exceptions.h"


/**
 * @brief Klasa dziedziczaca po ObjectSISO, implementuje obiekt typu ARX
 *
 */
class DiscreteObject : public ObjectSISO
{
private:
    std::vector<double> B; /** wielomian B */
    std::vector<double> A; /** wielomian A */
    int k;                 /** opoznienie wejscia */
    double noiseRatio;     /** współczynnik szumu */

protected:
    std::deque<double> U;  /** kolejka wymuszeń */
    std::deque<double> Y;  /** kolejka stanu (poprzednie wartości) */
    int counter;           /** aktualny numer próbki */

public:
    /**
     * @brief Konstruktor domyślny, parametry obiektu nie sa ustawione
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
     * @param vector<double> B Wielomian B
     * @param vector<double> A Wielomian A
     * @param unsigned int k Opóźnienie obiektu
     * @param double noiseRatio Współczynnik szumu domyślnie 0
     */
    DiscreteObject(std::vector<double> B, std::vector<double> A, unsigned int k, double noiseRatio);

    /**
     * @brief Konstruktor tworzący obiekt
     *
     * @param ModelData md obiekt zawierający parametry obiektu
     */
    DiscreteObject(ModelData md);

    /**
     * @brief Ustawia parametry obiektu
     *
     * @param ModelData md obiekt zawierający parametry obiektu
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
     * @param vector<double> B Wielomian B
     * @param vector<double> A Wielomian A
     * @param unsigned int k Opóźnienie obiektu
     */
    void setParameters(std::vector<double> B, std::vector<double> A, unsigned int k);

    /**
     * @brief Ustawia wielomiany B i A, oraz parametr k
     *
     * @param vector<double> B Wielomian B
     * @param vector<double> A Wielomian A
     * @param unsigned int k Opóźnienie obiektu
     * @param double noiseRatio Współczynnik szumu
     */
    void setParameters(std::vector<double> B, std::vector<double> A, unsigned int k, double noiseRatio);

    /**
     * @brief Zwraca wielomian B
     *
     */
    std::vector<double> getB();

    /**
     * @brief Zwraca wielomian A
     *
     */
    std::vector<double> getA();

    /**
     * @brief Zwraca opóźnienie obiektu
     *
     */
    unsigned int getk();

    /**
     * @brief Zwraca współczynnik szumu
     *
     */
    double getNoiseRatio();

    /**
     * @brief Resetuje obiekt i jego wielomiany, ustawia probke czasu na 0
     *
     */
    void reset();

    /**
     * @brief Symuluje kolejną iterację obiektu
     *
     * @param double input Wartosc wejscia
     *
     * @return double wartość wyjściowa
     */
    double simulate(double input);

    /**
     * @brief Zwraca wartość wyjściową obiektu wyznaczaną po ostatnim wywołaniu funkcji simulate
     *
     */
    double getLastValue();

    /**
     * @brief Funkcja ustawia współczynnik szumu obiektu
     *
     * @param double
     */
    void setNoiseRatio(double);

    /**
     * @brief Funkcja ustawia wektor wymuszeń obiektu
     *
     */
    void setU(std::deque<double>);

    /**
     * @brief Funkcja ustawia wektor stanu obiektu
     *
     */
    void setY(std::deque<double>);
};

#endif // DISCRETEOBJECT_H
