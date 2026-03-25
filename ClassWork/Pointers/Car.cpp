#include "Car.h"

Car::Car()
{
}

Car::Car(std::string vin, std::string make, std::string model, int year)
    : m_vin(vin)
    , m_make(make)
    , m_model(model)
    , m_year(year)
{

}

std::ostream& operator << (std::ostream& out, Car& car) {
    out
    << "VIN: " << car.m_vin
    << "Make: " << car.m_make
    << "Model: " << car.m_model
    << "Year: " << car.m_year;

    return out << std::endl;
}