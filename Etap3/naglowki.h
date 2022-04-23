//
// Created by 48510 on 10.01.2021.
//

#ifndef TRYBULOWSKAEWELINA_ETAP33_NAGLOWKI_H
#define TRYBULOWSKAEWELINA_ETAP33_NAGLOWKI_H
#include "Fabryka.h"
#include "Lakiernik.h"
#include "Komis.h"
#include<fstream>



void create_new_car(Fabryka<Samochod>* factories_car, int factory_amount );
void create_new_bike(Fabryka<Rower>* factories_bike, int factory_amount);
void create_new_motorcycle(Fabryka<Motocykl>* factory_motorcycle, int factory_amount );

void factory_sell_vehicle(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle,Owner<Rower>* owner_bike,
                          Fabryka<Samochod>* factories_car,Fabryka<Motocykl>* factories_motorcycle,Fabryka<Rower>* factories_bike, int factory_amount );//
void factory_sell_car(Owner<Samochod>* owner_car,Fabryka<Samochod>* factories_car, int factory_amount  );
void factory_sell_motorcycle(Owner<Motocykl>* owner_motorcycle,Fabryka<Motocykl>* factories_motorcycle, int factory_amount  );
void factory_sell_bike(Owner<Rower>* owner_bike, Fabryka<Rower>* factories_bike, int factory_amount  );

void show_factory_car(Fabryka<Samochod>* factories_car, int factory_amount);
void show_factory_motorcycle(Fabryka<Motocykl>* factories_motorcycle,  int factory_amount);
void show_factory_bike(Fabryka<Rower>* factories_bike, int factory_amount);

void drive_method(Fabryka<Samochod>* factories_car,Fabryka<Motocykl>* factories_motorcycle,Fabryka<Rower>* factories_bike, int factory_amount);
void drive_car(Fabryka<Samochod>* factories_car, int factory_amount );
void drive_motorcycle(Fabryka<Motocykl>* factories_motorcycle, int factory_amount );
void drive_bike(Fabryka<Rower>* factories_bike, int factory_amount );


void show_owner_car(Owner<Samochod>* owner_car);
void show_owner_motorcycle(Owner<Motocykl>* owner_motorcycle);
void show_owner_bike(Owner<Rower>* owner_bike);

void drive_method_owner(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle,Owner<Rower>* owner_bike );
void drive_method_owner_car(Owner<Samochod>* owner_car);
void drive_method_owner_motorcycle(Owner<Motocykl>* owner_motorcycle);
void drive_method_owner_bike(Owner<Rower>* owner_bike);

void change_vehicle_color(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle,Owner<Rower>* owner_bike, Lakiernik*lakiernik);


void change_car_color(Owner<Samochod>* owner_car, Lakiernik*lakiernik);
void change_motorcycle_color(Owner<Motocykl>* owner_motorcycle, Lakiernik*lakiernik);
void change_bike_color(Owner<Rower>* owner_bike, Lakiernik*lakiernik);


void sell_vehicle_to_commission(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle,Owner<Rower>* owner_bike, Komis*komis);
void sell_car_to_commission(Owner<Samochod>* owner_car, Komis*komis);
void sell_motorcycle_to_commission(Owner<Motocykl>* owner_motorcycle, Komis*komis);
void buy_from_commission(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle, Komis* komis);
void show_commission_vehicles(Komis* komis);

void check_capacity(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle,Owner<Rower>* owner_bike);

int readInt();
std::string readString();

#endif //TRYBULOWSKAEWELINA_ETAP33_NAGLOWKI_H
