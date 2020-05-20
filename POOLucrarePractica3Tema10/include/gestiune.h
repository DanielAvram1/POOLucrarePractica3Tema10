#ifndef GESTIUNE_H
#define GESTIUNE_H
#include "casa.h"
#include "apartament.h"
#include<vector>
using namespace std;

template <class T>
class gestiune{
private:
    vector<T*> tabel;

protected:
public:
    gestiune(){}
    gestiune(int n){
        tabel.reserve(n);
    }
    gestiune(const gestiune& ob){
        tabel = ob.tabel;
    }
    ~gestiune(){
        while(!tabel.empty()){
            T* temp = tabel.back();
            delete temp;
            tabel.pop_back();
        }
    }
    void adauga( T* ob){
        tabel.push_back(ob);
    }
    T* operator[](int index){
        return tabel[index];
    }

    const T* operator += ( T* ob){
        adauga(ob);
        return ob;
    }
    int total(){
        return tabel.size();
    }

    void sterge(int index){
        tabel->erase(tabel.begin() + index);
    }
};

template<>
class gestiune<casa>{
private:
    vector<casa*> tabel;

protected:
public:
    gestiune(){}
    gestiune(int n){
        tabel.reserve(n);
    }
    gestiune(const gestiune& ob){
        tabel = ob.tabel;
    }
    ~gestiune(){
        while(!tabel.empty()){
            casa* temp = tabel.back();
            delete temp;
            tabel.pop_back();
        }
    }
    void adauga(casa* ob){
        tabel.push_back(ob);
    }
    casa* operator[](int index){
        return tabel[index];
    }

    const casa* operator += (casa* ob){
        adauga(ob);
        return ob;
    }
    int total(){
        return tabel.size();
    }

    void sterge(int index){
        tabel.erase(tabel.begin() + index);
    }
    double castig_total(){
        double ans = 0;
        for(auto it : tabel){
            ans += it->calcul_chirie();
        }
        return ans;
    }

};

#endif // GESTIUNE_H
