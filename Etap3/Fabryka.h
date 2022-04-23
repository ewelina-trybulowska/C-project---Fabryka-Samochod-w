//
// Created by 48510 on 08.12.2020.
//

#ifndef FACTORY_PART2_FABRYKA_H
#define FACTORY_PART2_FABRYKA_H
#include<vector>
#include <iostream>
#include <string>
#include "Wlasciciel.h"
#include "Samochod.h"
#include "Rower.h"
#include "Motocykl.h"

template<typename T>
class Fabryka{

private:
    std::vector<T*> Vehicles;

public:
    std:: string nazwa_marki;

    Fabryka();
    void create_car(const std::string& color, int doors_number);
    void create_bike(const std::string& color, bool koszyk);
    void create_motorcycle(const std::string& color);
    T* sale_vehicle(Owner<T> &owner, int index, std::string buyer);
    T* get_vehicle(int);
    void print_vehicle() const;
    T* get_vehicle_ptr();
    int size_Vehicles(){ return Vehicles.size(); };
};

template<typename T>
Fabryka<T>::Fabryka()= default;

template<typename T>
void Fabryka<T>::create_car(const std::string& color, int doors_number ){
    T *car = new T("samochod","fabryka",
                   color,
                   nazwa_marki,
                   doors_number, 0,100); //nazwa marki taka sama jak fabryki
    Vehicles.push_back(car);
}
template<typename T>
void Fabryka<T>::create_motorcycle(const std::string& color){
    T *motorcycle = new T( "motocykl","fabryka",
                           color,
                           nazwa_marki,
                           0, 50);
    Vehicles.push_back(motorcycle);
}
template<typename T>
void Fabryka<T>::create_bike(const std::string& color, bool koszyk){
    T *bike = new T( "fabryka",
                     color,
                     nazwa_marki,
                     0, koszyk);
    Vehicles.push_back(bike);
}
template<typename T>
T* Fabryka<T>::sale_vehicle(Owner<T> &owner, int index, std::string buyer )
{
    if(index < Vehicles.size() && index >= 0){

        T* sale_vehicle = Vehicles.at(index); //at zwraca element z podanego miejsca
        sale_vehicle->changeOwner(std::move(buyer)); //zmienia wlasciciela na kupujacego
        owner.add_to_owner(sale_vehicle);//dodanie "kopii" usuwanego samochodu do wektora
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
template<typename T>
T* Fabryka<T>::get_vehicle_ptr(){
    T* vehicle = *(Vehicles.end() - 1);//zbieram wsk z wektora(Metoda end zwraca iterator swobodnego dostępu
    // wskazujący na element będący za ostatnim elementem znajdującym się w kontenerze.
    // Zwracany iterator wskazuje na nieistniejący element, dlatego robie end()-1)
    Vehicles.pop_back();//niszczenie wsk z wektora
    return vehicle;//zwraca wks do auta
}


//zwraca samochod o wybranym indeksie-wykorzystana w metodzie drive
template<typename T>
T* Fabryka<T>::get_vehicle(int index){
    if(index < Vehicles.size()){
        return Vehicles[index];
    }
    else{
        return nullptr;
    }
}


template<typename T>
void Fabryka<T>::print_vehicle() const
{
    for(int i=0; i < Vehicles.size(); i++)
    {
        std::cout<<"pojazd nr: "<<i+1<<" " ;
        Vehicles[i]->printItem() ;
        std::cout<<"\n";
    }

}

#endif //FACTORY_PART2_FABRYKA_H

