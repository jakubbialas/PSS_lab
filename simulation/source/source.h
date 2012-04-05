#ifndef SOURCE_H
#define SOURCE_H

#include <string>

class Source
{
public:
    Source();

    virtual void setParameter(std::string, double)=0;
    virtual double getSample()=0;

    double getNextSample();
    void reset();

    int getTime();
    int incrementTime();
    void setTime(int);

private:
    int time; /**< Aktualna probka czasu */

};

#endif // SOURCE_H
