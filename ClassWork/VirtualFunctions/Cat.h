#pragma once
#include <string>
#include <iostream>

#include "Animal.h"

class Cat : public Animal {
    double m_whiskerLength {2.0};

public:
    Cat(std::string, std::string, double, double);
    ~Cat();

    double getWhiskerLength() const { return m_whiskerLength; }

    std::string makeSound();
    std::string makeProperSound() override; // override virtual function

    friend std::ostream& operator << (std::ostream& out, Cat& cat);
};