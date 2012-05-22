#ifndef OBJECTSISO_H
#define OBJECTSISO_H

/**
 * @brief Klasa podstawowa Obiektu SISO
 *
 */
class ObjectSISO{
public:
    /**
     * @brief Konstruktor
     *
     */
    ObjectSISO();
    /**
     * @brief Funkcja odpowiedzialna za jeden krok symulacji
     *
     * @param double Wartosc wejscia
     */
    virtual double simulate(double)=0;
    /**
     * @brief Funkcja zwracająca wartość wyznaczoną w poprzednim wywołaniu funkcji symuluj
     *
     */
    virtual double getLastValue()=0;
    /**
     * @brief funkcja resetujaca obiekt
     *
     */
    virtual void reset(void)=0;
};

#endif // OBIECTSISO_H
