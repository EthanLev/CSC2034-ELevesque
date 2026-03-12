#pragma once
#include "Shape.h"

class Quadrilateral : public Shape {
    std::string m_name {};

public:
    Quadrilateral(std::string color, bool isFilled, std::string name);

    std::string getName();
};