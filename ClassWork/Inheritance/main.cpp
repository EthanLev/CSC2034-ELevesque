#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

int main(int, char**){
    Shape shape1 {"Blue", true};
    std::cout << shape1 << std::endl;

    Circle circle1 {"Green", false, 2.0};
    std::cout << circle1 << std::endl;

    Rectangle rec1 {"Red", true, "Rectangle", 2, 4};
    std::cout << rec1 << std::endl;
}
