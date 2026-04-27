#include <iostream>
#include <queue>
#include <set>
#include "Shape.h"

int main(int, char**){
    // QUEUE
    std::priority_queue<Shape, std::vector<Shape>, ShapeCompare> shapeQ;

    shapeQ.push(Shape("Red", 60));
    shapeQ.push(Shape("Blue", 20));
    shapeQ.push(Shape("Yellow", 40));
    shapeQ.push(Shape("Green", 80));
    shapeQ.push(Shape("White", 10));

    while (!shapeQ.empty()) {
        std::cout << shapeQ.top() << " ";
        shapeQ.pop();
    }

    std::cout << std::endl;

    // SET
    std::set<Shape, ShapeCompare> shapeSet;

    shapeSet.insert(Shape("Red", 60));
    shapeSet.insert(Shape("Blue", 20));
    shapeSet.insert(Shape("Yellow", 40));
    shapeSet.insert(Shape("Green", 80));
    shapeSet.insert(Shape("White", 10));

    // for each shape object in shapeSet
    for (const auto& elem : shapeSet) {
        std::cout << elem << " ";
    }

    std::cout << std::endl;
}
