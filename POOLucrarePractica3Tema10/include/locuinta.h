#ifndef LOCUINTA_H
#define LOCUINTA_H
#include<string>
#include<iostream>
using namespace std;

class locuinta
{
private:
    static int nr_locuinte;
protected:
    string nume_client;
    double suprafata;
    double pret_chirie;
    short int discount;

    locuinta();
    locuinta(string, double, double, short int);
    locuinta(const locuinta&);


    template<class T>
    void afisare(T info){
        cout<<info<<'\n';
    };

    friend istream& operator >> (istream&, locuinta&);
    friend ostream& operator << (ostream&, locuinta&);

    locuinta& operator = (const locuinta&);

    const string getNume_client() const;
    virtual const double getSuprafata() const;
    const short int getDiscount() const;
    const double getPret_chirie()const;


public:
    virtual const double calcul_chirie() = 0;
    virtual void afisare_informatie() = 0;
    static int get_nr_locuinte();
    ~locuinta();

};

#endif // LOCUINTA_H
