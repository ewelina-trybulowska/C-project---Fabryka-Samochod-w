//
// Created by 48510 on 26.11.2020.
//

#include "Samochod.h"
#include <cstring>
#include <string>

//konstruktor
Samochod::Samochod( std::string wlasciciel, const char* kolor, const char* marka,
                   int liczba_drzwi, int przebieg ) : kolor(nullptr),marka(nullptr){

    this->liczba_drzwi=liczba_drzwi;
    this->przebieg=0;
    this->wlasciciel=wlasciciel;
    copyString(kolor, &this->kolor);
    copyString(marka, &this->marka);
}

Samochod::Samochod( const std::string &wlasciciel, const std::string &kolor, const std::string &marka, int liczba_drzwi,
                   int przebieg):
        Samochod(wlasciciel, kolor.c_str(), marka.c_str(), liczba_drzwi, przebieg){

}

Samochod::~Samochod(){
    delete[] kolor;
    delete[] marka;
}

void Samochod::drive(int km)
{
    this->przebieg += km;
    std::cout<<"aktualny przebieg auta to: "<< przebieg << " km"<<std::endl;
}

void Samochod::copyString(const char *src, char **dst) {
    if (src) {
        delete *dst;
        *dst = new char[strlen(src) + 1] {};
        strcpy(*dst, src);
    }
    else {
        *dst = nullptr;
    }
}


