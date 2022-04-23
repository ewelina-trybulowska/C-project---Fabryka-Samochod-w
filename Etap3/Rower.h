//
// Created by 48510 on 08.12.2020.
//

#ifndef FACTORY_PART2_ROWER_H
#define FACTORY_PART2_ROWER_H
#include<string>
#include <iostream>
#include "Pojazd.h"

class Rower:public Pojazd{

private:
    bool koszyk;
    using Pojazd::owner;
    using  Pojazd::mileage;
    using Pojazd::color;
    using Pojazd::brand;
public:
    void drive(int km) final;//final nastepne klasy pochodne nie zatra jej nowszymi wersjami, ta jest ostateczna
    void printItem() final;
    int capacity_method()override;
    Rower( std::string owner , std::string color , const char* brand = nullptr, int mileage=-1, bool koszyk=true);

    Rower(const std::string &owner, const std::string &color, const std::string &brand,int mileage,bool koszyk);

    Rower(const Rower &rower) : Rower( rower.owner, rower.color, rower.brand, rower.mileage, rower.koszyk){};

    ~Rower() override;
};
#endif //FACTORY_PART2_ROWER_H
