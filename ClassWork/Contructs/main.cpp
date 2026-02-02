#include <iostream>

int main(){
    unsigned int age;

    std::cout << "Enter an age: ";
    std::cin >> age;

    while (age < 0) {
        std::cout << "invalid age";
        continue;
    }

    std::cout << "valid age";


    // do this while this is true
    // do {
    //     std::cout << "Enter an age: ";
    //     std::cin >> age;
    // } while (age < 0);
}
