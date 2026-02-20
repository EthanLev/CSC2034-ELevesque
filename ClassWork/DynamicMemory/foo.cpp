#include<iostream>

double gDoubArr[4] {};

void foo() {
    static int sint{0};

    std::cout << "Value of static: " << ++sint << std::endl;
}