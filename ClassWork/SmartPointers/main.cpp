#include <iostream>
#include <memory>
#include "Person.h"

void print(std::unique_ptr<Person> p) {
    std::cout << *p << std::endl;
}

void print(std::shared_ptr<Person> p) {
    std::cout << *p << std::endl;
}

void print(Person* p) {
    std::cout << *p << std::endl;
}

int main(int, char**){
    // Preferred way to initialize unique pointer
    std::unique_ptr<Person> maggie{std::make_unique<Person>("Maggie", 26)};
    auto ethan{std::make_unique<Person>("Ethan", 25)};

    // Pointer moved to print()
    print(std::move(ethan));

    // Getting the raw pointer from unique pointer
    print(ethan.get());

    auto ethanAddr = std::unique_ptr<Address>("3521 Stanford Rd", "Fort Collins", "CO");
    ethan->setAddress(std::move(ethanAddr));

    // Destroys the managed resource as well as the pointer
    ethan = nullptr;

    std::shared_ptr<Person> quincy = std::make_shared<Person>("Quincy", 25);
    auto quincyClone = quincy;

    print(quincyClone);

    std::cout << "End of program" << std::endl;
}
