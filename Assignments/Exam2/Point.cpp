#include "Point.h"

Point::Point(int x, int y)
    : m_x(x)
    , m_y(y)
{

}

// Copy constructor
Point::Point(const Point& other) {
    m_x = other.m_x;
    m_y = other.m_y;
}

void Point::operator+(const Point& other) {
    m_x += other.m_x;
    m_y += other.m_y;
}

std::ostream& operator << (std::ostream& out, Point& point) {
    out << "X:" << point.m_x
        << " Y:" << point.m_y;

    return out;
}
