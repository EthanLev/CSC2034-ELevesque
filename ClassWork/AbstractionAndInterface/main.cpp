#include <iostream>
#include "Car.h"
#include "Bike.h"
#include "Phone.h"
#include "IRepairable.h"

void repairAnything(IRepairable& val);

int main(int, char**){
    Vehicle v1 {};
    Car c1 {};
    Bike b1 {};
    Phone* p1 {};

    IRepairable& c2{c1};
    IRepairable* b2{new Bike()};

    std::cout << v1.move() << std::endl;

    std::cout << c1.move() << std::endl;
    std::cout << c2.repair() << std::endl;

    std::cout << b1.move() << std::endl;
    std::cout << b2->repair() << std::endl;

    repairAnything(*p1);
}

void repairAnything(IRepairable& val) {
    std::cout << val.repair() << std::endl;
}
