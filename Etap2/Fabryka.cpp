//
// Created by 48510 on 08.12.2020.
//
#include "Fabryka.h"
#include <iostream>
#include <utility>


Fabryka::Fabryka(std::string brand_name)
{
    this->nazwa_marki = std::move(brand_name);

}
Fabryka::Fabryka(){

}


void::Fabryka::create_car(const std::string& color, int doors_number ){
    Samochod *car = new Samochod("samochod","fabryka",
                                 color,
                                 nazwa_marki,
                                 doors_number, 0,100); //nazwa marki taka sama jak fabryki
    Vehicles.push_back(car);
}

void::Fabryka::create_motorcycle(const std::string& color){
    Motocykl *motorcycle = new Motocykl( "motocykl","fabryka",
                                         color,
                                        nazwa_marki,
                                        0, 50);
    Vehicles.push_back(motorcycle);
}
void::Fabryka::create_bike(const std::string& color, bool koszyk){
   Rower *bike = new Rower( "fabryka",
                           color,
                           nazwa_marki,
                           0, koszyk);
    Vehicles.push_back(bike);
}

Pojazd* Fabryka::sale_vehicle(Owner &owner, int index, std::string buyer )
{
    if(index < Vehicles.size() && index >= 0){

        Pojazd* sale_vehicle = Vehicles.at(index); //at zwraca element z podanego miejsca
        sale_vehicle->changeOwner(std::move(buyer)); //zmienia wlasciciela na kupujacego
        owner.add_from_factory(sale_vehicle);//dodanie "kopii" usuwanego samochodu do wektora
        Vehicles.erase(Vehicles.begin() + index); //usuwanie z fabryki wedlug indeksu--erase usuwa z wektora
// pojedynczy element o połozeniu begin()+index-begin zwraca iterator wskazujący pierwszy element wektora
//rozmiar vectora zmniejsza sie o 1

        std::cout<<"Udalo sie!!! Sprzedales pojazd!!!"<<std::endl;
        return sale_vehicle;
    }
    else{
        std::cout<<"W fabryce nie ma takiego pojazdu do sprzedania"<<std::endl;
        return nullptr;
    }
}

//do zniszczenia aut i zwolnienia pamięci
Pojazd* Fabryka::get_vehicle_ptr(){
    Pojazd* vehicle = *(Vehicles.end() - 1);//zbieram wsk z wektora(Metoda end zwraca iterator swobodnego dostępu
    // wskazujący na element będący za ostatnim elementem znajdującym się w kontenerze.
    // Zwracany iterator wskazuje na nieistniejący element, dlatego robie end()-1)
    Vehicles.pop_back();//niszczenie wsk z wektora
    return vehicle;//zwraca wks do auta
}


//zwraca samochod o wybranym indeksie-wykorzystana w metodzie drive
Pojazd* Fabryka::get_vehicle(int index){
    if(index < Vehicles.size()){
        return Vehicles[index];
    }
    else{
        return nullptr;
    }
}



void Fabryka::print_vehicle() const
{
    for(int i=0; i < Vehicles.size(); i++)
    {
        std::cout<<"pojazd nr: "<<i+1<<" " ;
        Vehicles[i]->printItem() ;
        std::cout<<"\n";
    }

}


