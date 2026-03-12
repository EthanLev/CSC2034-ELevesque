#pragma once
#include "Shape.h"
#include <iostream>
#include <cmath>

class Circle : public Shape {
    double m_radius {1.0};

public:
    Circle(std::string color, bool isFilled, double radius);

    double getArea();

    friend std::ostream& operator << (std::ostream& out, Circle& shape);
};