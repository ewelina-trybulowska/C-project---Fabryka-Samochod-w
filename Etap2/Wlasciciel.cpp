//
// Created by 48510 on 16.12.2020.
//
#include "Wlasciciel.h"
void Owner::print_vehicle_sold() const
{
    for(int i=0; i < Vehicles_Sold.size(); i++)
    {
        std::cout<<"pojazd nr: "<<i+1<<" " ;
        Vehicles_Sold[i]->printItem() ;
        std::cout<<"\n";
    }

}
Pojazd* Owner::get_vehicle_sold(int index){
    if(index < Vehicles_Sold.size()){
        return Vehicles_Sold[index];
    }
    else{
        return nullptr;
    }
}


Pojazd* Owner:: get_vehicle_sold_ptr(){
    Pojazd* car = *(Vehicles_Sold.end() - 1);
    Vehicles_Sold.pop_back();
    return car;
}