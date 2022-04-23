
#include <iostream>
#include "Fabryka.h"
#include "Lakiernik.h"
#include "Komis.h"
#include<fstream>
bool read_file=false;
std::ifstream file;

void create_new_car(Fabryka* factories, int factory_amount );
void create_new_bike(Fabryka* factories, int factory_amount);
void create_new_motorcycle(Fabryka* factory, int factory_amount );
void factory_sell_vehicle(Owner* owner, Fabryka* factories, int factory_amount );//
void show_factory_vehicles(Fabryka* factories, int factory_amount);
void drive_method(Fabryka* factories, int factory_amount );

void show_owner_vehicles(Owner* owner);
void drive_method_owner(Owner* owner );
void change_vehicle_color(Owner* owner, Lakiernik*lakiernik);
void sell_vehicle_to_commission(Owner* owner, Komis*komis);
void buy_from_commission(Owner* owner, Komis* komis);
void show_commission_vehicles(Komis* komis);
void check_capacity(Owner* owner);
int readInt();
std::string readString();

int main(int argc, char **argv) {


    if(argc==2){
        file=std::ifstream(argv[1]);
        read_file=true;
    }

    int factory_amount = 4;
    Fabryka* factories = new Fabryka [ factory_amount ];

    factories[0].nazwa_marki="BMW";
    factories[1].nazwa_marki="Audi";
    factories[2].nazwa_marki="Scoda";
    factories[3].nazwa_marki="Tesla";

    std::cout<<"Dysponujesz 4 fabrykami:"<<std::endl<<"BMW, Audi, Scoda i Tesla"<<
    std::endl<<"nazwa fabryki jest jednoczesnie marka pojazdu"<<std::endl;

    Komis* komis=new Komis[1];
    Lakiernik*lakiernik=new Lakiernik[1];
    Owner*owner =new Owner[1];



       int choice;
        do {
            std::cout
                    << "\n==============================------====== MENU ======------=================================================\n"
                       "                                 0: Zakoncz dzialanie programu\n"
                       "\n----METODY FABRYKI----                                  ----METODY WLASCICIELA---- \n"
                       "1: Utworz samochod                                        7: Wyswietl pojazdy ktore sa wlasnoscia wlasciciela\n"
                       "2: Utworz motocykl                                        8: Metoda drive-zwieksz przebieg, sprawdz stan paliwa\n"
                       "3: Utworz rower                                           9: Lakierowanie pojazdow\n"
                       "4: Sprzedaj pojazd                                       10: Metoda ladownsc-sprawdz ladownosc pojazdu\n"
                       "5: Metoda drive                                          11: Komis-sprzedaj pojazd silnikowy do komisu\n "
                       "6: Wyswietl pojazdy ktore sa wlasnoscia fabryki         12: Komis-kup z komisu\n"
                       "                                                         13: wypisz pojazdy silnikowe znajdujace sie w komisie\n"
                       "================================================================================================================\n"
                       "Wybierz akcje: " << std::endl;

            choice = readInt();

            switch (choice) {
                case 0:
                    break;
                case 1:
                    create_new_car(factories, factory_amount);
                    break;
                case 2:
                    create_new_motorcycle(factories, factory_amount);
                    break;
                case 3:
                    create_new_bike(factories, factory_amount);
                    break;
                case 4:
                    factory_sell_vehicle(owner, factories, factory_amount);
                    break;
                case 5:
                    drive_method(factories, factory_amount);
                    break;
                case 6:
                    show_factory_vehicles(factories, factory_amount);
                    break;
                case 7:
                    show_owner_vehicles(owner);
                    break;
                case 8:
                    drive_method_owner(owner);
                    break;
                case 9:
                    change_vehicle_color(owner, lakiernik);
                    break;
                case 10:
                    check_capacity(owner);
                    break;
                case 11:
                    sell_vehicle_to_commission(owner, komis);
                    break;
                case 12:
                    buy_from_commission(owner, komis);
                    break;
                case 13:
                    show_commission_vehicles(komis);
                    break;
                default:
                    std::cout << "Niepoprawny wybor" << std::endl;
            }
        } while (choice != 0);


//niszczenie aut i zwalnianie pamięci
    for(int i=0; i < factory_amount; i++ )
    {
        while(factories[i].size_Vehicles() > 0 )
        {
            Pojazd* car= factories[i].get_vehicle_ptr();
            delete car;
        }
    }


        while(owner[0].size_Vehicles_sold() > 0 )
        {
            Pojazd* car_sold= owner[0].get_vehicle_sold_ptr();
            delete car_sold;
        }


    while(komis->sizeComission() > 0 )
    {
        PojazdSilnikowy* commission= komis[0].get_vehicle_commission_ptr();
        delete commission;
    }

    delete [] factories;
    delete [] komis;
    delete [] lakiernik;

    if(argc==2){
        file.close();
    }

    return 0;
}


