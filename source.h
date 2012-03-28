#ifndef SOURCE_H
#define SOURCE_H

/**
 * @brief Klasa odpowiedzialnia za dobor wymuszenia
 *
 */
class Source
{
public:
    /**
     * @brief Typ enum określający możliwe typy wymuszenia
     *STEP - skok jednostkowy
     *IMP - impuls
     *NONE - wymuszenie zerowe
     *CUSTOM - wymuszenie dobrane ręcznie jako parametr
     */
    enum SourceType { STEP, IMP, NONE, CUSTOM };

    /**
     * @brief Konstruktor bezparametrowy klasy Coerce
     *
     */
    Source();
    /**
     * @brief Ustaw typ aktualnego wymuszenia
     *
     * @param n_Type Typ wymuszenia
    */
    Source(SourceType n_Type);
    /**
     * @brief
     *
     * @param SourceType typ wymuszenia
     */
    void setSourceType(SourceType);
    /**
     * @brief Dla typu wymuszenia custom ustala wartosc wymuszenia
     *
     * @param double Wartosc wymuszenia
     */
    void setSourceValue(double);
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
    SourceType type; /**< Zmienna przechowujaca aktualny typ wymuszenia */
    double value; /**< Wartosc wymuszenia dla sterowania CUSTOM */
    int time; /**< Aktualna probka czasu */
};

#endif // SOURCE_H
