//
// Created by 48510 on 16.12.2020.
//

#ifndef FACTORY_PART2_WLASCICIEL_H
#define FACTORY_PART2_WLASCICIEL_H
#include<vector>
#include <string>
#include "Samochod.h"
#include "Motocykl.h"

template <typename T>
class Owner{
private:
    std::vector<T*> Vehicles_Sold;
public:



    T* remove_from_Vsold(int index ){ Vehicles_Sold.erase(Vehicles_Sold.begin() + index);
        return nullptr;};
    void add_to_owner(T* vehicle){Vehicles_Sold.push_back(vehicle);};
    int size_Vehicles_sold(){ return Vehicles_Sold.size();};
    void print_vehicle_sold() const;
    T* get_vehicle_sold_ptr();
    T* get_vehicle_sold(int);
};
template<typename T>
void Owner<T>::print_vehicle_sold() const
{
    for(int i=0; i < Vehicles_Sold.size(); i++)
    {
        std::cout<<"pojazd nr: "<<i+1<<" " ;
        Vehicles_Sold[i]->printItem() ;
        std::cout<<"\n";
    }

}
template<typename T>
T* Owner<T>::get_vehicle_sold(int index){
    if(index < Vehicles_Sold.size()){
        return Vehicles_Sold[index];
    }
    else{
        return nullptr;
    }
}

template<typename T>
T* Owner<T>:: get_vehicle_sold_ptr(){
    T* car = *(Vehicles_Sold.end() - 1);
    Vehicles_Sold.pop_back();
    return car;
}

#endif //FACTORY_PART2_WLASCICIEL_H
