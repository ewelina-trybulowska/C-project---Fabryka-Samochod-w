#include <iostream>
#include "Fabryka.h"

void stworz_samochod( Fabryka* fabryki, int ilosc_fabryk );
void sprzedaz_samochodu( Fabryka* fabryki, int ilosc_fabryk );
void pokaz_samochody_sprzedane(Fabryka* fabryki,int ilosc_fabryk);
void metoda_jedz( Fabryka* fabryki, int ilosc_fabryk );
int readInt();
std::string readString();

int main() {

    std::cout << "Ile zrobic fabryk:" << std::endl;
    int ilosc_fabryk = readInt();
    if(ilosc_fabryk<=0){
        std::cout<<"podano niepoprawna liczbe, program sie nie wykona";
        return 1;
    }

    Fabryka* fabryki = new Fabryka [ ilosc_fabryk ];
    for( int i=0; i<ilosc_fabryk; i++ )
    {
        std::cout << "Podaj nazwe marki/fabryki: ";
        std::string nazwa_marki = readString();
        fabryki[i].nazwa_marki=nazwa_marki;
    }


    int choice;
    do {
        std::cout << "\n---====== MENU =====---\n"
                     "0: Zakoncz dzialanie programu\n"
                     "1: Utworz samochod\n"
                     "2: Sprzedaj samochod\n"
                     "3: Metoda jedz\n "
                     "4: Wyswietl samochody sprzedane z utworzonych fabryk\n "

                     "Wybierz akcje: " << std::endl;
        choice = readInt();

        switch (choice) {
            case 0:
                break;
            case 1:
                stworz_samochod(fabryki,ilosc_fabryk);
                break;
            case 2:
                sprzedaz_samochodu(fabryki,ilosc_fabryk);
                break;

            case 3:
                metoda_jedz(fabryki, ilosc_fabryk);
                break;

            case 4:
                pokaz_samochody_sprzedane(fabryki, ilosc_fabryk);
                break;

            default:
                std::cout << "Niepoprawny wybor" << std::endl;
        }
    } while (choice != 0);


//niszczenie aut i zwalnianie pamięci
for( int i=0; i<ilosc_fabryk;i++ )
{
    while( fabryki[i].sizeSamochody()>0 )
    {
        Samochod* car= fabryki[i].get_car_ptr();
        delete car;
    }
}

    for( int i=0; i<ilosc_fabryk;i++ )
    {
        while( fabryki[i].sizeSamochody_Sprzedane()>0 )
        {
            Samochod* car_sold= fabryki[i].get_car_sold_ptr();
            delete car_sold;
        }
    }
    delete [] fabryki;

    return 0;
}


void stworz_samochod( Fabryka* fabryki, int ilosc_fabryk )
{
    std::cout << "w ktorej fabryce chcesz stworzyc auta?" << std::endl;
    std::string ktora_fabryka = readString();

    for( int i=0; i<ilosc_fabryk; i++ ) {

        if ( ktora_fabryka == fabryki[i].nazwa_marki ) {
            std::cout<<"ile chcesz stworzyc aut?"<<std::endl;
            int ilosc_aut=readInt();
            if( ilosc_aut>0 ){
                for ( int j = 0; j < ilosc_aut; j++ ) {
                    std::cout<<"PRODUKCJA SAMOCHODU NR: " << j+1 <<std::endl;
                    std::cout << "podaj kolor" << std::endl;
                    std::string kolor = readString();

                    std::cout << "podaj ilosc drzwi" << std::endl;
                    int liczba_drzwi = readInt();
                    fabryki[i].stworz_samochod(kolor, liczba_drzwi);
                }
                break;
            }
            else std::cout<<"podano zla liczbe"<<std::endl;

        }
    }
}

void sprzedaz_samochodu( Fabryka* fabryki, int ilosc_fabryk )
{
    std::cout<<"z ktorej fabryki chcesz sprzedac?"<<std::endl;
    std::string ktora_fabryka = readString();

    int ilosc_samochodow;
    int ile_aut;
    for( int i=0 ; i<ilosc_fabryk; i++ )
    {
        if( ktora_fabryka ==fabryki[i].nazwa_marki )
        {
            if( fabryki[i].sizeSamochody()!=0 ) {
                std::cout << "Fabryka posiada w swoim asortymencie nastepujace auta:" << std::endl;
                fabryki[i].printsamochody();
                ilosc_samochodow = fabryki[i].sizeSamochody();
                std::cout << "ile aut chcesz sprzedac?" << std::endl;
                ile_aut = readInt();
                if ( ile_aut <= ilosc_samochodow && ile_aut>0 ) {
                    for ( int j = 0; j < ile_aut; j++ ) {
                        std::cout << "Ktory samochod chcesz sprzedac?" << std::endl;
                        fabryki[i].printsamochody();
                        std::cout << "podaj wybrany nr:" << std::endl;
                        int index = readInt();
                        if( index <= fabryki[i].sizeSamochody() && index>0){
                            std::cout<<"podaj imie i nazwisko kupujacego"<< std::endl;
                            std::string kupujacy=readString();
                            fabryki[i].sprzedaj(index - 1, kupujacy);
                        }
                        else std::cout<<"samochod o takim nr nie istnieje"<<std::endl;
                    }
                    break;
                } else std::cout<< "podano zla liczbe lub w fabryce nie ma takiej ilosci aut->stworz wiecej samochodow ";
            }else std::cout<<"nie masz co sprzedac, fabryka jest pusta";
        }
    }
}


void metoda_jedz( Fabryka* fabryki, int ilosc_fabryk )
{
    std::cout<<"Z ktorej fabryki samochod zwiekszyl swoj przebieg?"<<std::endl;
    std::string ktora_fabryka = readString();
    for( int i=0 ; i<ilosc_fabryk; i++ ){
        if( ktora_fabryka == fabryki[i].nazwa_marki )
        {
            if( fabryki[i].sizeSamochody()!=0 ){
                std::cout<<"ktory z ponizszych samochodow zwiekszyl przebieg?" <<std::endl;
                fabryki[i].printsamochody();
                std::cout<<"podaj wybrany nr:"<<std::endl;
                int ktory_samochod=readInt();
                Samochod* szukany_samochod= fabryki[i].getsamochod(ktory_samochod-1);
                if( szukany_samochod != nullptr ){
                    std::cout<<"ile kilometrow pokonalo auto w fabryce lub w trasie fabryka- salon_sprzedazy?"<<std::endl;
                    int przejechane_km = readInt();
                    szukany_samochod->drive(przejechane_km);

                }else std::cout<<"samoochod o takim nr nie istnieje"<<std::endl;
            }else std::cout<<"brak aut w fabryce";
        }
    }
}

void pokaz_samochody_sprzedane(Fabryka* fabryki,int ilosc_fabryk){

    for(int i=0;i<ilosc_fabryk;i++){
        if( fabryki[i].sizeSamochody_Sprzedane()>0 ){
            std::cout<<"Samochody marki "<<fabryki[i].nazwa_marki<<" ,ktore sie sprzedaly:"<<std::endl;
            fabryki[i].printsamochody_sprzedane();
        }
        else std::cout<<"w fabryce "<<fabryki[i].nazwa_marki<<" nie zostal sprzedany zaden samochod"<<std::endl;
    }
}
int readInt() {
    std::string line;
    std::getline(std::cin, line);
    return atoi(line.c_str());
}

std::string readString() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}



