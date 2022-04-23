//
// Created by 48510 on 09.01.2021.
//

#ifndef TRYBULOWSKAEWELINA_ETAP33_EXCEPTION_H
#define TRYBULOWSKAEWELINA_ETAP33_EXCEPTION_H
#include "iostream"
struct Exception: public std::exception{
    std::string message;
    explicit Exception(std::string message): message(std::move(message)){}
};

struct Bike_Exception: public Exception{
    explicit Bike_Exception(): Exception("EXCEPTION_ERROR:Komis nie skupuje rowerow!!!"){};
};

struct Index_Exception: public Exception{
    explicit Index_Exception(): Exception("EXCEPTION_ERROR:Pojazd o takim nr nie istnieje!!!"){};
};

struct Exist_Exception: public Exception{
    explicit Exist_Exception(): Exception("EXCEPTION_ERROR:Nikt jeszcze nie kupil wybranego typu pojazdu, nie masz pojazdu do zmiany koloru"){};
};
struct Color_Exception: public Exception{
    explicit Color_Exception(): Exception("EXCEPTION_ERROR:Przykro nam, dla lakiernika skonczyla sie czerwona farba"){};
};
struct Km_Exception: public Exception{
    explicit Km_Exception(): Exception("EXCEPTION_ERROR:Wpisano niepoprawna liczbe km"){};
};
struct Capacity_Exception: public Exception{
    explicit Capacity_Exception(): Exception("EXCEPTION_ERROR: brak pojazdow  do sprawdzenia ladownosci/pojemnosci"){};
};
#endif //TRYBULOWSKAEWELINA_ETAP33_EXCEPTION_H
