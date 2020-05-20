#include <iostream>
using namespace std;
#include "apartament.h"
#include "casa.h"
#include "gestiune.h"
#include <set>
#include <utility>
#include <string>

int main(){

   /// apartament a("aasd", 12,21,12,2);
   /// casa c("sad", 12,12,12,12,12,-4);
    set< pair <locuinta*, string > > str;
    gestiune<casa> gest;

    cout << "Introduceti numarul de locuinte: ";
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cout <<"Introduceti tipul (apartament/casa): ";
        string tip;
        cin >> tip;
        if(tip == "apartament"){
            apartament *ap = new apartament();
            cin >> (*ap);
            str.insert({ ap, tip});
        }
        if(tip == "casa"){
            casa *ca = new casa();
            cin >> *ca;

            str.insert({ca, tip});
        }
    }

    set<pair < locuinta*, string > >::iterator it = str.begin();
    while(it != str.end()){
        cout <<"tip: "<< it->second <<'\n';
        it->first->afisare_informatie();
        it++;
    }

    return 0;
}
