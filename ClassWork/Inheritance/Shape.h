#pragma once
#include <iostream>
#include <string>

class Shape {
    std::string m_color {"Grey"}; // automatically private

protected: // all children classes can access, other classes cannot
    bool m_isFilled {false};

public:
    Shape(std::string color, bool isFilled);

    std::string getColor() { return m_color; }

    bool isFilled() { return m_isFilled; }

    // friend function can access variables without getter methods
    friend std::ostream& operator << (std::ostream& out, Shape& shape);
};