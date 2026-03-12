#include "Circle.h"

Circle::Circle(std::string color, bool isFilled, double radius)
    : Shape(color, isFilled)
    , m_radius(radius) 
{

}

double Circle::getArea() { return M_PI * m_radius * m_radius; }

std::ostream& operator << (std::ostream& out, Circle& shape) {
    return out << static_cast<Shape&>(shape)
    << "\nRadius: " << shape.m_radius
    << "\nArea: " << shape.getArea() << std::endl;
}