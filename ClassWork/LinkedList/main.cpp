#include "IntList.h"
#include <iostream>

void test() {
    IntList list1;
    std::cout << "List 1: " << std::endl;

    list1.add(10);
    list1.add(-2);
    list1.add(8);

    list1.print();
    std::cout << "Size: " << list1.size() << std::endl;

    std::cout << "List 2: " << std::endl;
    IntList list2{list1};

    list2.print();
    list2.add(23);
    std::cout << "Add 23 " << std::endl;
    list2.print();
    std::cout << "Size: " << list2.size() << std::endl;

    std::cout << "List 1: "; 
    list1.print();
    std::cout << "List 2: ";
    list2.print();
}

int main(int, char**){
    test();

    std::cout << "End" << std::endl;
}
