#include "IntList.h"
#include <iostream>

void test() {
    IntList list1, list2;

    list1.add(10);
    list1.add(-2);
    list1.add(8);

    list1.print();
    std::cout << "Size: " << list1.size() << std::endl;

    list1.clear();
    list1.print();
}

int main(int, char**){
    test();

    std::cout << "End" << std::endl;
}
