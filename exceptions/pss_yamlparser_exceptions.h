#ifndef PSS_YAMLPARSER_EXCEPTIONS_H
#define PSS_YAMLPARSER_EXCEPTIONS_H

#include "pss_exception.h"

class PSSYAMLParserParameterNotFoundException : public PSSException
{
public:
    virtual const char * what() const throw()
    {
        return "Parameter not found";
    }
};


#endif // PSS_YAMLPARSER_EXCEPTIONS_H
