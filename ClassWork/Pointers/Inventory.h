#pragma once
#include <vector>
#include <iostream>
#include "Car.h"

class Inventory {

    std::vector<Car*>* cars {nullptr}; // [[Car*][Car*][Car*][Car*]]
                             // Vector of pointers to cars
                             // cars points to vector of cars    

public:
    Inventory(); // Constructor
    ~Inventory(); // Destructor

    Inventory(Inventory& other); // Copy constructor
                                 // = delete doesn't allow copying

    Inventory& operator = (Inventory& other) = default; // Overload operator

    bool add(Car* car);
    bool remove(Car* car);

    friend std::ostream& operator << (std::ostream& out, const Inventory* inventory);
};