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

    Inventory(Inventory& other) = delete; // Copy constructor
                                          // = delete doesn't allow copying

    ~Inventory(); // Destructor

    Inventory& operator = (Inventory& other) = delete; // Overload operator

    bool add(Car* car);
    bool remove(Car* car);
};