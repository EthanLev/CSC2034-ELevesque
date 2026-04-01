#pragma once
#include <string>

class Animal {
    std::string m_name;
    std::string m_color;
    double m_weight;

public:
    Animal();
    Animal(std::string, std::string, double weight);
    virtual ~Animal() = default;

    std::string getName() { return m_name; }
    std::string getColor() { return m_color; }
    double getWeight() { return m_weight; }

    std::string makeSound();
    virtual std::string makeProperSound(); // virtual allows child classes to use

    friend std::ostream& operator << (std::ostream& out, Animal& animal);
};