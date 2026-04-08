#pragma once
#include <iostream>
#include <string>
#include "IRepairable.h"

class Phone : public IRepairable {
    double screenSize {4};

public:
    std::string repair() override;
};