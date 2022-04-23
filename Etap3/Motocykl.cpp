//
// Created by 48510 on 08.12.2020.
//
#include "Motocykl.h"
#include <cstring>
#include <string>
#include <utility>
//konstruktor
Motocykl::Motocykl( const char* vehicle_type, std::string owner, std::string color , const char* brand,
                   int mileage,double fuel_amount ) {
    this->vehicle_type= nullptr;
    this->mileage=mileage;
    this->fuel_amount=fuel_amount;
    this->owner=std::move(owner);
    this->color= std::move(color);
    this->brand= nullptr;
    copyString(brand, &this->brand);
    copyString(vehicle_type, &this->vehicle_type);
}

Motocykl::Motocykl( const std::string &vehicle_type, const std::string &owner, const std::string &color, const std::string &brand,
                   int mileage,double fuel_amount):
        Motocykl( vehicle_type.c_str(), owner, color, brand.c_str(), mileage, fuel_amount){

}
void Motocykl::printItem(){
        std::cout << " MOTOCYKL " << " ||brand: " << brand << " ,color: " << color
                  << " ,mileage:" << mileage << "km" <<
                  "  --->owner:" << owner << std::endl;
}
int Motocykl::capacity_method(){
    int capacity;
    if(strcmp(this->brand, "BMW")==0 ){ //funkcja strcmp porownuje dwa lancuchy znakowe,
        capacity=30;
    }
    else if(strcmp(this->brand, "Audi")==0 ){
        capacity=20;
    }
    else if(strcmp(this->brand, "Scoda")==0 ){
        capacity=15;
    }
    else {
        capacity=10;
    }
    return capacity;
}
void Motocykl::drive(int km) {
    int number_refueling=0;
    this->mileage += km;
    std::cout << "aktualny przebieg motocykla to: " << mileage << " km" << std::endl;
    for(int i=0; i<km; i++){

        this->fuel_amount -= 0.06; //samochod spala 6 l paliwa na 100km, czyli 0.06 l na 1 km

        if(this->fuel_amount <= 15){ //jezeli w baku jest 15 litrow trzeba pojazd dotankowac do pelna
            number_refueling+=1;
            while(this->fuel_amount <= 50){ this->fuel_amount +=0.01;}//100 to maxymalna pojemnosc baka
        }
    }
    std::cout << "w czasie podrozy motocykl spalil: " << 0.06*km << " l" << "-->tankowales pojazd " << number_refueling << " razy" << std::endl;
    std::cout << "aktualny stan paliwa w twoim pojezdzie to: " << this->fuel_amount << " l" << std::endl;
}

Motocykl::~Motocykl(){
    delete[] brand;
    delete [] vehicle_type;
}

