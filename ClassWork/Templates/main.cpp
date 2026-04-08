#include <iostream>
#include "Calculator.h"
#include "IntList.h"

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main(int, char**){
    Calculator<int> calc1;
    Calculator<int> calc2;
    Calculator<int> calc3;

    std::cout << calc1.add(8, 2) << std::endl;

    IntList<Calculator<int>> list;
    list.add(calc1);
    list.add(calc2);
    list.add(calc3);

    list.print();
}
