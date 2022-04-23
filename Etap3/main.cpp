
#include <iostream>
#include "naglowki.h"
bool read_file;
std::ifstream file;
int main(int argc, char **argv) {

    if(argc==2){
        file=std::ifstream(argv[1]);
        read_file=true;
    }

    int factory_amount = 4;

    auto* factories_car = new Fabryka<Samochod> [ factory_amount ];

    factories_car[0].nazwa_marki="BMW";
    factories_car[1].nazwa_marki="Audi";
    factories_car[2].nazwa_marki="Scoda";
    factories_car[3].nazwa_marki="Tesla";

    auto* factories_motorcycle = new Fabryka<Motocykl> [ factory_amount ];

    factories_motorcycle[0].nazwa_marki="BMW";
    factories_motorcycle[1].nazwa_marki="Audi";
    factories_motorcycle[2].nazwa_marki="Scoda";
    factories_motorcycle[3].nazwa_marki="Tesla";

    auto* factories_bike = new Fabryka<Rower> [ factory_amount ];
    factories_bike[0].nazwa_marki="BMW";
    factories_bike[1].nazwa_marki="Audi";
    factories_bike[2].nazwa_marki="Scoda";
    factories_bike[3].nazwa_marki="Tesla";

    std::cout<<"Dysponujesz 4 fabrykami:"<<std::endl<<"BMW, Audi, Scoda i Tesla"<<
    std::endl<<"nazwa fabryki jest jednoczesnie marka pojazdu"<<std::endl;

    auto* komis=new Komis[1];
    auto* lakiernik=new Lakiernik[1];

    auto*owner_car =new Owner<Samochod>[1];
    auto*owner_motorcycle =new Owner<Motocykl>[1];
    auto*owner_bike =new Owner<Rower>[1];



       int choice;
        do {
            std::cout
                    << "\n==============================------====== MENU ======------=================================================\n"
                       "                                 0: Zakoncz dzialanie programu\n"
                       "\n----METODY FABRYKI----                                  ----METODY WLASCICIELA---- \n"
                       "1: Utworz samochod                                        9 : Wyswietl samochody ktore sa wlasnoscia wlasciciela\n"
                       "2: Utworz motocykl                                        10: Wyswietl motocykle ktore sa wlasnoscia wlasciciela\n"
                       "3: Utworz rower                                           11: Wyswietl rowery ktore sa wlasnoscia wlasciciela\n"
                       "4: Sprzedaj pojazd                                        12: Metoda drive-zwieksz przebieg, sprawdz stan paliwa\n"
                       "5: Metoda drive                                           13: Lakierowanie pojazdow\n"
                       "6: Wyswietl samochody ktore sa wlasnoscia fabryki         14: Metoda ladownsc-sprawdz ladownosc pojazdu\n"
                       "7: Wyswietl motocykle ktore sa wlasnoscia fabryki         15: Komis-sprzedaj pojazd silnikowy do komisu\n"
                       "8: Wyswietl rowery ktore sa wlasnoscia fabryki            16: Komis-kup z komisu\n"
                       "                                                          17: wypisz pojazdy silnikowe znajdujace sie w komisie\n"
                       "================================================================================================================\n"
                       "Wybierz akcje: " << std::endl;

            choice = readInt();

            switch (choice) {
                case 0:
                    break;
                case 1:
                    create_new_car(factories_car, factory_amount);
                    break;

                case 2:
                    create_new_motorcycle(factories_motorcycle, factory_amount);
                    break;
                case 3:
                    create_new_bike(factories_bike, factory_amount);
                    break;

                case 4:
                    factory_sell_vehicle(owner_car, owner_motorcycle, owner_bike,
                                         factories_car,factories_motorcycle,factories_bike, factory_amount);
                    break;

                case 5:
                    drive_method(factories_car,factories_motorcycle,factories_bike,factory_amount);
                    break;

                case 6:
                    show_factory_car(factories_car, factory_amount);
                    break;

                case 7:
                    show_factory_motorcycle(factories_motorcycle, factory_amount);
                    break;

                case 8:
                    show_factory_bike(factories_bike, factory_amount);
                    break;

                case 9:
                    show_owner_car(owner_car);
                    break;
                case 10:
                    show_owner_motorcycle(owner_motorcycle);
                    break;
                case 11:
                    show_owner_bike(owner_bike);
                    break;

                case 12:
                    drive_method_owner(owner_car, owner_motorcycle, owner_bike);
                    break;

                case 13:
                    change_vehicle_color(owner_car, owner_motorcycle, owner_bike, lakiernik);
                    break;

                case 14:
                    try {
                        check_capacity(owner_car, owner_motorcycle, owner_bike);
                    }
                    catch (Index_Exception &X){
                        std::cout << X.message <<std::endl;
                    }
                    catch (Capacity_Exception &X) {
                        std::cout << X.message <<std::endl;
                    }
                    break;

                case 15:
                    sell_vehicle_to_commission(owner_car,owner_motorcycle,owner_bike, komis);
                    break;
                case 16:
                    buy_from_commission(owner_car,owner_motorcycle, komis);
                    break;
                case 17:
                    show_commission_vehicles(komis);
                    break;

                default:
                    std::cout << "Niepoprawny wybor" << std::endl;
            }
        } while (choice != 0);


//niszczenie aut i zwalnianie pamięci
    for(int i=0; i < factory_amount; i++ ){
        while(factories_car[i].size_Vehicles() > 0 ){
            Samochod* car= factories_car[i].get_vehicle_ptr();
            delete car;
        }
    }
    for(int i=0; i < factory_amount; i++ ){
        while(factories_motorcycle[i].size_Vehicles() > 0 ){
            Motocykl* motorcycle= factories_motorcycle[i].get_vehicle_ptr();
            delete motorcycle;
        }
    }
    for(int i=0; i < factory_amount; i++ ){
        while(factories_bike[i].size_Vehicles() > 0 ){
            Rower* bike= factories_bike[i].get_vehicle_ptr();
            delete bike;
        }
    }
        while(owner_car[0].size_Vehicles_sold() > 0 )
        {
            Samochod* car_owner= owner_car[0].get_vehicle_sold_ptr();
            delete car_owner;
        }
    while(owner_motorcycle[0].size_Vehicles_sold() > 0 )
    {
        Motocykl* motor_owner= owner_motorcycle[0].get_vehicle_sold_ptr();
        delete motor_owner;
    }
    while(owner_bike[0].size_Vehicles_sold() > 0 )
    {
        Rower* bike= owner_bike[0].get_vehicle_sold_ptr();
        delete bike;
    }


    while(komis->sizeComission() > 0 )
    {
        PojazdSilnikowy* commission= komis[0].get_vehicle_commission_ptr();
        delete commission;
    }

    delete [] factories_motorcycle;
    delete [] factories_car;
    delete [] factories_bike;
    delete [] owner_bike;
    delete [] owner_motorcycle;
    delete [] owner_car;
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
    return std::strtol(line.c_str(), nullptr,10);
    //return atoi(line.c_str());
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

void create_new_car(Fabryka<Samochod>* factories_car, int factory_amount )
{
    std::cout << "W ktorej fabryce chcesz stworzyc samochod? Podaj nazwe:" << std::endl;
    std::string which_factory = readString();

    for(int i=0; i < factory_amount; i++ ) {

        if (which_factory == factories_car[i].nazwa_marki ) {
            std::cout<<"Ile chcesz stworzyc aut?"<<std::endl;
            int car_amount=readInt();
            if(car_amount > 0 ){
                for (int j = 0; j < car_amount; j++ ) {
                    std::cout<<"PRODUKCJA SAMOCHODU NR: " << j+1 <<std::endl;
                    std::cout << "Podaj kolor:" << std::endl;
                    std::string color = readString();

                    std::cout << "Podaj liczbe drzwi:(min:1 max:5):" << std::endl;
                    int doors_nr = readInt();
                    if(doors_nr > 0 && doors_nr <= 5){
                        factories_car[i].create_car(color, doors_nr);
                        std::cout<<"Samochod zostal wyprodukowany"<<std::endl;
                    }else std::cout<<"Nie udalo sie stworzyc tego auta, liczba drzwi powinna wynosci 1,2,3,4, lub 5"<<std::endl;
                }
                break;
            }
            else std::cout<<"Podano zla liczbe!"<<std::endl;
        }
    }

    if(which_factory != factories_car[0].nazwa_marki && which_factory != factories_car[1].nazwa_marki &&
       which_factory != factories_car[2].nazwa_marki && which_factory != factories_car[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje!"<<std::endl;
    }
}

void create_new_bike(Fabryka<Rower>* factories_bike, int factory_amount ){
    std::cout << "W ktorej fabryce chcesz stworzyc rower? Wpisz jej nazwe:" << std::endl;
    std::string which_factory = readString();

    for(int i=0; i < factory_amount; i++ ) {

        if (which_factory == factories_bike[i].nazwa_marki ) {
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
                        factories_bike[i].create_bike(color, kosz);
                        std::cout<<"Rower z koszykiem zostal wyprodukowany"<<std::endl;
                    }
                    else if(answer == "false"){
                        bool kosz=false;
                        factories_bike[i].create_bike(color, kosz);
                        std::cout<<"Rower bez koszyka zostal wyprodukowany"<<std::endl;
                    }
                    else std::cout<<"Nie wpisales sugerowanego wyboru, rower nie zostal stworzony!!"<<std::endl;

                }
                break;
            }
            else std::cout<<"Podano zla liczbe!"<<std::endl;
        }
    }

    if(which_factory != factories_bike[0].nazwa_marki && which_factory != factories_bike[1].nazwa_marki &&
       which_factory != factories_bike[2].nazwa_marki && which_factory != factories_bike[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje!"<<std::endl;
    }
}


