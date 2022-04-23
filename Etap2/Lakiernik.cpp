//
// Created by 48510 on 15.12.2020.
//

#include "Lakiernik.h"

Lakiernik::Lakiernik(){
}

void Lakiernik::color_change(Owner &owner, const std::string& new_color, int index) {
    Pojazd* vehicle_color = owner.get_vehicle_sold(index);
    vehicle_color->changeColor(new_color);
    std::cout << "LAKIEROWANIE SKONCZONE! zmieniono color pojazu na: " << new_color << std::endl;
}