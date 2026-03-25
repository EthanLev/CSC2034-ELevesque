#include "Inventory.h"

Inventory::Inventory() {
    cars = new std::vector<Car*>;
}

Inventory::~Inventory() {
    auto iterator = (*cars).begin(); // ptr to first spot in cars vector
    
    while (iterator != cars->end()) {
        delete *iterator;
        iterator++; // next object
    }
}