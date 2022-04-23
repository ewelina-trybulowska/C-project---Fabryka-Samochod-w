//
// Created by 48510 on 08.12.2020.
//

#ifndef FACTORY_PART2_POJAZDSILNIKOWY_H
#define FACTORY_PART2_POJAZDSILNIKOWY_H
#include <iostream>
#include"Pojazd.h"
//musze dziedziczyc publicznie zeby dynamic castem rzutowac z klasy bazowej na pochodna
class PojazdSilnikowy:public Pojazd{

protected:
    double fuel_amount; //pojazdy silnikowe maja paliwo
    char* vehicle_type;
    using Pojazd::owner;
    using  Pojazd::mileage;
    using Pojazd::color;
    using Pojazd::brand;
    //stosujac using wybrane pola sa dziedziczone tak jakby dla nich dziedziczenie odbylo sie protected,
    //dzieki czemu zachowuje "kapsulacje"

public:
    const char* get_type(){return vehicle_type;};

};
#endif //FACTORY_PART2_POJAZDSILNIKOWY_H
