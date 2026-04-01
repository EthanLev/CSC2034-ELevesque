#include <iostream>
#include "Animal.h"
#include "Cat.h"

int main(int, char**){
    Animal* bear = new Animal("Bear", "Brown", 300);
    Cat* cat = new Cat("Cat", "Black", 10, 2.5);

    std::cout << static_cast<Animal*> (cat)->makeSound() << std::endl; // cast cat to animal

    Animal* animal = cat;

    // Equivalent of Java instanceof operator
    Cat* cat1 = dynamic_cast <Cat*> (animal);
    if (cat1 != nullptr) {
        std::cout << cat1->getWhiskerLength() << std::endl;
    }

    std::cout << bear->makeSound() << std::endl;
    std::cout << cat->makeSound() << std::endl;

    std::cout << animal->makeProperSound() << std::endl;

    delete animal;
}
