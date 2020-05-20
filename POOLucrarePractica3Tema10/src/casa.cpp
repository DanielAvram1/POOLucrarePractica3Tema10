#include "casa.h"
#include "locuinta.h"
#include<iostream>
#include "exceptionNrEtaj.h"
using namespace std;

int casa::nr_case = 0;

casa::casa()
    :locuinta(), suprafata_curte(0), pret_curte(0), nr_etaje(0)
{
    casa::nr_case++;
    suprafata_curte = 0;
    nr_etaje = 0;
    suprafata_etaj = new double[nr_etaje + 1];
    suprafata_etaj[0] = 0;

}

casa::casa(string n, double s_par, double pr, short int dis, double s_c, double pr_c, int nr_e)
    : locuinta(n,s_par, pr,dis), suprafata_curte(s_c), pret_curte(pr_c)
{
    exceptionNrEtaj ex;
    try{
        if(nr_e < 0)
            throw ex;
        nr_etaje = nr_e + 1;
    }
    catch(...){
        cout << ex.what();
        nr_etaje = 1;
    }
    casa::nr_case++;
    suprafata_etaj = new double[nr_etaje];
    suprafata_etaj[0] = s_par;
    for(int i = 1;i < nr_etaje; i++)
        suprafata_etaj[i] = 0;
}
casa::casa(const casa& other)
    : locuinta(other), suprafata_curte(other.suprafata_curte), nr_etaje(other.nr_etaje)
{
    casa::nr_case++;
    if(suprafata_etaj == other.suprafata_etaj){   ///copiere de acelasi obiect
        return;
    }

    delete[] suprafata_etaj;
    suprafata_etaj = new double[nr_etaje + 1];
    for(int i = 0;i<nr_etaje;i++)
        suprafata_etaj[i] = other.suprafata_etaj[i];

}

casa::~casa(){
    casa::nr_case--;
    delete[] suprafata_etaj;
}

int casa::get_nr_case(){
    return casa::nr_case;
}

void casa::afisare_informatie(){
    cout<<"Casa:\n";
    cout<<"\tNume chirias: "; afisare(nume_client);
    cout<<"\tSuprafata: "; afisare( suprafata);
    cout<<"\tPret chirie: "; afisare(pret_chirie);
    cout<<"\tDiscount: "; afisare( discount);
    cout<<'\n';
    cout<<"\tSuprafata curte: "; afisare(suprafata_curte);
    cout<<"\tPret curte: "; afisare(pret_curte);
    cout<<"\tNumarul de etaje: "; afisare(nr_etaje);
    cout<<"\tSuprafata etajelor: ";
    for(int i = 0;i<=nr_etaje;i++)
        cout<<suprafata_etaj[i]<<' ';
    cout<<'\n';
    cout<<'\n';


}

const double casa::calcul_chirie(){
    return suprafata*pret_chirie*(1 + discount) + suprafata_curte*pret_curte;
}




const double casa::getSuprafata_curte() const{
    return suprafata_curte;
}
const int casa::getNr_etaje() const{
    return nr_etaje;
}
const double* casa::getSuprafata_etaj() const{
    return suprafata_etaj;
}

const double casa::getEtaj(int i) const{
    return suprafata_etaj[i];
}

double& casa::operator[](int index){
    return suprafata_etaj[index];
}

void casa::setEtaj(int i, const double& val){
    suprafata -= suprafata_etaj[i];
    suprafata_etaj[i] = val;
    suprafata += val;
}

const double casa::getSuprafata(){
    double rezultat = 0;
    for(int i = 0;i<nr_etaje;i++)
        rezultat += suprafata_etaj[i];
    return rezultat;
}

casa& casa::operator = (const casa& other){
    if(suprafata_etaj == other.suprafata_etaj)
        return *this;
    nume_client = other.nume_client;
    suprafata = other.suprafata;
    pret_chirie = other.pret_chirie;
    discount = other.discount;
    suprafata_curte = other.suprafata_curte;
    pret_curte = other.pret_chirie;
    nr_etaje = other.nr_etaje;
    suprafata_etaj = new double[nr_etaje + 1];
    for(int i = 0; i <= nr_etaje; i++) {
        suprafata_etaj[i] = other.suprafata_etaj[i];
    }
    return *this;
}

istream& operator >> (istream& in, casa& ob){
    in >> *(static_cast<locuinta*>(&ob));
    cout << "suprafata parter: ";
    in >> ob.suprafata;
    cout << "curte: ";
    in >> ob.suprafata_curte;
    cout << "pret curte: ";
    in >> ob.pret_curte;
    cout << "nretaje: ";
    in >> ob.nr_etaje;
    delete[] ob.suprafata_etaj;
    if(ob.nr_etaje < 0) ob.nr_etaje = 0;
    ob.suprafata_etaj = new double[ob.nr_etaje+1];
    ob[0] = ob.suprafata;
    for(int i = 1; i <= ob.nr_etaje; i++){
        cout<< "suprafata etajului "<<i<<": ";
        in >> ob.suprafata_etaj[i];
    }
    return in;

}

ostream& operator << (ostream& out, casa& ob){
    out<< "Casa:\n";
    out << *(static_cast<locuinta*>(&ob));
    out <<"\tNr de etaje: " << ob.nr_etaje << '\n';
    out << "\tSuprafata etajelor: ";
    for(int i = 0;i <= ob.nr_etaje; i++){
        out << ob.suprafata_etaj[i] << ' ';
    }
    out << '\n';
    return out;
}
