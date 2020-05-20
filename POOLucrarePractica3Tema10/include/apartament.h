#ifndef APARTAMENT_H
#define APARTAMENT_H

#include "locuinta.h"
using namespace std;

class apartament:public locuinta
{
private:
    int etaj;
    static int nr_apartamente;
protected:
public:

    static int get_nr_apartamente();

    apartament();
    apartament(string, double,double, short int , int);
    apartament(const apartament&);
    ~apartament();

    const int getEtaj() const;
    void setEtaj(int);
    virtual const double getSuprafata();
    virtual const double calcul_chirie();
    virtual void afisare_informatie();

    apartament& operator = (const apartament&);

    friend istream& operator >> (istream&, apartament&);
    friend ostream& operator << (ostream&, apartament&);

};

#endif // APARTAMENT_H
