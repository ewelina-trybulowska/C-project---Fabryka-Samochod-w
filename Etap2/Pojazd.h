//
// Created by 48510 on 08.12.2020.
//

#ifndef FACTORY_PART2_POJAZD_H
#define FACTORY_PART2_POJAZD_H
#include <iostream>
#include <cstring>

class Pojazd{

protected:
    std::string owner;
    int mileage; //przebieg
    std:: string color;
    char* brand;

public:
   virtual void drive(int km)=0;//funkcja zwiekszajaca przebieg
   virtual void printItem()=0;
   virtual int capacity_method()=0;
   void copyString(const char *src, char **dst);
   int get_mileage() const{return mileage;};
   virtual ~Pojazd(){} //wirtualny destruktor, klasa jest abstrakcyjna

   //FUNKCJE DZIEKI KTORYM NIE MUSZE NADMIERNIE STOSOWAC PRZYJAZNI;)
   void changeOwner(std::string newOwner){ this->owner=std::move(newOwner);};
   void changeColor(std::string newColor){this->color=std::move(newColor);};
   void changeMileage(int newMileage){this->mileage=newMileage;};
   const char* get_brand(){return brand;};
};
#endif //FACTORY_PART2_POJAZD_H
