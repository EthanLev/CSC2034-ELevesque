#include "Animal.h"

Animal::Animal()
{
    m_color = "Colorless";
    m_weight = 1.0;
}

Animal::Animal(std::string name, std::string color, double weight) 
    : m_name(name)
    , m_color(color)
    , m_weight(weight)
{

}

std::string Animal::makeSound() {
    return "Animal sounds";
}

std::string Animal::makeProperSound() {
    return "Proper animal sounds";
}

// std::ostream& operator << (std::ostream& out, Animal& animal) {
//     out
//     << "Name: " << animal.m_name
//     << "\nColor: " << animal.m_color
//     << "\nWeight: " << animal.m_weight;

//     return out << std::endl;
// }

