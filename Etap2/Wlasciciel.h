//
// Created by 48510 on 16.12.2020.
//

#ifndef FACTORY_PART2_WLASCICIEL_H
#define FACTORY_PART2_WLASCICIEL_H

#include<vector>
#include <string>
#include "Pojazd.h"
#include "PojazdSilnikowy.h"

class Owner{
private:
    std::vector<Pojazd*> Vehicles_Sold;
public:
        void remove_from_Vsold(int index ){ Vehicles_Sold.erase(Vehicles_Sold.begin() + index);};
        void add_to_Vsold( PojazdSilnikowy* vehicle ){ Vehicles_Sold.push_back(vehicle);};
        void add_from_factory(Pojazd* vehicle){Vehicles_Sold.push_back(vehicle);};
        int size_Vehicles_sold(){ return Vehicles_Sold.size();};
        void print_vehicle_sold() const;
        Pojazd* get_vehicle_sold_ptr();
        Pojazd* get_vehicle_sold(int);
};

#endif //FACTORY_PART2_WLASCICIEL_H
