#ifndef PSS_DISCRETEOBJECT_EXCEPTIONS_H
#define PSS_DISCRETEOBJECT_EXCEPTIONS_H

#include "pss_exception.h"

class PSSDiscreteObjectParameterNotSetException : public PSSException
{
public:
    virtual const char * what() const throw()
    {
        return "Parameter not set";
    }
};

class PSSDiscreteObjectUnknownParameterException : public PSSException
{
public:
    virtual const char * what() const throw()
    {
        return "Uknown parameter";
    }
};

class PSSDiscreteObjectSorceNotDefinedException : public PSSException
{
public:
    virtual const char * what() const throw()
    {
        return "Source not defined";
    }
};

#endif // PSS_DISCRETEOBJECT_EXCEPTIONS_H
