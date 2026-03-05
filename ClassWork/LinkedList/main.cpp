#include "IntList.h"
#include <iostream>

void test() {
    IntList list1;
    std::cout << "List 1: " << std::endl;

    list1.add(10);
    list1.add(-2);
    list1.add(8);

    list1.print();

    IntList list2;
    list2 = list1;

    std::cout << "List 2: " << std::endl;
    list2.print();

    list2.add(23);
    std::cout << "Add 23 " << std::endl;

    std::cout << "List 1: "; 
    list1.print();
    std::cout << "List 2: ";
    list2.print();
}

void test1() {
    IntList seq1;
    seq1.add(1);
    seq1.add(2);
    seq1.add(3);

    IntList seq2;
    seq2.add(4);
    seq2.add(5);
    seq2.add(6);

    seq1 = seq1 + seq2;

    seq1.print();
}

int main(int, char**){
    test();

    std::cout << "End" << std::endl;
}
