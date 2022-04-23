//
// Created by 48510 on 26.11.2020.
//

#include "Fabryka.h"
#include <iostream>


Fabryka::Fabryka(std::string nazwa_marki)
{
    this->nazwa_marki = nazwa_marki;

}
Fabryka::Fabryka(){

}

void::Fabryka::stworz_samochod( const std::string& kolor, int liczba_drzwi ){
Samochod *samochodzik = new Samochod("fabryka",
                                     kolor,
                                     nazwa_marki,
                                     liczba_drzwi, 0); //nazwa marki taka sama jak fabryki
Samochody.push_back(samochodzik);
}

Samochod* Fabryka::sprzedaj( int index, std::string kupujacy )
{
    if( index < Samochody.size() && index>=0){

        Samochod* samochod_do_sprzedania = Samochody.at(index); //at zwraca element z podanego miejsca
        samochod_do_sprzedania->wlasciciel=kupujacy; //zmienia wlasciciela na kupujacego
        Samochody_Sprzedane.push_back(samochod_do_sprzedania); //dodanie "kopii" usuwanego samochodu do wektora
        Samochody.erase(Samochody.begin()+index); //usuwanie z fabryki wedlug indeksu--erase usuwa z wektora
// pojedynczy element o połozeniu begin()+index-begin zwraca iterator wskazujący pierwszy element wektora
//rozmiar vectora zmniejsza sie o 1

        std::cout<<"Udalo sie!!! Sprzedales samochod!!!"<<std::endl;

       return samochod_do_sprzedania;
    }
    else{
        std::cout<<"W fabryce nie ma takiego samochodu do sprzedania"<<std::endl;
        return nullptr;
    }
}

//do zniszczenia aut i zwolnienia pamięci
Samochod* Fabryka::get_car_ptr(){
    Samochod* car = *(Samochody.end()-1);//zbieram wsk z wektora(Metoda end zwraca iterator swobodnego dostępu
    // wskazujący na element będący za ostatnim elementem znajdującym się w kontenerze.
    // Zwracany iterator wskazuje na nieistniejący element, dlatego robie end()-1)
    Samochody.pop_back();//niszczenie wsk z wektora
    return car;//zwraca wks do auta
}

Samochod* Fabryka:: get_car_sold_ptr(){
    Samochod* car = *(Samochody_Sprzedane.end()-1);
    Samochody_Sprzedane.pop_back();
    return car;
}
//zwraca samochod o wybranym indeksie-wykorzystana w metodzie jedz
Samochod* Fabryka::getsamochod(int index){
    if( index < Samochody.size()){
        return Samochody[index];
    }
    else{
        return nullptr;
    }
}

Samochod* Fabryka::printsamochody() const
{
    for(int i=0; i<Samochody.size(); i++)
    {
        std::cout<<"samochod nr: "<<i+1 <<" ||marka: " <<Samochody[i]->marka<<" ,kolor: "<<Samochody[i]->kolor
                 <<" ,liczba drzwi: "<<Samochody[i]->liczba_drzwi<<" ,przebieg:" <<Samochody[i]->przebieg<<"km"<<
                 "  --->wlasciciel:"<<Samochody[i]->wlasciciel<<std::endl;
    }

    return nullptr;
}

Samochod* Fabryka::printsamochody_sprzedane() const
{
    for(int i=0; i<Samochody_Sprzedane.size(); i++)
    {
        std::cout<<"samochod nr: "<<i+1 <<" ||marka: " <<Samochody_Sprzedane[i]->marka<<" ,kolor: "<<Samochody_Sprzedane[i]->kolor
                 <<" ,liczba drzwi: "<<Samochody_Sprzedane[i]->liczba_drzwi<<" ,przebieg:" <<Samochody_Sprzedane[i]->przebieg<<"km"<<
                 "  --->wlasciciel:"<<Samochody_Sprzedane[i]->wlasciciel<<std::endl;
    }

    return nullptr;
}
