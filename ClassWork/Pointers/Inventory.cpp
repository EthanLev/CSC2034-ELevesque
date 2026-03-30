#include "Inventory.h"

Inventory::Inventory() { // Constructor to create vector
    cars = new std::vector<Car*>;
}

Inventory::Inventory(Inventory& inventory) // Constructor 
    : Inventory()
{
    auto iterator = inventory.cars->begin();

    while (iterator != inventory.cars->end()) {
        Car* car = new Car{(*iterator)->getMake(), (*iterator)->getModel(), (*iterator)->getVin().append("0")};
        cars->push_back(car);
        iterator++;
    }
}

Inventory::~Inventory() { // Destructor
    clearInventory();
}

bool Inventory::add(Car* car) { // Add method
    cars->push_back(car);
    return true;
}

bool Inventory::remove(Car* car) { // Remove method
    auto iterator = cars->begin();

    while (iterator != cars->end()) {
        if ((*iterator)->getVin() == car->getVin()) {
            delete *iterator;
            cars->erase(iterator);
            return true;
        }

        iterator++;
    }

    return false;
}

void Inventory::clearInventoryBackwards() { // Clear inventory backwards method
    auto iterator = cars->end();
    iterator--;

    while (iterator != cars->begin()) {
        delete *iterator;
        cars->erase(iterator); // only erase because were going backwards through the vector
        iterator--;
    }

    delete *iterator;
    cars->erase(iterator);
}

void Inventory::clearInventory() { // Clear inventory method
    auto iterator = cars->begin();

    while (iterator != cars->end()) {
        delete *iterator;
        iterator++;
    }

    while (!cars->empty()) {
        cars->pop_back();
    }
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