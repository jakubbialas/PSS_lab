#ifndef COERCE_H
#define COERCE_H

/**
 * @brief Klasa odpowiedzialnia za dobor wymuszenia
 *
 */
class Coerce
{
public:
    /**
     * @brief Typ enum określający możliwe typy wymuszenia
     *STEP - skok jednostkowy
     *IMP - impuls
     *NONE - wymuszenie zerowe
     *CUSTOM - wymuszenie dobrane ręcznie jako parametr
     */
    enum CoercionType { STEP, IMP, NONE, CUSTOM };

/**
 * @brief Konstruktor bezparametrowy klasy Coerce
 *
 */
    Coerce();
/**
 * @brief Ustaw typ aktualnego wymuszenia
 *
 * @param n_Type Typ wymuszenia
 */
    Coerce(CoercionType n_Type);
    /**
     * @brief
     *
     * @param CoercionType typ wymuszenia
     */
    void setCoercionType(CoercionType);
    /**
     * @brief Dla typu wymuszenia custom ustala wartosc wymuszenia
     *
     * @param double Wartosc wymuszenia
     */
    void setCoercionValue(double);
    /**
     * @brief resetuj czas wymuszenia(głownie gdy wymuszeniem jest impuls, by jedynka pojawila sie ponownie)
     *
     */
    void reset();
    /**
     * @brief Podaje kolejna wartosc wymuszenia
     *
     */
    double nextSample();

private:
    CoercionType type; /**< Zmienna przechowujaca aktualny typ wymuszenia */
    double value; /**< Wartosc wymuszenia dla sterowania CUSTOM */
    int time; /**< Aktualna probka czasu */
};

#endif // COERCE_H
