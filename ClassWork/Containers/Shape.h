#pragma once
#include <string>
#include <iostream>

class Shape {
    std::string m_color;
    double m_area;

public:
    Shape(std::string color, double area)
        : m_color(color)
        , m_area(area)
    {}

    const std::string getColor() const { return m_color; }
    const double getArea() const { return m_area; }

    friend std::ostream& operator<<(std::ostream& out, Shape s);

    // bool operator<=>(Shape other) {
    //     return this->m_area <=> other.m_area;
    // }
};

std::ostream& operator<<(std::ostream& out, Shape s) {
    out<< "(" << s.m_color << ", " << s.m_area << ")";
    return out;
}

struct ShapeCompare {
    bool operator()(const Shape& s1, const Shape& s2) const {
        return s1.getArea() < s2.getArea();
    }
};
