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
    std::vector<ModelData> models; /**< Vector obiektow ModelData(parametrow obiektu) */

    std::string name; /**< Nazwa obiektu */
};

#endif // OBJECTDATA_H
