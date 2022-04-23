//
// Created by 48510 on 08.12.2020.
//

#ifndef FACTORY_PART2_SAMOCHOD_H
#define FACTORY_PART2_SAMOCHOD_H
#include<string>
#include <iostream>
#include "PojazdSilnikowy.h"



class Samochod: public PojazdSilnikowy {

private:
    int doors_number;
    using PojazdSilnikowy:: fuel_amount; //pojazdy silnikowe maja paliwo
    using PojazdSilnikowy:: vehicle_type;
    using PojazdSilnikowy::owner;
    using  PojazdSilnikowy::mileage;
    using PojazdSilnikowy::color;
    using PojazdSilnikowy::brand;
public:

    Samochod( const char* vehicle_type,std::string owner , std::string color = nullptr,
             const char* brand = nullptr, int doors_number=-1, int mileage=-1, double fuel_amount=-1);

    Samochod(const std::string &vehicle_type,const std::string &owner, const std::string &color,
             const std::string &brand, int doors_number, int mileage,double fuel_amount);

    Samochod(const Samochod &samochod) : Samochod( samochod.vehicle_type,samochod.owner, samochod.color,
                                                  samochod.brand, samochod.doors_number, samochod.mileage,
                                                  samochod.fuel_amount){};

    void printItem() override; //override-dla nastepnych pokolen funkcja bedzie zacierac ta z klasy bazowej
    int capacity_method()override;
    void drive(int km) override;
    ~Samochod() override;



};
#endif //FACTORY_PART2_SAMOCHOD_H
