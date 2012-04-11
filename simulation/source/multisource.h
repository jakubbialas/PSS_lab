#ifndef MULTISOURCE_H
#define MULTISOURCE_H

#include "source.h"

#include "stepsource.h"
#include "impulssource.h"
#include "trianglesource.h"
#include "sinussource.h"
#include "noisesource.h"
#include "squaresource.h"

#include <vector>

/**
 * @brief Klasa MultiSource pozwala na sumowanie wybranych źródeł prostych
 * TODO: Klasa jest prawdopodobnie do przeróbki!!
 *
 */
class MultiSource : public Source
{
public:
/**
 * @brief
 *
 */
    MultiSource();

    /**
     * @brief
     *
     * @param std::string
     * @param double
     */
    void setParameter(std::string, double);
    /**
     * @brief
     *
     */
    double getSample();

    /**
     * @brief
     *
     * @param std::string
     */
    void addSource(std::string);
    /**
     * @brief
     *
     */
    void removeLastSource();
    /**
     * @brief
     *
     * @param std::string
     * @param double
     */
    void setLastSourceParameter(std::string, double);

private:
    std::vector<Source*> sources; /**< TODO */
};

#endif // MULTISOURCE_H
