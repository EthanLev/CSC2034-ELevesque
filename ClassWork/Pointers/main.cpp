#include <iostream>
#include "Inventory.h"

int main(int, char**){
    Inventory* stock = new Inventory();
    //Inventory stock2 {*stock}; // copy of stock with pointer
    //Inventory* stock3 = &stock2; // address to stock2

    Car* bmw = new Car {"BMW123", "BMW", "335i"};
    Car* subaru = new Car {"Subaru456", "Subaru", "Impreza"};
    Car* audi = new Car {"Audi789", "Audi", "R8"};

    stock->add(bmw);
    stock->add(subaru);
    stock->add(audi);

    std::cout << stock << std::endl;
}
