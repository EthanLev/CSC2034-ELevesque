#include "Car.h"

Car::Car()
{
}

Car::Car(std::string vin, std::string make, std::string model)
    : m_vin(vin)
    , m_make(make)
    , m_model(model)
{

}

std::ostream& operator << (std::ostream& out, Car& car) {
    out
    << "VIN: " << car.m_vin
    << "Make: " << car.m_make
    << "Model: " << car.m_model;

    return out << std::endl;
}