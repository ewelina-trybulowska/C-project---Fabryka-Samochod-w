//
// Created by 48510 on 08.12.2020.
//

#ifndef FACTORY_PART2_MOTOCYKL_H
#define FACTORY_PART2_MOTOCYKL_H
#include <iostream>
#include "PojazdSilnikowy.h"



class Motocykl:public PojazdSilnikowy{

private:
    using PojazdSilnikowy:: fuel_amount; //pojazdy silnikowe maja paliwo
    using PojazdSilnikowy:: vehicle_type;
    using PojazdSilnikowy::owner;
    using  PojazdSilnikowy::mileage;
    using PojazdSilnikowy::color;
    using PojazdSilnikowy::brand;
public:
    Motocykl( const char* vehicle_type, std::string owner , std::string color , const char* brand = nullptr, int mileage=-1,
             double fuel_amount=-1);

    Motocykl( const std::string &vehicle_type, const std::string &owner, const std::string &color, const std::string &brand,
             int mileage,double fuel_amount);

    Motocykl(const Motocykl &motocykl) : Motocykl( motocykl.owner, motocykl.owner, motocykl.color,
                                                  motocykl.brand, motocykl.mileage, motocykl.fuel_amount){};
    void printItem() override;
    int capacity_method() override;
    void drive(int km) override;
    ~Motocykl() override;

};
#endif //FACTORY_PART2_MOTOCYKL_H
