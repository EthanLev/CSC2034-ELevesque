#include <cmath>
#include <tuple>
#include "Line.h"

Line::Line() {
    pt1 = new Point{0,0};
    pt2 = new Point{0,0};
}

Line::Line(int x1, int y1, int x2, int y2) {
    pt1 = new Point{x1,y1};
    pt2 = new Point{x2,y2};
}

// Copy constructor
Line::Line(const Line& other) {
    pt1 = new Point{*other.pt1};
    pt2 = new Point{*other.pt2};
}

// Destructor
Line::~Line() {
    delete pt1;
    delete pt2;
}

double Line::segmentLength() {
    double x = pt1->getX() - pt2->getX();
    double y = pt1->getY() - pt2->getY();

    return std::sqrt(x * x + y * y);
}

int Line::slope() {
    int y = pt2->getY() - pt1->getY();
    int x = pt2->getX() - pt1->getX();

    return y/x;
}

Line& Line::operator = (const Line& other) {
    if (this == &other) return *this;

    delete pt1;
    delete pt2;

    pt1 = new Point{*other.pt1};
    pt2 = new Point{*other.pt2};

    return *this;
}

std::ostream& operator << (std::ostream& out, Line& line) {
    out << *line.pt1
        << " and " 
        << *line.pt2;

    return out;
}


