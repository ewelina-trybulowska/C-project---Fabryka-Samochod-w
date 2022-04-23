//
// Created by 48510 on 08.12.2020.
//

#ifndef FACTORY_PART2_FABRYKA_H
#define FACTORY_PART2_FABRYKA_H
#include<vector>
#include <string>
#include "Wlasciciel.h"
#include "Samochod.h"
#include "Rower.h"
#include "Motocykl.h"
class Fabryka{

private:
    std::vector<Pojazd*> Vehicles;

public:
    std:: string nazwa_marki;
    Fabryka(std::string brand_name);
    Fabryka();
    void create_car(const std::string& color, int doors_number);
    void create_bike(const std::string& color, bool koszyk);
    void create_motorcycle(const std::string& color);
    Pojazd* sale_vehicle(Owner &owner, int index, std::string buyer);
    Pojazd* get_vehicle(int);
    void print_vehicle() const;
    Pojazd* get_vehicle_ptr();
    int size_Vehicles(){ return Vehicles.size(); };
};
#endif //FACTORY_PART2_FABRYKA_H
