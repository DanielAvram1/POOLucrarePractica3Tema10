#ifndef CASA_H
#define CASA_H
#include "locuinta.h"

class casa:public locuinta
{
private:
    double suprafata_curte;
    double pret_curte;
    int nr_etaje;
    double *suprafata_etaj;
    static int nr_case;
protected:
public:

    static int get_nr_case();

    casa();
    casa(string, double, double, short int, double,double , int);
    casa(const casa&);
    //casa(int);
    ~casa();

    const double getSuprafata_curte() const;
    const int getNr_etaje() const;
    const double* getSuprafata_etaj() const;
    void setEtaj(int, const double&);

    const double getEtaj(int) const;
    double& operator[](int);
    casa& operator = (const casa&);

    friend istream& operator >> (istream&, casa&);
    friend ostream& operator << (ostream&, casa&);

    virtual const double getSuprafata();
    virtual void afisare_informatie();
    virtual const double calcul_chirie();
};
#endif // CASA_H
