#pragma once
#include "Quadrilateral.h"

class Rectangle : public Quadrilateral {
    int m_length {1};
    int m_breadth {1};

public:
    Rectangle(std::string, bool, std::string, int, int);

    int getArea();

    friend std::ostream& operator << (std::ostream& out, Rectangle& shape);

    //using Shape::getColor; // loosen protections, make parent function public
};