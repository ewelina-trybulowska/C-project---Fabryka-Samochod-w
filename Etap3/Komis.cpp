//
// Created by 48510 on 09.12.2020.
//
#include "Komis.h"

#include <utility>
Komis::Komis()= default;


double Komis:: selling_price(int index){
    double price;
    double price_reduction;
//wraz ze zwiekszeniem przebiegu, zmniejsza sie wartosc samochodu
//przebyte kilometry zmniejszaja cene o kwote wyliczana na podstawie przebiegu wg schematu:
    int pti = (motor_vehicles[index]->get_mileage());

    if(strcmp(motor_vehicles[index]->get_brand() ,"BMW")==0 || strcmp(motor_vehicles[index]->get_brand(), "Audi")==0 ){
        pti=pti*2;//mnoze przez 2 poniewaz podczas kupienia komis
        //dzieli przebieg tych marekprzez 2, a ta funkcje wywoluje juz po 'przekreceniu 'licznika, trzeba sprawdzic pierowtny stan
    }

    if(pti>=0 && pti<30000) {//moj algorytm oceny ile przejechane km obniza wartosc pojazdu
        price_reduction= 0.12 * pti;
    }
    else if(pti>=30000 && pti<80000) {
        price_reduction= 0.16 * pti;
    }
    else if(pti>=80000 && pti<200000) {
        price_reduction= 0.17 * pti;
    }
    else price_reduction=35000;
    //cena zależna od marki--samochody okreslonych marek maja przypisana cene do skupu,
    //jest to cena "nowego" samochodu bez przejechanych km
    if(strcmp(motor_vehicles[index]->get_brand() ,"BMW")==0){
        price=80000;
    }
    else if(strcmp(motor_vehicles[index]->get_brand(), "Audi") ==0){
        price=70000;
    }
    else if(strcmp(motor_vehicles[index]->get_brand(), "Scoda") == 0){
        price=60000;
    }
    else{//tutaj wycena tesli
        price=50000;
    }
    double vehicle_value= price - price_reduction;

    if( strcmp(motor_vehicles[index]->get_type() , "motocykl") == 0 ){
        vehicle_value=vehicle_value/2; ///motocykl jest tanszy od samochodu
    }

    return vehicle_value;
}

void Komis::comission_buy_vehicle(Pojazd* vehicle_buy){ //KOMIS KUPUJE pojazd

    auto*p=dynamic_cast<PojazdSilnikowy*>(vehicle_buy);
    if(p!= nullptr){
        p->changeOwner("komis");
        //przebieg wybranych marek dzielony przez 2: wybrałam audi i bmw
        if(strcmp(p->get_brand() ,"BMW")==0 || strcmp(p->get_brand(), "Audi")==0 ){
            int pti = p->get_mileage();
            int new_milage = pti / 2;
            vehicle_buy->changeMileage(new_milage);
        }

        motor_vehicles.push_back(p); //rzutowanie w gore zachodzi automatycznie

        std::cout<<"Udalo sie!!! Sprzedales pojazd!!!"<<std::endl;
        int nr=motor_vehicles.size();
        int number_last= nr - 1;
        std::cout << "Komis zaplacil za twoj pojazd:" << selling_price(number_last) << " zl" << std::endl;
    } else {
            throw Bike_Exception();
    }
}

void Komis::comission_sell(Owner<Motocykl>&owner_motorcycle,Owner<Samochod> &owner_car, int index, std::string kupujacy){

    if(index < motor_vehicles.size() && index >= 0){

        if( strcmp(motor_vehicles[index]->get_type() , "motocykl") == 0 ){
            PojazdSilnikowy* vehicle = motor_vehicles.at(index);
            //std::move(kupujacy); //std move zeby nie kopiowac jeszcze raz i nie alokowac na to pamieci,
            vehicle->changeOwner(std::move(kupujacy));
            owner_motorcycle.add_to_owner(dynamic_cast<Motocykl *>(vehicle));

            std::cout<<"Udalo sie!!! wlasnie kupiles motocykl z komisu!!"<<std::endl;
            double price= selling_price(index) + 0.1 * selling_price(index);//marza to 10% ceny zakupu
            std::cout << "Zaplaciles za niego " << price << " zl" << std::endl;
            motor_vehicles.erase(motor_vehicles.begin() + index);
        }
        else {
            PojazdSilnikowy* vehicle = motor_vehicles.at(index);
            vehicle->changeOwner(std::move(kupujacy));
            owner_car.add_to_owner(dynamic_cast<Samochod *>(vehicle));//rzutuje dynamic cast bo konwersja w dol nie wykona się automatycznie

            std::cout<<"Udalo sie!!! wlasnie kupiles samochod z komisu!!"<<std::endl;
            double price= selling_price(index) + 0.1 * selling_price(index);//marza to 10% ceny zakupu
            std::cout << "Zaplaciles za niego " << price << " zl" << std::endl;
            motor_vehicles.erase(motor_vehicles.begin() + index);
        }
    }
    else{
        std::cout<<"W komisie nie ma takiego pojazdu do sprzedania"<<std::endl;
    }
}


void Komis::print_comission() const
{
    for(int i=0; i < motor_vehicles.size(); i++)
    {
        std::cout<<"pojazd nr: "<<i+1<<" " ;
        motor_vehicles[i]->printItem() ;
        std::cout<<"\n";
    }
}


PojazdSilnikowy* Komis::get_vehicle_commission_ptr(){
    PojazdSilnikowy* commission = *(motor_vehicles.end() - 1);
    motor_vehicles.pop_back();
    return commission;
}