#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QObject>
#include "tool.h"

#include "controller/adjustmentdata.h"
#include <yaml-cpp/yaml.h>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "object/nonstationarydiscreteobject.h"
#include "controller/controllerp.h"
#include "controller/controllerpid.h"
#include "source/multisource.h"
#include "object/objectdata.h"
#include "object/modeldata.h"
#include <string>


/**
 * @brief Klasa zarządzająca całym programem
 * Klasa jest odpowiedzialna za:
 *  - wczytywanie danych z pliku (zapisane obiekty dyskretne, zapisane nastawy regulatorów, zapisane źródła (te bardziej skomplikowane))
 *  - zapis danych do pliku (jw)
 *
 *  - wysyłanie sygnałów z danymi do gui aplikacji
 *  - odbieranie sygnałów z parametrami obiektów przeznaczonych do symulacji od gui
 *  - konstrukcja obiektów wykorzystywanych do symulacji (źródła, rerulatory, obiekty dyskretne)
 *  - wysyłanie sygnałów z tymi obiektami do obiektu klasy symulacji
 *  - destrukcja niepotrzebnych obiektów
 *
 */
class Configuration : public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Konstruktor
     *
     * @param parent
     */
    explicit Configuration(QObject *parent = 0);
    /**
     * @brief Destruktor
     *
     */
    ~Configuration();

signals:
    /**
     * @brief sygnał z obiektem dyskretnym wysyłany do obiektu klasy symulacji
     *
     * @param wskaźnik na obiektSISO w najprostrzej postaci
     */
    void setObject(ObjectSISO*);
    /**
     * @brief sygnał z regulatorem wysyłany do obiektu klasy symulacji
     *
     * @param wskaźnik na obiektSISO w najprostrzej postaci
     */
    void setController(ObjectSISO*);
    /**
     * @brief sygnał ze źródłem wysyłany do obiektu klasy symulacji
     *
     * @param wskaźnik na Źródło w najprostrzej postaci
     */
    void setSource(Source*);

    /**
     * @brief sygnał z listą zdefiniowanych obiektów dyskretnych (tylko z nazwami tych obiektów) wysyłany do gui
     * przy jakichkolwiek zmianach na liscie obiektów, badz jako odpowiedz na sygnał getObjectsList();
     *
     * @param std::vector<std::string>
     */
    void retObjectsList(std::vector<std::string>);
    /**
     * @brief sygnał z wszystkimi parametrami jednego obiektu dyskretnego wysyłany do gui
     * jako odpowiedz na sygnał getObjectData(nazwa);
     *
     * @param ObjectData
     */
    void retObjectData(ObjectData);
    /**
     * @brief sygnał wysyłany do gui
     * wysyła nazwę obiektu wysłanego do symulacji
     *
     * @param std::string
     */
    void retActiveObject(std::string);

    /**
     * @brief sygnał z lista wszystkich zdefiniowanych nastw wysyłany do gui
     * wysyłane sa nazwy nastaw jak i ich parametry
     * jako odpowiedz na sygnał getAdjustmentsList();
     * badz przy jakiejkolwiek zmianie listy z zdefiniowanymi nastawami
     *
     * @param std::vector<AdjustmentData>
     */
    void retAdjustmentsList(std::vector<AdjustmentData>);
    /**
     * @brief sygnał wysyłany do gui
     * wysyła typ regulatora oraz zmienna tekstowa z wilistowanymi parametrami nastaw
     * wysyłany w momencie wysłania nowego regulatora do klasy symulacji
     *
     * @param std::string
     * @param std::string
     */
    void retActiveAdjustment(std::string, std::string);

public slots:
    /**
     * @brief tworzy pustą konfigurację
     *
     */
    void newConfig();
    /**
     * @brief otwiera istniejaca konfigurację
     *
     * @param std::string scierzka do pliku
     */
    void openConfig(std::string);
    /**
     * @brief zapisuje kofigurację
     *
     * @param std::string scierzka do pliku
     */
    void saveConfig(std::string);

    /**
     * @brief zwraca sygnał z lista obiektow
     *
     */
    void getObjectsList();
    /**
     * @brief zwraca sygnał z danymi obiektu o nazwie
     *
     * @param std::string nazwa
     */
    void getObjectData(std::string);
    /**
     * @brief edytuje zapisuje obiekt o nazwie i parametrach (zapisuje nowy, badz nadpisuje istniejacy obiekt)
     *
     * @param std::string nazwa
     * @param ObjectData parametry
     */
    void editObject(std::string, ObjectData);
    /**
     * @brief usówa obiekt o nazwie
     *
     * @param std::string nazwa
     */
    void removeObject(std::string);
    /**
     * @brief wysyła obiekt o podanej nazwie do klasy symulacji
     *
     * @param std::string nazwa
     */
    void setActiveObject(std::string);

    /**
     * @brief zwraca sygnał z lista nastaw
     *
     */
    void getAdjustmentsList();
    /**
     * @brief usówa nastawe o typie i nazwie
     *
     * @param std::string typ regulatora
     * @param std::string nazwa nastawy
     */
    void removeAdjustment(std::string, std::string);
    /**
     * @brief zapisuje nastawe (bądz nadpisuje jesli istnieje)
     *
     * @param AdjustmentData parametry nastawy
     */
    void saveAdjustment(AdjustmentData);
    /**
     * @brief wysyła regulator o podanej nastawie do klasy symulacji
     *
     * @param AdjustmentData
     */
    void setActiveAdjustment(AdjustmentData);

    /**
     * @brief wysyła proste źródło według zadanych parametrów i wysyła do klasy symulacji
     *
     * @param std::string typ źródła (np. "step", "noise"...)
     * @param std::map<std::string, double> parametry źródła
     */
    void setActiveSimpleSource(std::string, std::map<std::string, double>);

private:
    /**
     * @brief funkcja zwraca vektor z nazwami zapisanych obiektów
     *
     */
    std::vector<std::string> getObjectsKeys();
    /**
     * @brief funkcja zwraca zapisane nastawy
     *
     */
    std::vector<AdjustmentData> getAdjustments();
    /**
     * @brief funkcja zwraca iterator na nastawe o danej nazwie dla regulatora o zadanym typie
     * w przypadku braku szukanaj nastawy zwraca iterator wskazujacy na koniec wektora nastaw
     *
     * @param std::string typ regulatora
     * @param std::string nazwa nastawy
     */
    std::vector<AdjustmentData>::iterator findAdjustment(std::string, std::string);

private:
    std::map<std::string, ObjectData> objects; /**< Mapa zawierajaca obiekty gdzie kluczem sa ich nazwy */
    std::vector<AdjustmentData> adjustments; /**< vektor przechowujacy zdefiniowane nastawy */
    //std::map<std::string, MultiSourceData> sources; /**< TODO mapa z zdefiniowanymi źródłami */

    std::string filename; /**< scierzka do aktualnie wszytanego pliku (wykrzystywana przy funkcji saveConfig() */

    std::string currentControllerType; /**< Typ wykorzystywanego regulatora (aby nie tworzyć nopwego regulatora gdy zmieniaja sie tylko jego nastawy) */
    Controller *controller; /**< wskaźnik na wykorzystywany regulator */
    NonStationaryDiscreteObject *object; /**< wskaźnik na wykorzystywany obiekt */
    Source *source; /**< wskaźnik na wykorzystywane źródło */
};

#endif // CONFIGURATION_H
