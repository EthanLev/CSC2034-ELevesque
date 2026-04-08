#pragma once
#include "Vehicle.h"
#include "IRepairable.h"

class Bike : public Vehicle, public IRepairable {
    int size {26};

public:
    std::string move() override;
    std::string repair() override;
};