#pragma once
#include <iostream>

class Point {
    int m_x{0};
    int m_y{0};

public:
    Point() {};
    Point(int x, int y);

    Point(const Point& other); // Copy constructor

    int getX() { return m_x; }
    int getY() { return m_y; }

    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }

    void operator + (const Point& other);

    friend std::ostream& operator << (std::ostream& out, Point& point);
};

