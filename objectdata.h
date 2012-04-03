#ifndef OBJECTDATA_H
#define OBJECTDATA_H

#include "modeldata.h"
#include <vector>

/**
 * @brief Klasa przechowujaca zbior parametrow obiektu i jego nazwe
 *(zbior poniewaz jesli obiekt jest niestacjonarny to moze miec np. kilka wielomianow A oraz B)
 */
class ObjectData
{
public:

    /**
     * @brief Konstruktor
     *
     */
    ObjectData();
    ObjectData(std::string, std::vector<ModelData>);
    ~ObjectData();

private:
    std::vector<ModelData> models; /**< Vector obiektow ModelData(parametrow obiektu) */
    std::string name; /**< Nazwa obiektu */

public:
    void setName(std::string);
    std::string getName();
    void setModels(std::vector<ModelData>);
    std::vector<ModelData> getModels();

    void addModel(ModelData);
    //void getModel(std::string);

    friend void operator << (std::ofstream &filestream, ObjectData &md );
    friend void operator << (std::ofstream &filestream, std::vector<ObjectData> &md );

};

#endif // OBJECTDATA_H
