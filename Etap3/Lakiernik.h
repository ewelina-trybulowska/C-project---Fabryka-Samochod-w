//
// Created by 48510 on 08.12.2020.
//

#ifndef FACTORY_PART2_LAKIERNIK_H
#define FACTORY_PART2_LAKIERNIK_H
#include<string>
#include <iostream>
#include"Exception.h"

class Lakiernik{
public:


    template<typename T>
   void color_change(const std::string& new_color, T*vehicle_paint);//metoda do lakierowania pojazdu
   Lakiernik()= default;;
};
template<typename T>
void Lakiernik::color_change(const std::string& new_color,T*vehicle_paint) {
    if(new_color != "czerwony"){
        vehicle_paint->changeColor(new_color);
        std::cout << "LAKIEROWANIE SKONCZONE! zmieniono color pojazu na: " << new_color << std::endl;
    }else{
        throw Color_Exception();
    }

}
#endif //FACTORY_PART2_LAKIERNIK_H
