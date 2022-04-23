//
// Created by 48510 on 08.12.2020.
//

#ifndef FACTORY_PART2_LAKIERNIK_H
#define FACTORY_PART2_LAKIERNIK_H
#include<string>
#include <iostream>
#include "Wlasciciel.h"
class Lakiernik{
public:
   void color_change(Owner &owner, const std::string& new_color, int index);//metoda do lakierowania pojazdu
   Lakiernik();
};

#endif //FACTORY_PART2_LAKIERNIK_H
