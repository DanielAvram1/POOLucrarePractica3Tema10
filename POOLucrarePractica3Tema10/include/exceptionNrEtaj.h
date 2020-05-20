#ifndef EXCEPTIONNRETAJ_H
#define EXCEPTIONNRETAJ_H
#include <exception>
using namespace std;

class exceptionNrEtaj: public exception
{
    public:
    virtual const char* what() const throw();
};

#endif // EXCEPTIONNRETAJ_H
