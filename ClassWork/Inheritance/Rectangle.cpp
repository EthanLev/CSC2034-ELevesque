#include "Rectangle.h"

Rectangle::Rectangle(std::string color, bool isFilled, std::string name, int length, int breadth)
    : Quadrilateral{color, isFilled, name}
    , m_length(length) 
    , m_breadth(breadth)
{

}

int Rectangle::getArea() { return m_length * m_breadth; }

std::ostream& operator << (std::ostream& out, Rectangle& shape) {
    return out << static_cast<Shape&>(shape)
    << "\nLength: " << shape.m_length
    << "\nBreadth: " << shape.m_breadth << std::endl;
}