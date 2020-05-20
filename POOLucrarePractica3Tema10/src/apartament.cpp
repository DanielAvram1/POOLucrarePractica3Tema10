#include "apartament.h"
#include "locuinta.h"
#include "exceptionNrEtaj.h"
#include<iostream>
using namespace std;

int apartament::nr_apartamente = 0;

int apartament::get_nr_apartamente() {
    return apartament::nr_apartamente;
}

apartament::apartament()
    :locuinta(), etaj(0)
{
    nr_apartamente++;
}

apartament::apartament(string _nume_client,double _suprafata,double _pret_chirie, short int _discount, int _etaj)
    :locuinta(_nume_client, _suprafata, _pret_chirie, _discount)
{
    exceptionNrEtaj ex;
    try{

        if(_etaj < 0)
            throw ex;
        etaj = _etaj;
    }
    catch(...){
        cout << ex.what();
        etaj = 0;
    }
    nr_apartamente++;
}

apartament::apartament(const apartament& other)
    :locuinta(other), etaj(other.etaj)
{
    nr_apartamente++;
}

apartament::~apartament(){
    nr_apartamente--;
}

const int apartament::getEtaj() const{
    return etaj;
}

void apartament::setEtaj(int i){
    etaj = i;
}

const double apartament::calcul_chirie(){
    return pret_chirie*suprafata*(1 + discount/100);
}

const double apartament::getSuprafata() {
    return suprafata;
}


void apartament::afisare_informatie(){
    cout<<"Apartament:\n";
    cout<<"\tNume chirias: "; afisare(nume_client);
    cout<<"\tSuprafata: "; afisare( suprafata);
    cout<<"\tPret chirie: "; afisare(pret_chirie);
    cout<<"\tDiscount: "; afisare( discount);
    cout<<'\n';
    cout<<"\tEtajul: "; afisare(etaj);
    cout<<'\n';

}



istream& operator >> (istream& in, apartament& ob){
    in >> *(static_cast<locuinta*>(&ob));
    cout << "suprafata: ";
    in >> ob.suprafata;
    cout << "etajul: ";
    in >> ob.etaj;
    return in;
}
ostream& operator << (ostream& out, apartament& ob){
    out << "Apartament:\n";
    out << *(static_cast<locuinta*>(&ob));
    out << "\tEtajul: " << ob.etaj << '\n';
    return out;
}

apartament& apartament::operator = (const apartament& other){
    nume_client = other.nume_client;
    suprafata = other.suprafata;
    pret_chirie = other.pret_chirie;
    discount = other.discount;
    etaj = other.etaj;
    return *this;
}