void create_new_motorcycle(Fabryka<Motocykl>* factory_motorcycle, int factory_amount ){
    std::cout << "W ktorej fabryce chcesz stworzyc motocykl? Wpisz jej nazwe:" << std::endl;
    std::string which_factory = readString();

    for(int i=0; i < factory_amount; i++ ) {

        if (which_factory == factory_motorcycle[i].nazwa_marki ) {
            std::cout<<"Ile chcesz stworzyc motocykli?"<<std::endl;
            int motorcycle_nr=readInt();
            if(motorcycle_nr > 0 ){
                for (int j = 0; j < motorcycle_nr; j++ ) {
                    std::cout<<"PRODUKCJA MOTOCYKLU NR: " << j+1 <<std::endl;
                    std::cout << "Podaj kolor:" << std::endl;
                    std::string color = readString();
                    factory_motorcycle[i].create_motorcycle(color);
                    std::cout<<"Motocykl zostal wyprodukowany"<<std::endl;
                }
                break;
            }
            else std::cout<<"Podano zla liczbe!"<<std::endl;
        }
    }

    if(which_factory != factory_motorcycle[0].nazwa_marki && which_factory != factory_motorcycle[1].nazwa_marki &&
       which_factory != factory_motorcycle[2].nazwa_marki && which_factory != factory_motorcycle[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje!"<<std::endl;
    }
}


void factory_sell_vehicle(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle,Owner<Rower>* owner_bike,
                          Fabryka<Samochod>* factories_car,Fabryka<Motocykl>* factories_motorcycle,Fabryka<Rower>* factories_bike, int factory_amount  )
{
    std::cout << "podaj ktory pojazd ma zostac sprzedany z fabryki: samochod/motocykl/rower"<<std::endl;
    std::string which_vehicle = readString();
    if ( which_vehicle == "samochod"){
        factory_sell_car(owner_car,factories_car, factory_amount );
    }
    else if(which_vehicle == "motocykl"){
        factory_sell_motorcycle(owner_motorcycle, factories_motorcycle, factory_amount );
    }
    else if(which_vehicle == "rower"){
        factory_sell_bike(owner_bike, factories_bike,  factory_amount );
    }
    else std::cout<<"podano niewlasciwy rodzaj pojazdu" << std::endl;
}

void factory_sell_car(Owner<Samochod>* owner_car,Fabryka<Samochod>* factories_car, int factory_amount  ){
    std::cout<<"Z ktorej fabryki chcesz sprzedac pojazd? Podaj jej nazwe:"<<std::endl;
    std::string which_factory = readString();

    int vehicle_nr;
    int how_many;
    for(int i=0 ; i < factory_amount; i++ )
    {
        if(which_factory == factories_car[i].nazwa_marki )
        {
            if(factories_car[i].size_Vehicles() != 0 ) {
                std::cout << "Fabryka posiada w swoim asortymencie nastepujace samochody:" << std::endl;
                factories_car[i].print_vehicle();
                vehicle_nr = factories_car[i].size_Vehicles();
                std::cout << "Ile samochodow chcesz sprzedac?" << std::endl;
                how_many = readInt();
                if (how_many <= vehicle_nr && how_many > 0 ) {
                    for (int j = 0; j < how_many; j++ ) {
                        std::cout << "Ktory samochod chcesz sprzedac?" << std::endl;
                        factories_car[i].print_vehicle();
                        std::cout << "Wpisz wybrany nr:" << std::endl;
                        int index = readInt();
                        if(index <= factories_car[i].size_Vehicles() && index > 0){
                            std::cout<<"Podaj imie i nazwisko kupujacego"<< std::endl;
                            std::string kupujacy=readString();
                            factories_car[i].sale_vehicle(owner_car[0],index - 1, kupujacy);
                        }
                        else std::cout<<"Samochod o takim nr nie istnieje!"<<std::endl;
                    }
                    break;
                } else std::cout<< "Podano zla liczbe lub w fabryce nie ma takiej ilosci samochodow!!!";
            }else std::cout<<"Nie masz co sprzedac, fabryka jest pusta!";
        }
    }
    if(which_factory != factories_car[0].nazwa_marki && which_factory != factories_car[1].nazwa_marki &&
       which_factory != factories_car[2].nazwa_marki && which_factory != factories_car[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje"<<std::endl;
    }
}
void factory_sell_motorcycle(Owner<Motocykl>* owner_motorcycle,Fabryka<Motocykl>* factories_motorcycle, int factory_amount  ){
    std::cout<<"Z ktorej fabryki chcesz sprzedac motocykl? Podaj jej nazwe:"<<std::endl;
    std::string which_factory = readString();

    int vehicle_nr;
    int how_many;
    for(int i=0 ; i < factory_amount; i++ )
    {
        if(which_factory == factories_motorcycle[i].nazwa_marki )
        {
            if(factories_motorcycle[i].size_Vehicles() != 0 ) {
                std::cout << "Fabryka posiada w swoim asortymencie nastepujace motocykle:" << std::endl;
                factories_motorcycle[i].print_vehicle();
                vehicle_nr = factories_motorcycle[i].size_Vehicles();
                std::cout << "Ile motocykli chcesz sprzedac?" << std::endl;
                how_many = readInt();
                if (how_many <= vehicle_nr && how_many > 0 ) {
                    for (int j = 0; j < how_many; j++ ) {
                        std::cout << "Ktory motocykl chcesz sprzedac?" << std::endl;
                        factories_motorcycle[i].print_vehicle();
                        std::cout << "Wpisz wybrany nr:" << std::endl;
                        int index = readInt();
                        if(index <= factories_motorcycle[i].size_Vehicles() && index > 0){
                            std::cout<<"Podaj imie i nazwisko kupujacego"<< std::endl;
                            std::string kupujacy=readString();
                            factories_motorcycle[i].sale_vehicle(owner_motorcycle[0],index - 1, kupujacy);
                        }
                        else std::cout<<"Pojazd o takim nr nie istnieje!"<<std::endl;
                    }
                    break;
                } else std::cout<< "Podano zla liczbe lub w fabryce nie ma takiej ilosci pojazdow!!!";
            }else std::cout<<"Nie masz co sprzedac, fabryka jest pusta!";
        }
    }
    if(which_factory != factories_motorcycle[0].nazwa_marki && which_factory != factories_motorcycle[1].nazwa_marki &&
       which_factory != factories_motorcycle[2].nazwa_marki && which_factory != factories_motorcycle[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje"<<std::endl;
    }
}
void factory_sell_bike(Owner<Rower>* owner_bike, Fabryka<Rower>* factories_bike, int factory_amount  ){
    std::cout<<"Z ktorej fabryki chcesz sprzedac pojazd? Podaj jej nazwe:"<<std::endl;
    std::string which_factory = readString();

    int vehicle_nr;
    int how_many;
    for(int i=0 ; i < factory_amount; i++ )
    {
        if(which_factory == factories_bike[i].nazwa_marki )
        {
            if(factories_bike[i].size_Vehicles() != 0 ) {
                std::cout << "Fabryka posiada w swoim asortymencie nastepujace rowery:" << std::endl;
                factories_bike[i].print_vehicle();
                vehicle_nr = factories_bike[i].size_Vehicles();
                std::cout << "Ile rowerow chcesz sprzedac?" << std::endl;
                how_many = readInt();
                if (how_many <= vehicle_nr && how_many > 0 ) {
                    for (int j = 0; j < how_many; j++ ) {
                        std::cout << "Ktory rower chcesz sprzedac?" << std::endl;
                        factories_bike[i].print_vehicle();
                        std::cout << "Wpisz wybrany nr:" << std::endl;
                        int index = readInt();
                        if(index <= factories_bike[i].size_Vehicles() && index > 0){
                            std::cout<<"Podaj imie i nazwisko kupujacego"<< std::endl;
                            std::string kupujacy=readString();
                            factories_bike[i].sale_vehicle(owner_bike[0],index - 1, kupujacy);
                        }
                        else std::cout<<"Rower o takim nr nie istnieje!"<<std::endl;
                    }
                    break;
                } else std::cout<< "Podano zla liczbe lub w fabryce nie ma takiej ilosci rowerow!!!";
            }else std::cout<<"Nie masz co sprzedac, fabryka jest pusta!";
        }
    }
    if(which_factory != factories_bike[0].nazwa_marki && which_factory != factories_bike[1].nazwa_marki &&
       which_factory != factories_bike[2].nazwa_marki && which_factory != factories_bike[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje"<<std::endl;
    }
}


void drive_car(Fabryka<Samochod>* factories_car, int factory_amount ){
    std::cout<<"Z ktorej fabryki samochod zwiekszyl swoj przebieg? Wpisz jej nazwe:"<<std::endl;
    std::string which_factory = readString();
    for(int i=0 ; i < factory_amount; i++ ){
        if(which_factory == factories_car[i].nazwa_marki )
        {
            if(factories_car[i].size_Vehicles() != 0 ){
                std::cout<<"Ktory z ponizszych samochodow zwiekszyl przebieg?" <<std::endl;
                factories_car[i].print_vehicle();
                std::cout<<"Wpisz wybrany nr:"<<std::endl;
                int number=readInt();
                Samochod* search_vehicle= factories_car[i].get_vehicle(number - 1);
                if(search_vehicle != nullptr ){
                    std::cout<<"Ile kilometrow pokonal w fabryce lub w trasie fabryka- salon_sprzedazy?"<<std::endl;
                    int kilometers = readInt();
                    if( kilometers>=0 ){
                        search_vehicle->drive(kilometers);
                    }else throw Km_Exception();

                }else throw Index_Exception();
            }else std::cout<<"Brak samochodow w tej fabryce!";
        }
    }
    if(which_factory != factories_car[0].nazwa_marki && which_factory != factories_car[1].nazwa_marki &&
       which_factory != factories_car[2].nazwa_marki && which_factory != factories_car[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje!"<<std::endl;
    }
}
void drive_motorcycle(Fabryka<Motocykl>* factories_motorcycle, int factory_amount ){
    std::cout<<"Z ktorej fabryki motocykl zwiekszyl swoj przebieg? Wpisz jej nazwe:"<<std::endl;
    std::string which_factory = readString();
    for(int i=0 ; i < factory_amount; i++ ){
        if(which_factory == factories_motorcycle[i].nazwa_marki )
        {
            if(factories_motorcycle[i].size_Vehicles() != 0 ){
                std::cout<<"Ktory z ponizszych motocykli zwiekszyl przebieg?" <<std::endl;
                factories_motorcycle[i].print_vehicle();
                std::cout<<"Wpisz wybrany nr:"<<std::endl;
                int number=readInt();
                Motocykl* search_vehicle= factories_motorcycle[i].get_vehicle(number - 1);
                if(search_vehicle != nullptr ){
                    std::cout<<"Ile kilometrow pokonal w fabryce lub w trasie fabryka- salon_sprzedazy?"<<std::endl;
                    int kilometers = readInt();
                    if( kilometers>=0 ){
                        search_vehicle->drive(kilometers);
                    }else throw Km_Exception();

                }else throw Index_Exception();
            }else std::cout<<"Brak motocykli w tej fabryce!";
        }
    }
    if(which_factory != factories_motorcycle[0].nazwa_marki && which_factory != factories_motorcycle[1].nazwa_marki &&
       which_factory != factories_motorcycle[2].nazwa_marki && which_factory != factories_motorcycle[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje!"<<std::endl;
    }
}
void drive_bike(Fabryka<Rower>* factories_bike, int factory_amount ){
    std::cout<<"Z ktorej fabryki rower zwiekszyl swoj przebieg? Wpisz jej nazwe:"<<std::endl;
    std::string which_factory = readString();
    for(int i=0 ; i < factory_amount; i++ ){
        if(which_factory == factories_bike[i].nazwa_marki )
        {
            if(factories_bike[i].size_Vehicles() != 0 ){
                std::cout<<"Ktory z ponizszych rowerow zwiekszyl przebieg?" <<std::endl;
                factories_bike[i].print_vehicle();
                std::cout<<"Wpisz wybrany nr:"<<std::endl;
                int number=readInt();
                Rower* search_vehicle= factories_bike[i].get_vehicle(number - 1);
                if(search_vehicle != nullptr ){
                    std::cout<<"Ile kilometrow pokonal w fabryce lub w trasie fabryka- salon_sprzedazy?"<<std::endl;
                    int kilometers = readInt();
                    if( kilometers>=0 ){
                        search_vehicle->drive(kilometers);
                    }else throw Km_Exception();

                }else throw Index_Exception();
            }else std::cout<<"Brak rowerow w tej fabryce!";
        }
    }
    if(which_factory != factories_bike[0].nazwa_marki && which_factory != factories_bike[1].nazwa_marki &&
       which_factory != factories_bike[2].nazwa_marki && which_factory != factories_bike[3].nazwa_marki){
        std::cout<<"Taka fabryka nie istnieje!"<<std::endl;
    }
}


void drive_method(Fabryka<Samochod>* factories_car,Fabryka<Motocykl>* factories_motorcycle,Fabryka<Rower>* factories_bike, int factory_amount )
{
    std::cout << "podaj ktory pojazd zwieksza przebieg: samochod/motocykl/rower"<<std::endl;
    std::string which_vehicle = readString();
    if ( which_vehicle == "samochod"){
        try{
            drive_car(factories_car, factory_amount );
        }
        catch (Index_Exception &X){
            std::cout << X.message <<std::endl;
        }
        catch (Km_Exception &X){
            std::cout << X.message <<std::endl;
        }
    }
    else if(which_vehicle == "motocykl"){
        try {
            drive_motorcycle(factories_motorcycle, factory_amount);
        }
        catch (Index_Exception &X){
            std::cout << X.message <<std::endl;
        }
        catch (Km_Exception &X){
            std::cout << X.message <<std::endl;
        }
    }
    else if(which_vehicle == "rower"){
        try {
            drive_bike(factories_bike, factory_amount);
        }
        catch (Index_Exception &X){
            std::cout << X.message <<std::endl;
        }
        catch (Km_Exception &X){
            std::cout << X.message <<std::endl;
        }
    }
    else std::cout<<"podano niewlasciwy rodzaj pojazdu" << std::endl;
}

void show_factory_car(Fabryka<Samochod>* factories_car, int factory_amount){
    for(int i=0; i < factory_amount; i++){
        if(factories_car[i].size_Vehicles() > 0 ){
            std::cout << "Samochod marki " << factories_car[i].nazwa_marki << " :" << std::endl;
            factories_car[i].print_vehicle();
        }
        else std::cout << "W fabryce " << factories_car[i].nazwa_marki << " nie ma zadnych samochodow" << std::endl;
    }

}
void show_factory_motorcycle(Fabryka<Motocykl>* factories_motorcycle, int factory_amount){

    for(int i=0; i < factory_amount; i++){
        if(factories_motorcycle[i].size_Vehicles() > 0 ){
            std::cout << "Motocykl marki " << factories_motorcycle[i].nazwa_marki << " :" << std::endl;
            factories_motorcycle[i].print_vehicle();
        }
        else std::cout << "W fabryce " << factories_motorcycle[i].nazwa_marki << " nie ma zadnych motocykli" << std::endl;
    }

}

void show_factory_bike(Fabryka<Rower>* factories_bike, int factory_amount){

    for(int i=0; i < factory_amount; i++){
        if(factories_bike[i].size_Vehicles() > 0 ){
            std::cout << "rower marki " << factories_bike[i].nazwa_marki << " :" << std::endl;
            factories_bike[i].print_vehicle();
        }
        else std::cout << "W fabryce " << factories_bike[i].nazwa_marki << " nie ma zadnych rowerow" << std::endl;
    }
}



/////////////---------- FUNKCJE WLASCICIELA-------------///////////////////////////

void show_owner_car(Owner<Samochod>* owner_car){
    if(owner_car[0].size_Vehicles_sold() != 0 ){
        std::cout << "Samochody ,ktore maja wlasciciela:" << std::endl;
        owner_car[0].print_vehicle_sold();
    }
    else std::cout << "Nikt jeszcze nie kupil zadnego samochodu "  << std::endl;
}
void show_owner_motorcycle(Owner<Motocykl>* owner_motorcycle){
    if(owner_motorcycle[0].size_Vehicles_sold() != 0 ){
        std::cout << "Motocykle ,ktore maja wlasciciela:" << std::endl;
        owner_motorcycle[0].print_vehicle_sold();
    }
    else std::cout << "Nikt jeszcze nie kupil zadnego motocykla "  << std::endl;
}
void show_owner_bike(Owner<Rower>* owner_bike){
    if(owner_bike[0].size_Vehicles_sold() != 0 ){
        std::cout << "Rowery ,ktore maja wlasciciela:" << std::endl;
        owner_bike[0].print_vehicle_sold();
    }
    else std::cout << "Nikt jeszcze nie kupil zadnego roweru "  << std::endl;
}

void drive_method_owner(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle,Owner<Rower>* owner_bike){
    std::cout << "podaj ktory pojazd zwieksza przebieg: samochod/motocykl/rower"<<std::endl;
    std::string which_vehicle = readString();
    if ( which_vehicle == "samochod"){
        drive_method_owner_car(owner_car);
    }
    else if(which_vehicle == "motocykl"){
        drive_method_owner_motorcycle(owner_motorcycle);
    }
    else if(which_vehicle == "rower"){
        drive_method_owner_bike( owner_bike );
    }
    else std::cout<<"podano niewlasciwy rodzaj pojazdu" << std::endl;

}

void drive_method_owner_car(Owner<Samochod>* owner_car){
    if(owner_car[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj samochod?" <<std::endl;
        owner_car[0].print_vehicle_sold();
        std::cout<<"Wpisz wybrany nr:"<<std::endl;
        int my_vehicle=readInt();
        Samochod* search_vehicle= owner_car[0].get_vehicle_sold(my_vehicle - 1);
        if(search_vehicle != nullptr ){
            std::cout<<"Ile kilometrow przejechales?"<<std::endl;
            int kilometers = readInt();
            if(kilometers>=0){
                search_vehicle->drive(kilometers);
            }else std::cout<<"Podano niepoprawna liczbe kilometrow"<<std::endl;
        }else std::cout<<"Samochod o takim nr nie istnieje!"<<std::endl;
    }else std::cout<<"Nikt jeszcze nie kupil samochodu, nie mozna sprawdzic przebiegu!";
}
void drive_method_owner_motorcycle(Owner<Motocykl>* owner_motorcycle){
    if(owner_motorcycle[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj motocykl?" <<std::endl;
        owner_motorcycle[0].print_vehicle_sold();
        std::cout<<"Wpisz wybrany nr:"<<std::endl;
        int my_vehicle=readInt();
        Motocykl* search_vehicle= owner_motorcycle[0].get_vehicle_sold(my_vehicle - 1);
        if(search_vehicle != nullptr ){
            std::cout<<"Ile kilometrow przejechales?"<<std::endl;
            int kilometers = readInt();
            if(kilometers>=0){
                search_vehicle->drive(kilometers);
            }else std::cout<<"Podano niepoprawna liczbe kilometrow"<<std::endl;
        }else std::cout<<"Motocykl o takim nr nie istnieje!"<<std::endl;
    }else std::cout<<"Nikt jeszcze nie kupil motocyklu, nie mozna sprawdzic przebiegu!";
}
void drive_method_owner_bike(Owner<Rower>* owner_bike){
    if(owner_bike[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj rower?" <<std::endl;
        owner_bike[0].print_vehicle_sold();
        std::cout<<"Wpisz wybrany nr:"<<std::endl;
        int my_vehicle=readInt();
        Rower* search_vehicle= owner_bike[0].get_vehicle_sold(my_vehicle - 1);
        if(search_vehicle != nullptr ){
            std::cout<<"Ile kilometrow przejechales?"<<std::endl;
            int kilometers = readInt();
            if(kilometers>=0){
                search_vehicle->drive(kilometers);
            }else std::cout<<"Podano niepoprawna liczbe kilometrow"<<std::endl;
        }else std::cout<<"Rower o takim nr nie istnieje!"<<std::endl;
    }else std::cout<<"Nikt jeszcze nie kupil roweru, nie mozna sprawdzic przebiegu!";
}

void sell_vehicle_to_commission(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle,Owner<Rower>* owner_bike, Komis*komis){

    std::cout << "podaj ktory pojazd chcesz sprzedac do komisu: samochod/motocykl/rower"<<std::endl;
    std::string which_vehicle = readString();
    if ( which_vehicle == "samochod"){
        sell_car_to_commission(owner_car, komis);
    }
    else if(which_vehicle == "motocykl"){
        sell_motorcycle_to_commission(owner_motorcycle, komis);
    }
    else if(which_vehicle == "rower"){

        if(owner_bike[0].size_Vehicles_sold() != 0 ){
            std::cout<<"Ktory to twoj rower?" <<std::endl;
            owner_bike[0].print_vehicle_sold();
            std::cout<<"Podaj wybrany nr:"<<std::endl;
            int number=readInt();
            if(number > 0 && number <= owner_bike[0].size_Vehicles_sold()){
                try{
                    Pojazd*search_vehicle= owner_bike[0].get_vehicle_sold(number - 1);
                    komis[0].comission_buy_vehicle(search_vehicle);
                }
                catch (Bike_Exception &X) {
                    std::cout << X.message <<std::endl;
                }
            }else std::cout<<"Rower o takim nr nie istnieje"<<std::endl;
        }else std::cout<<"Nikt nie kupil roweru!";

    }
    else {
        std::cout<<"podano niewlasciwy rodzaj pojazdu" << std::endl;
    }

}
void sell_car_to_commission(Owner<Samochod>* owner_car, Komis*komis){

    if(owner_car[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj samochod?" <<std::endl;
        owner_car[0].print_vehicle_sold();
        std::cout<<"Podaj wybrany nr:"<<std::endl;
        int number=readInt();
        if(number > 0 && number <= owner_car[0].size_Vehicles_sold()){
            Pojazd* search_vehicle= owner_car[0].get_vehicle_sold(number - 1);
            komis[0].comission_buy_vehicle(search_vehicle);
            owner_car->remove_from_Vsold(number-1);
        }else std::cout<<"Samochod o takim nr nie istnieje"<<std::endl;
    }else std::cout<<"Nie ma samochodu ktory moglbys sprzedac do komisu!";
}


void sell_motorcycle_to_commission(Owner<Motocykl>* owner_motorcycle, Komis*komis){

    if(owner_motorcycle[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj motocykl?" <<std::endl;
        owner_motorcycle[0].print_vehicle_sold();
        std::cout<<"Podaj wybrany nr:"<<std::endl;
        int number=readInt();
        if(number > 0 && number <= owner_motorcycle[0].size_Vehicles_sold()){
            Pojazd* search_vehicle= owner_motorcycle[0].get_vehicle_sold(number - 1);
            komis[0].comission_buy_vehicle(search_vehicle);
            owner_motorcycle->remove_from_Vsold(number-1);

        }else std::cout<<"Motocykl o takim nr nie istnieje"<<std::endl;

    }else std::cout<<"Nie ma pojazdu ktory moglbys sprzedac do komisu!";
}


void buy_from_commission(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle, Komis*komis){

    if(komis[0].sizeComission() != 0 ) {
        std::cout << "Komis posiada w swojej ofercie nastepujace pojazdy:" << std::endl;
        komis[0].print_comission();

        std::cout << "Ktory pojazd chcesz kupic? Wpisz wybrany nr:" << std::endl;
        int index = readInt();
        if( index <= komis[0].sizeComission() && index > 0){
            std::cout<<"Podaj swoje imie i nazwisko :"<< std::endl;
            std::string buyer=readString();
            komis[0].comission_sell(owner_motorcycle[0],owner_car[0], (index - 1), buyer);
        }else std::cout<<"Pojazd o takim nr nie istnieje!"<<std::endl;
    }else std::cout<<"Nie masz co kupic, komis jest pusty!";
}


void check_capacity(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle,Owner<Rower>* owner_bike) {

    std::cout << "podaj rodzaj pojazdu, ktorego pojemnosc chcesz sprawdzic: samochod/motocykl/rower"<<std::endl;
    std::string which_vehicle = readString();
    if ( which_vehicle == "samochod"){
        if(owner_car[0].size_Vehicles_sold() != 0 ){
            std::cout<<" Ladownosc ktorego samochodu ciebie interesuje?" <<std::endl;
            owner_car[0].print_vehicle_sold();
            std::cout<<"podaj wybrany nr:"<<std::endl;
            int number=readInt();
            Samochod* search_vehicle= owner_car[0].get_vehicle_sold(number - 1);
            if(search_vehicle != nullptr ){
                std::cout << "ladownosc wynosi: " << search_vehicle->capacity_method() << " l" << std::endl;
            }else throw Index_Exception();
        }else throw Capacity_Exception();
    }
    else if(which_vehicle == "motocykl"){
        if(owner_motorcycle[0].size_Vehicles_sold() != 0 ){
            std::cout<<" Ladownosc ktorego motocykla ciebie interesuje?" <<std::endl;
            owner_motorcycle[0].print_vehicle_sold();
            std::cout<<"podaj wybrany nr:"<<std::endl;
            int number=readInt();
            Motocykl* search_vehicle= owner_motorcycle[0].get_vehicle_sold(number - 1);
            if(search_vehicle != nullptr ){
                std::cout << "ladownosc wynosi: " << search_vehicle->capacity_method() << " l" << std::endl;
            }else throw Index_Exception();
        }else throw Capacity_Exception();
    }
    else if(which_vehicle == "rower"){
        if(owner_bike[0].size_Vehicles_sold() != 0 ){
            std::cout<<" Ladownosc ktorego roweru ciebie interesuje?" <<std::endl;
            owner_bike[0].print_vehicle_sold();
            std::cout<<"podaj wybrany nr:"<<std::endl;
            int number=readInt();
            Rower* search_vehicle= owner_bike[0].get_vehicle_sold(number - 1);
            if(search_vehicle != nullptr ){
                std::cout << "ladownosc wynosi: " << search_vehicle->capacity_method() << " l" << std::endl;
            }else throw Index_Exception();
        }else throw Capacity_Exception();
    }
    else std::cout<<"podano niewlasciwy rodzaj pojazdu" << std::endl;

}


void show_commission_vehicles(Komis* komis){
    if(komis[0].sizeComission() != 0 ) {
        std::cout << "Komis posiada w swojej ofercie nastepujace pojazdy:" << std::endl;
        komis[0].print_comission();
    }
    else std::cout<<"Brak pojazdow w komisie!";
}


void change_vehicle_color(Owner<Samochod>* owner_car,Owner<Motocykl>* owner_motorcycle,Owner<Rower>* owner_bike, Lakiernik*lakiernik){

    std::cout << "podaj ktory pojazd chcesz przemalowac: samochod/motocykl/rower"<<std::endl;
    std::string which_vehicle = readString();
    if ( which_vehicle == "samochod"){
        try{
            change_car_color(owner_car, lakiernik);
        }
        catch (Color_Exception &X) {
            std::cout << X.message <<std::endl;
        }
        catch (Exist_Exception &X) {
            std::cout << X.message <<std::endl;
        }
        catch(Index_Exception &X){
            std::cout << X.message <<std::endl;
        }
    }
    else if(which_vehicle == "motocykl"){
        try {
            change_motorcycle_color(owner_motorcycle, lakiernik);
        }
        catch (Color_Exception &X) {
            std::cout << X.message <<std::endl;
        }
        catch (Exist_Exception &X) {
            std::cout << X.message <<std::endl;
        }
        catch(Index_Exception &X){
            std::cout << X.message <<std::endl;
        }
    }
    else if(which_vehicle == "rower"){
        try {
            change_bike_color(owner_bike, lakiernik);
        }
        catch (Color_Exception &X) {
            std::cout << X.message <<std::endl;
        }
        catch (Exist_Exception &X) {
            std::cout << X.message <<std::endl;
        }
        catch(Index_Exception &X){
            std::cout << X.message <<std::endl;
        }
    }
    else std::cout<<"podano niewlasciwy rodzaj pojazdu" << std::endl;

}
void change_car_color(Owner<Samochod>* owner_car, Lakiernik*lakiernik){
    if(owner_car[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj samochod?" <<std::endl;
        owner_car[0].print_vehicle_sold();
        std::cout<<"Podaj wybrany nr:"<<std::endl;
        int my_vehicle=readInt();
        Pojazd* search_vehicle= owner_car[0].get_vehicle_sold(my_vehicle - 1);
        if(search_vehicle != nullptr ){
            std::cout<<"Na jaki color chcesz przemalowac samochod?"<<std::endl;
            std::string newColor = readString();
            lakiernik[0].color_change(newColor,search_vehicle);
        }else throw Index_Exception();
    }else throw Exist_Exception();
}
void change_motorcycle_color(Owner<Motocykl>* owner_motorcycle, Lakiernik*lakiernik){
    if(owner_motorcycle[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj motocykl?" <<std::endl;
        owner_motorcycle[0].print_vehicle_sold();
        std::cout<<"Podaj wybrany nr:"<<std::endl;
        int my_vehicle=readInt();
        Motocykl* search_vehicle= owner_motorcycle[0].get_vehicle_sold(my_vehicle - 1);
        if(search_vehicle != nullptr ){
            std::cout<<"Na jaki color chcesz przemalowac motocykl?"<<std::endl;
            std::string newColor = readString();
            lakiernik[0].color_change(newColor,search_vehicle);
        }else throw Index_Exception();
    }else throw Exist_Exception();
}
void change_bike_color(Owner<Rower>* owner_bike, Lakiernik*lakiernik){
    if(owner_bike[0].size_Vehicles_sold() != 0 ){
        std::cout<<"Ktory to twoj rower?" <<std::endl;
        owner_bike[0].print_vehicle_sold();
        std::cout<<"Podaj wybrany nr:"<<std::endl;
        int my_vehicle=readInt();
        Rower* search_vehicle= owner_bike[0].get_vehicle_sold(my_vehicle - 1);
        if(search_vehicle != nullptr ){
            std::cout<<"Na jaki color chcesz przemalowac rower?"<<std::endl;
            std::string newColor = readString();
            lakiernik[0].color_change(newColor,search_vehicle);
        }else throw Index_Exception();
    }else throw Exist_Exception();
}