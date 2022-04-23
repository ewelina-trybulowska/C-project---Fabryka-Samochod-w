//
// Created by 48510 on 08.12.2020.
//
#include <cstring>
#include <string>
#include "Rower.h"
Rower::Rower( std::string owner, std::string color, const char* brand, int mileage, bool koszyk) {
    this->color= std::move(color);
    this->brand= nullptr;
    this->owner=std::move(owner);
    this->mileage=mileage;
    this->koszyk=koszyk;
    copyString(brand, &this->brand);
}

Rower::Rower(  const std::string &owner, const std::string &color,
              const std::string &brand,int mileage, bool koszyk):
        Rower( owner, color , brand.c_str(),mileage, koszyk){
}

Rower::~Rower(){

    delete[] brand;
}

void Rower:: drive(int km){//funkcja zwiekszajaca mileage
    this->mileage += km;
    std::cout << "aktualny przebieg roweru to: " << mileage << " km" << std::endl;
}
void Rower::printItem(){
    std::cout << " ROWER " << " ||brand: " << brand << " ,color: " << color
              << " ,mileage:" << mileage << "km" <<" ,koszyk: "<<koszyk<<
              "  --->owner:" << owner << std::endl;
}
int Rower::capacity_method(){
    int capacity=0;
    if( this->koszyk == 1 ){ //1 oznacza prawde(uzywam bool)
        capacity=3;
    }
    return capacity;
}