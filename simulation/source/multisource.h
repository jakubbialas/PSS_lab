#ifndef MULTISOURCE_H
#define MULTISOURCE_H

#include "source.h"

#include "stepsource.h"
#include "impulssource.h"
#include "trianglesource.h"
#include "sinussource.h"
#include "noisesource.h"
#include "squaresource.h"
#include "sourcedata.h"

#include <vector>

/**
 * @brief Klasa MultiSource pozwala na sumowanie wybranych źródeł prostych
 *
 */
class MultiSource : public Source
{
public:
    /**
     * @brief Konstruktor
     *
     */
    MultiSource();
    /**
     * @brief Konstruktor
     *
     */
    MultiSource(std::vector<SourceData>);
    /**
     * @brief Destruktor
     *
     */
    ~MultiSource();

    /**
     * @brief nieuzywana funkcjia...
     *
     * @param std::string
     * @param double
     */
    void setParameter(std::string, double);
    /**
     * @brief funkcja zwraca sygnał wyjsciowy
     *
     */
    double getSample();

private:
    /**
     * @brief funkcja tworzy źródło określonego typu i je zwraca
     *
     * @param type
     */
    Source* createSource(std::string type);

    std::vector<Source*> sources; /**< vektor źródeł podstawowych */
};

#endif // MULTISOURCE_H
