#include "Cat.h"

Cat::Cat(std::string name, std::string color, double weight, double whiskerLength) 
    : Animal{name, color, weight}
    , m_whiskerLength(whiskerLength)
{

}

Cat::~Cat() {
    std::cout << "Deleting cat";

}

std::string Cat::makeSound() {
    return "Meow";
}

std::string Cat::makeProperSound() {
    return "Proper Meow";
}