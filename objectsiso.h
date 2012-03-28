#ifndef OBJECTSISO_H
#define OBJECTSISO_H

/**
 * @brief Klasa podstawowa Obiektu SISO
 *
 */
class ObjectSISO
{
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
    virtual double Symuluj(double)=0;

};

#endif // OBIECTSISO_H
