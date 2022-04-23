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
#include "Samochod.h"
#include "Motocykl.h"
#include "Rower.h"
#include "Exception.h"
class Komis{
private:
    std::vector<PojazdSilnikowy*> motor_vehicles;
    double selling_price(int index); //funkcj wycenia wartosc skupywanego przez komis samochodu//funkcja pomocnicz

public:

    Komis();
    void print_comission() const;
    int sizeComission(){ return motor_vehicles.size(); };
    PojazdSilnikowy* get_vehicle_commission_ptr();
    void comission_buy_vehicle(Pojazd* vehicle_buy);
    void comission_sell(Owner<Motocykl> &owner_motorcycle,Owner <Samochod> &owner_car, int index, std::string kupujacy);
};
#endif //FACTORY_PART2_KOMIS_H
