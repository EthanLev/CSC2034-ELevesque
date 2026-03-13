#pragma once

#include "Point.h"

class Line {
    Point* pt1;
    Point* pt2;

public:
    Line();
    Line(int x1, int y1, int x2, int y2); 

    Line(const Line& other); // Copy constructor

    ~Line(); // Destructor to delete points when line is out of scope

    // Getters
    Point* getPt1() { return pt1; }
    Point* getPt2() { return pt2; }

    // Returns length of points in line
    double segmentLength();

    // Returns slope of line as an int
    int slope();

    // Assignment operator to copy points
    Line& operator = (const Line& other);

    //Overload stream for printing line
    friend std::ostream& operator << (std::ostream& out, Line& line);
};