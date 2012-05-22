#ifndef PSS_EXCEPTION_H
#define PSS_EXCEPTION_H

class PSSException : public std::exception
{
public:
    virtual const char * what() const throw()
    {
        return "Default pss project exception";
    }
};

#endif // PSS_EXCEPTION_H
