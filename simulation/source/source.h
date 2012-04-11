#ifndef SOURCE_H
#define SOURCE_H

#include <string>

/**
 * @brief Podstawowa klasa źródła sygnału dyskretnego
 *
 */
class Source
{
public:
    /**
     * @brief Konstruktor
     *
     */
    Source();

    /**
     * @brief Funkcja ustawiająca parametr źródła
     *
     * @param std::string nazwa parametru
     * @param double wartość parametru
     */
    virtual void setParameter(std::string, double)=0;
    /**
     * @brief funkcja zwracająca wartość sygnału źródłowego
     *
     */
    virtual double getSample()=0;

    /**
     * @brief funkcja inkrementujaca czas i zwracająca wartość sygnału źródłowego
     *
     */
    double getNextSample();

    /**
     * @brief funkcja resetujaca żródło
     *
     */
    void reset();

    /**
     * @brief funkcja zwracająca czas
     *
     */
    int getTime();

    /**
     * @brief funkcja inkrementujaca czas
     *
     */
    int incrementTime();

    /**
     * @brief funkcja ustawiajaca czas na zadana wartosc
     *
     * @param int
     */
    void setTime(int);

private:
    int time; /**< Aktualna probka czasu */

};

#endif // SOURCE_H
