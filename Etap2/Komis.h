//
// Created by 48510 on 08.12.2020.
//

#ifndef FACTORY_PART2_KOMIS_H
#define FACTORY_PART2_KOMIS_H
#include<iostream>
#include <cstring>
#include<vector>
#include"PojazdSilnikowy.h"
#include"Wlasciciel.h"
#include"Pojazd.h"
class Komis{
private:
    std::vector<PojazdSilnikowy*> motor_vehicles;
    double selling_price(int index); //funkcj wycenia wartosc skupywanego przez komis samochodu//funkcja pomocnicz

public:
    Komis();
    void print_comission() const;
    int sizeComission(){ return motor_vehicles.size(); };
    PojazdSilnikowy* get_vehicle_commission_ptr();
    void comission_buy(Owner &owner, int index);
    void comission_sell(Owner &owner, int index, std::string kupujacy);
};
#endif //FACTORY_PART2_KOMIS_H
