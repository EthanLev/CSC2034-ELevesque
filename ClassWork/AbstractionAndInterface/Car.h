#pragma once
#include "Vehicle.h"
#include "IRepairable.h"

class Car : public Vehicle, public IRepairable {
    int numWheels {4};

public:
    std::string move() override;
    std::string repair() override;
};