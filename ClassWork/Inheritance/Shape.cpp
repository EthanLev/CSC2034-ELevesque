#include "Shape.h"

Shape::Shape(std::string color, bool isFilled)
    : m_color(color)
    , m_isFilled(isFilled)
{

}

std::ostream& operator << (std::ostream& out, Shape& shape) {
    std::string result = (shape.m_isFilled) ? "True" : "False";

    out 
    << "Color: " << shape.m_color
    << "\nFilled: " << result;
    return out;
}