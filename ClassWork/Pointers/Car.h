#pragma once
#include <iostream>
#include <string>

class Car {

private:
    std::string m_vin {};
    std::string m_make {};
    std::string m_model {};

public:
    Car();
    Car(std::string, std::string, std::string);

    std::string getVin() { return m_vin; }
    std::string getMake() { return m_make; }
    std::string getModel() { return m_model; }

    friend std::ostream& operator << (std::ostream& out, Car& car);
};