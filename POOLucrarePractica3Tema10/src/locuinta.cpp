#include "locuinta.h"
using namespace std;

int locuinta::nr_locuinte = 0;

int locuinta::get_nr_locuinte(){
    return nr_locuinte;
}

locuinta::locuinta(){
    locuinta::nr_locuinte++;
    nume_client = "";
    suprafata = 0;
    pret_chirie = 0;
    discount = 0;
}
locuinta::locuinta(string n, double s, double pr, short int dis)
    :nume_client(n), suprafata(s), pret_chirie(pr), discount(dis)
{
    locuinta::nr_locuinte++;
}
locuinta::locuinta(const locuinta& other)
    :nume_client(other.nume_client), suprafata(other.suprafata), pret_chirie(other.pret_chirie), discount(other.discount)
{
    locuinta::nr_locuinte++;
}

const string locuinta::getNume_client() const{
    return nume_client;
}
const double locuinta::getSuprafata() const{
    return suprafata;
}
const short int locuinta::getDiscount() const{
    return discount;
}

double const locuinta::getPret_chirie() const{
    return pret_chirie;
}



istream& operator >> (istream& in, locuinta& ob){
        cout << "nume client: ";
        in >> ob.nume_client;
        cout << "pret chirie: ";
        in >> ob.pret_chirie;
        cout << "discount: ";
        in >> ob.discount;
        return in;
}
ostream& operator << (ostream& out, locuinta& ob){
    out<<"\tNume chirias: " << ob.nume_client << '\n';
    out<<"\tSuprafata: " << ob.getSuprafata() << '\n';
    out<<"\tPret chirie: " << ob.pret_chirie << '\n';
    out<<"\tDiscount: " << ob.discount << '\n';
    return out;
}

locuinta::~locuinta(){
    locuinta::nr_locuinte--;
}

locuinta& locuinta::operator = (const locuinta& other){
    nume_client = other.nume_client;
    suprafata = other.suprafata;
    pret_chirie = other.pret_chirie;
    discount = other.discount;
    return *this;
}

