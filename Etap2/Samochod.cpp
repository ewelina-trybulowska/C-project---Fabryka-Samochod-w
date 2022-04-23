//
// Created by 48510 on 08.12.2020.
//
#include "Samochod.h"
#include <cstring>
#include <string>
#include <utility>


//konstruktor
Samochod::Samochod( const char* vehicle_type,std::string owner, std::string color, const char* brand,
                   int doors_number, int mileage,double fuel_amount ) {
    this->vehicle_type= nullptr;
    this->color= std::move(color);
    this->brand= nullptr;
    this->doors_number=doors_number;
    this->mileage=0;
    this->fuel_amount=100;//na starcie dostaje w prezencie pełen bag ;)
    this->owner=std::move(owner);
    copyString(brand, &this->brand);
    copyString(vehicle_type, &this->vehicle_type);

}

Samochod::Samochod( const std::string &vehicle_type, const std::string &owner, const std::string &color, const std::string &brand, int doors_number,
                   int mileage,double fuel_amount):
        Samochod(vehicle_type.c_str(),owner, color, brand.c_str(), doors_number, mileage,fuel_amount){

}

void Samochod::printItem(){
    std::cout <<" SAMOCHOD " << " ||brand: " << brand << " ,color: " << color << " ,doors number: " << doors_number
              << " ,mileage:" << mileage << "km" <<
              "  --->owner:" << owner << std::endl;
}


int Samochod:: capacity_method(){
    int capacity=0;
    if(strcmp(this->brand, "BMW")==0 ){ //funkcja strcmp porownuje dwa lancuchy znakowe,
        capacity=300;
    }
    else if(strcmp(this->brand, "Audi")==0 ){
        capacity=200;
    }
    else if(strcmp(this->brand, "Scoda")==0 ){
        capacity=150;
    }
    else {
        capacity=100;
    }
    return capacity;
}
void Samochod::drive(int km) {
    int number_refueling=0;
    this->mileage += km;
    std::cout << "aktualny przebieg samochodu to: " << mileage << " km" << std::endl;
    for(int i=0; i<km; i++){

    this->fuel_amount -= 0.08; //samochod spala 8 l paliwa na 100km, czyli 0.08 l na 1 km

    if(this->fuel_amount <= 15){ //jezeli w baku jest 15 litrow trzeba pojazd dotankowac do pelna
    number_refueling+=1;
    while(this->fuel_amount <= 100){ this->fuel_amount +=0.01;}//100 to maxymalna pojemnosc baka
    }
}
std::cout << "w czasie podrozy auto spalilo: " << 0.08*km << " l" << "-->tankowales pojazd " << number_refueling << " razy" << std::endl;
std::cout << "aktualny stan paliwa w twoim pojezdzie to: " << this->fuel_amount << " l" << std::endl;
}
Samochod::~Samochod(){
    delete[] brand;
    delete [] vehicle_type;
}


