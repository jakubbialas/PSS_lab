#ifndef SOURCEDATA_H
#define SOURCEDATA_H

#include <string>
#include <map>

class SourceData
{
public:
    SourceData();

    void setType(std::string);
    std::string getType();
    void setParameters(std::map<std::string, double>);
    std::map<std::string, double> getParameters();

private:
    std::string type;
    std::map<std::string, double> parameters;

    friend void operator >> (const YAML::Node& node, SourceData &sd);
};

/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z obiektu SourceData do formatu parsera yaml
 *
 * @param emitter format parsera yaml
 * @param ad obiekt z którego dane sa zapisywane
 */
YAML::Emitter& operator << (YAML::Emitter &emitter, const SourceData &sd);
/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z obiektu SourceData do strumienia std::ostream
 *
 * @param stream obiekt std::ostream
 * @param ad obiekt z którego dane sa zapisywane
 */
std::ostream& operator << (std::ostream &stream, const SourceData &sd);
/**
 * @brief nadpisanie operatora strumienia zapisujacego dane z formatu parsera yaml do obiektu SourceData
 *
 * @param node format parsera yaml
 * @param ad obiekt do którego sa zapisywane dane
 */
void operator >> (const YAML::Node& node, SourceData &sd);

#endif // SOURCEDATA_H
