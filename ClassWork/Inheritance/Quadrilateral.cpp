#include "Quadrilateral.h"

Quadrilateral::Quadrilateral(std::string color, bool isFilled, std::string name)
    : Shape{color, isFilled}
    , m_name(name) 
{

}

std::string Quadrilateral::getName() { return m_name; }

std::ostream& operator << (std::ostream& out, Quadrilateral& shape) {
    return out << static_cast<Shape&>(shape)
    << "\nName: " << shape.getName() << std::endl;
}