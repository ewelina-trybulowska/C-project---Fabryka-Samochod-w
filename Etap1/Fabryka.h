//
// Created by 48510 on 26.11.2020.
//

#ifndef FACTORY_FABRYKA_H
#define FACTORY_FABRYKA_H
#include "Samochod.h"
#include<vector>
#include <string>

class Fabryka{

    std::vector<Samochod*> Samochody;
    std::vector<Samochod*> Samochody_Sprzedane;
public:
    std::string nazwa_marki;
    Fabryka(std::string nazwa_marki);
    Fabryka ();
    void stworz_samochod( const std::string& kolor, int liczba_drzwi);
    Samochod* sprzedaj(int index,  std::string kupujacy);
    Samochod* getsamochod(int);
    Samochod* printsamochody() const;
    Samochod* printsamochody_sprzedane() const;
    Samochod* get_car_ptr();
    Samochod* get_car_sold_ptr();
    int sizeSamochody(){ return Samochody.size(); };
    int sizeSamochody_Sprzedane(){ return Samochody_Sprzedane.size();};
};
#endif //FACTORY_FABRYKA_H
