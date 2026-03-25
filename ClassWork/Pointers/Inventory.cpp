#include "Inventory.h"

Inventory::Inventory() {
    cars = new std::vector<Car*>;
}

Inventory::Inventory(Inventory& inventory) 
    : Inventory()
{
    auto iterator = inventory.cars->begin();

    while (iterator != inventory.cars->end()) {
        Car* car = new Car{(*iterator)->getMake(), (*iterator)->getModel(), (*iterator)->getVin().append("0")};
        cars->push_back(car);
        iterator++;
    }
}

Inventory::~Inventory() {
    auto iterator = (*cars).begin(); // ptr to first spot in cars vector
    
    while (iterator != cars->end()) {
        delete *iterator;
        iterator++; // next object
    }
}

bool Inventory::add(Car* car) {
    cars->push_back(car);
    return true;
}

std::ostream& operator << (std::ostream& out, const Inventory* inventory) {
    auto iterator = (*inventory->cars).begin();

    while (iterator != inventory->cars->end()) {
        out 
        
        << (*iterator)->getMake() << " " 
        << (*iterator)->getModel() << " " 
        << (*iterator)->getVin() << std::endl;

        iterator++;
    }

    return out << std::endl;
}