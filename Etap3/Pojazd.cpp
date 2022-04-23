//
// Created by 48510 on 08.12.2020.
//

#include "Pojazd.h"
#include <iostream>


void Pojazd::drive(int km) {}
void Pojazd::printItem() {}

void Pojazd:: copyString(const char *src, char **dst) {
    if (src) {
        delete *dst;
        *dst = new char[strlen(src) + 1] {};
        strcpy(*dst, src);
    }
    else {
        *dst = nullptr;
    }
}


