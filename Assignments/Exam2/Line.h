#pragma once

#include "Point.h"

class Line {
    Point* pt1;
    Point* pt2;

public:
    Line();
    Line(int x1, int y1, int x2, int y2); 

    Line(const Line& other); // Copy constructor

    ~Line();

    Point* getPt1() { return pt1; }
    Point* getPt2() { return pt2; }

    double segmentLength();
    int slope();

    friend std::ostream& operator << (std::ostream& out, Line& line);
};