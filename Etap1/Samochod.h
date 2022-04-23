//
// Created by 48510 on 26.11.2020.
//

#ifndef FACTORY_SAMOCHOD_H
#define FACTORY_SAMOCHOD_H
#include<string>
#include <iostream>

class Fabryka; //deklaracja zapowiadajaca

class Samochod {
  friend class Fabryka; //zaprzyjazniam klasy zeby Fabryka miala dostep do private z klasy Samochod

private:
    std::string wlasciciel;
    char* kolor;
    int liczba_drzwi;
    char* marka;
    int przebieg;


public:

    Samochod( std::string wlasciciel , const char* kolor = nullptr, const char* marka = nullptr, int liczba_drzwi=-1,int przebieg=-1);

    Samochod(const std::string &wlasciciel, const std::string &kolor, const std::string &marka, int liczba_drzwi, int przebieg);


    Samochod(const Samochod &samochod) : Samochod(samochod.wlasciciel, samochod.kolor,
                                                  samochod.marka, samochod.liczba_drzwi, samochod.przebieg){};

    ~Samochod();
    void copyString(const char *src, char **dst);
    void drive(int km);//funkcja zwiekszajaca przebieg
};
#endif //FACTORY_SAMOCHOD_H