int readInt() {
    std::string line;
    if(read_file) {
        std::getline(file, line);
        if (line[line.size() - 1] == '\r') line.resize(line.size() - 1);
        std::cout<<line<<std::endl;
    }
    else std::getline(std::cin, line);
    return atoi(line.c_str());
}

std::string readString() {
    std::string line;
    if(read_file) {
        std::getline(file, line);
        if (line[line.size() - 1] == '\r') line.resize(line.size() - 1);
        std::cout<<line<<std::endl;
    }
    else std::getline(std::cin, line);
    return line;
}

void create_new_car(Fabryka* factories, int factory_amount )
{
    std::cout << "W ktorej fabryce chcesz stworzyc samochod? Podaj nazwe:" << std::endl;
    std::string which_factory = readString();

    for(int i=0; i < factory_amount; i++ ) {

        if (which_factory == factories[i].nazwa_marki ) {
            std::cout<<"Ile chcesz stworzyc aut?"<<std::endl;
            int car_amount=readInt();
            if(car_amount > 0 ){
                for (int j = 0; j < car_amount; j++ ) {
                    std::cout<<"PRODUKCJA SAMOCHODU NR: " << j+1 <<std::endl;
                    std::cout << "Podaj kolor:" << std::endl;
                    std::string color = readString();

                    std::cout << "Podaj liczbe drzwi:(maksymalna :5, minimalna:1):" << std::endl;
                    int doors_nr = readInt();
                    if(doors_nr > 0 && doors_nr <= 5){
                        factories[i].create_car(color, doors_nr);
                        std::cout<<"Samochod zostal wyprodukowany"<<std::endl;
                    }else std::cout<<"Nie udalo sie stworzyc tego auta, liczba drzwi powinna wynosci 1,2,3,4, lub 5"<<std::endl;
                }
                break;
            }
            else std::cout<<"Podano zla liczbe!"<<std::endl;
        }
    }

    if(which_factory != factories[0].nazwa_marki && which_factory != factories[1].nazwa_marki &&
       which_factory != factories[2].nazwa_marki && which_factory != factories[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje!"<<std::endl;
    }
}
void create_new_bike(Fabryka* factories, int factory_amount ){
    std::cout << "W ktorej fabryce chcesz stworzyc rower? Wpisz jej nazwe:" << std::endl;
    std::string which_factory = readString();

    for(int i=0; i < factory_amount; i++ ) {

        if (which_factory == factories[i].nazwa_marki ) {
            std::cout<<"Ile chcesz stworzyc rowerow?"<<std::endl;
            int bike_amount=readInt();
            if(bike_amount > 0 ){
                for (int j = 0; j < bike_amount; j++ ) {
                    std::cout<<"PRODUKCJA ROWERU NR: " << j+1 <<std::endl;
                    std::cout << "Podaj kolor:" << std::endl;
                    std::string color = readString();
                    std::cout << "Czy twoj rower ma miec koszyk? false/true" << std::endl;
                    std::string answer= readString();
                    if(answer == "true"){
                        bool kosz=true;
                        factories[i].create_bike(color, kosz);
                        std::cout<<"Rower z koszykiem zostal wyprodukowany"<<std::endl;
                    }
                    else if(answer == "false"){
                        bool kosz=false;
                        factories[i].create_bike(color, kosz);
                        std::cout<<"Rower bez koszyka zostal wyprodukowany"<<std::endl;
                    }
                    else std::cout<<"Nie wpisales sugerowanego wyboru, rower nie zostal stworzony!!"<<std::endl;

                }
                break;
            }
            else std::cout<<"Podano zla liczbe!"<<std::endl;
        }
    }

    if(which_factory != factories[0].nazwa_marki && which_factory != factories[1].nazwa_marki &&
       which_factory != factories[2].nazwa_marki && which_factory != factories[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje!"<<std::endl;
    }
}
void create_new_motorcycle(Fabryka* factory, int factory_amount ){
    std::cout << "W ktorej fabryce chcesz stworzyc motocykl? Wpisz jej nazwe:" << std::endl;
    std::string which_factory = readString();

    for(int i=0; i < factory_amount; i++ ) {

        if (which_factory == factory[i].nazwa_marki ) {
            std::cout<<"Ile chcesz stworzyc motocykli?"<<std::endl;
            int motorcycle_nr=readInt();
            if(motorcycle_nr > 0 ){
                for (int j = 0; j < motorcycle_nr; j++ ) {
                    std::cout<<"PRODUKCJA MOTOCYKLU NR: " << j+1 <<std::endl;
                    std::cout << "Podaj kolor:" << std::endl;
                    std::string color = readString();
                    factory[i].create_motorcycle(color);
                    std::cout<<"Motocykl zostal wyprodukowany"<<std::endl;
                }
                break;
            }
            else std::cout<<"Podano zla liczbe!"<<std::endl;
        }
    }

    if(which_factory != factory[0].nazwa_marki && which_factory != factory[1].nazwa_marki &&
       which_factory != factory[2].nazwa_marki && which_factory != factory[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje!"<<std::endl;
    }
}


void factory_sell_vehicle(Owner *owner, Fabryka* factories, int factory_amount )
{
    std::cout<<"Z ktorej fabryki chcesz sprzedac pojazd? Podaj jej nazwe:"<<std::endl;
    std::string which_factory = readString();

    int vehicle_nr;
    int how_many;
    for(int i=0 ; i < factory_amount; i++ )
    {
        if(which_factory == factories[i].nazwa_marki )
        {
            if(factories[i].size_Vehicles() != 0 ) {
                std::cout << "Fabryka posiada w swoim asortymencie nastepujace pojazdy:" << std::endl;
                factories[i].print_vehicle();
                vehicle_nr = factories[i].size_Vehicles();
                std::cout << "Ile pojazdow chcesz sprzedac?" << std::endl;
                how_many = readInt();
                if (how_many <= vehicle_nr && how_many > 0 ) {
                    for (int j = 0; j < how_many; j++ ) {
                        std::cout << "Ktory pojazd chcesz sprzedac?" << std::endl;
                        factories[i].print_vehicle();
                        std::cout << "Wpisz wybrany nr:" << std::endl;
                        int index = readInt();
                        if(index <= factories[i].size_Vehicles() && index > 0){
                            std::cout<<"Podaj imie i nazwisko kupujacego"<< std::endl;
                            std::string kupujacy=readString();
                            factories[i].sale_vehicle(owner[0],index - 1, kupujacy);
                        }
                        else std::cout<<"Pojazd o takim nr nie istnieje!"<<std::endl;
                    }
                    break;
                } else std::cout<< "Podano zla liczbe lub w fabryce nie ma takiej ilosci pojazdow!!!";
            }else std::cout<<"Nie masz co sprzedac, fabryka jest pusta!";
        }
    }
    if(which_factory != factories[0].nazwa_marki && which_factory != factories[1].nazwa_marki &&
       which_factory != factories[2].nazwa_marki && which_factory != factories[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje"<<std::endl;
    }
}


void drive_method(Fabryka* factories, int factory_amount )
{
    std::cout<<"Z ktorej fabryki pojazd zwiekszyl swoj przebieg? Wpisz jej nazwe:"<<std::endl;
    std::string which_factory = readString();
    for(int i=0 ; i < factory_amount; i++ ){
        if(which_factory == factories[i].nazwa_marki )
        {
            if(factories[i].size_Vehicles() != 0 ){
                std::cout<<"Ktory z ponizszych pojazdow zwiekszyl przebieg?" <<std::endl;
                factories[i].print_vehicle();
                std::cout<<"Wpisz wybrany nr:"<<std::endl;
                int number=readInt();
                Pojazd* search_vehicle= factories[i].get_vehicle(number - 1);
                if(search_vehicle != nullptr ){
                    std::cout<<"Ile kilometrow pokonal w fabryce lub w trasie fabryka- salon_sprzedazy?"<<std::endl;
                    int kilometers = readInt();
                    if( kilometers>=0 ){
                        search_vehicle->drive(kilometers);
                    }else std::cout<<"Wpisano niepoprawna liczbe km"<<std::endl;

                }else std::cout<<"Pojazd o takim nr nie istnieje!"<<std::endl;
            }else std::cout<<"Brak pojazdow w tej fabryce!";
        }
    }
    if(which_factory != factories[0].nazwa_marki && which_factory != factories[1].nazwa_marki &&
       which_factory != factories[2].nazwa_marki && which_factory != factories[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje!"<<std::endl;
    }
}

void show_factory_vehicles(Fabryka* factories, int factory_amount){
    for(int i=0; i < factory_amount; i++){
        if(factories[i].size_Vehicles() > 0 ){
            std::cout << "Pojazd marki " << factories[i].nazwa_marki << " :" << std::endl;
            factories[i].print_vehicle();
        }
        else std::cout << "W fabryce " << factories[i].nazwa_marki << " nie ma zadnych pojazdow" << std::endl;
    }
}

/////////////---------- FUNKCJE WLASCICIELA-------------///////////////////////////

void show_owner_vehicles(Owner* owner){

    if(owner[0].size_Vehicles_sold() != 0 ){
        std::cout << "Pojazdy ,ktore maja wlasciciela:" << std::endl;
        owner[0].print_vehicle_sold();
    }
    else std::cout << "Nikt jeszcze nie kupil zadnego pojazdu "  << std::endl;

}

void drive_method_owner(Owner* owner){

    if(owner[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj pojazd?" <<std::endl;
        owner[0].print_vehicle_sold();
        std::cout<<"Wpisz wybrany nr:"<<std::endl;
        int my_vehicle=readInt();
        Pojazd* search_vehicle= owner[0].get_vehicle_sold(my_vehicle - 1);
        if(search_vehicle != nullptr ){
            std::cout<<"Ile kilometrow przejechales?"<<std::endl;
            int kilometers = readInt();
            if(kilometers>=0){
                search_vehicle->drive(kilometers);
            }else std::cout<<"Podano niepoprawna liczbe kilometrow"<<std::endl;
        }else std::cout<<"Pojazd o takim nr nie istnieje!"<<std::endl;
    }else std::cout<<"Nikt jeszcze nie kupil pojazdu, nie mozna sprawdzic przebiegu!";

}

void change_vehicle_color(Owner* owner, Lakiernik*lakiernik){

    if(owner[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj pojazd?" <<std::endl;
        owner[0].print_vehicle_sold();
        std::cout<<"Podaj wybrany nr:"<<std::endl;
        int my_vehicle=readInt();
        Pojazd* search_vehicle= owner[0].get_vehicle_sold(my_vehicle - 1);
        if(search_vehicle != nullptr ){
            std::cout<<"Na jaki color chcesz przemalowac pojazd?"<<std::endl;
            std::string newColor = readString();
            lakiernik[0].color_change(owner[0], newColor, my_vehicle - 1);
        }else std::cout<<"pojazd o takim nr nie istnieje"<<std::endl;
    }else std::cout<<"Nikt jeszcze nie kupil pojazdu, nie masz pojazdu do zmiany koloru!"<<std::endl;

}

void sell_vehicle_to_commission(Owner* owner, Komis*komis){

    if(owner[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj pojazd?" <<std::endl;
        owner[0].print_vehicle_sold();
        std::cout<<"Podaj wybrany nr:"<<std::endl;
        int number=readInt();
        if(number > 0 && number <= owner[0].size_Vehicles_sold()){
            Pojazd* search_vehicle= dynamic_cast<PojazdSilnikowy *>(owner[0].get_vehicle_sold(
                    number - 1));//rzutuje z Pojazd na PojazdSilnikowy, z klasy bazowej na pochadna dlatego uzywam
                            //dynamic cast//rower sie nie przezutuje dlatego:
             if(search_vehicle != nullptr ){

                        komis[0].comission_buy(owner[0], number - 1);
                        
             }else std::cout<<"Niestety, komis nie skupuje rowerow tylko pojazdy silnikowe!"<<std::endl;
        }else std::cout<<"Pojazd o takim nr nie istnieje"<<std::endl;

    }else std::cout<<"Nie ma pojazdu ktory moglbys sprzedac do komisu!";

}
void buy_from_commission(Owner* owner, Komis*komis){

    if(komis[0].sizeComission() != 0 ) {
        std::cout << "Komis posiada w swojej ofercie nastepujace pojazdy:" << std::endl;
        komis[0].print_comission();

        std::cout << "Ktory pojazd chcesz kupic? Wpisz wybrany nr:" << std::endl;
        int index = readInt();
        if( index <= komis[0].sizeComission() && index > 0){
            std::cout<<"Podaj swoje imie i nazwisko :"<< std::endl;
            std::string buyer=readString();
                    komis[0].comission_sell(owner[0], (index - 1), buyer);
        }else std::cout<<"Pojazd o takim nr nie istnieje!"<<std::endl;
    }else std::cout<<"Nie masz co kupic, komis jest pusty!";
}


void check_capacity(Owner* owner) {

    if(owner[0].size_Vehicles_sold() != 0 ){
        std::cout<<" Ladownosc ktorego pojazdu ciebie interesuje?" <<std::endl;
        owner[0].print_vehicle_sold();
        std::cout<<"podaj wybrany nr:"<<std::endl;
        int number=readInt();
        Pojazd* search_vehicle= owner[0].get_vehicle_sold(number - 1);
         if(search_vehicle != nullptr ){
            std::cout << "ladownosc wynosi: " << search_vehicle->capacity_method() << " l" << std::endl;
         }else std::cout<<"Pojazd o takim nr nie istnieje!"<<std::endl;
    }else std::cout<<"Nie posiadasz zadnego pojazdu w ktorym mozesz sprawdzic pojemnosc!";
}


void show_commission_vehicles(Komis* komis){
    if(komis[0].sizeComission() != 0 ) {
        std::cout << "Komis posiada w swojej ofercie nastepujace pojazdy:" << std::endl;
        komis[0].print_comission();
    }
    else std::cout<<"Brak pojazdow w komisie!";
}