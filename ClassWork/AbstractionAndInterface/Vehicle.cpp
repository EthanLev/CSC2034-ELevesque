#include "Vehicle.h"

Vehicle::Vehicle(std::string color, bool hasEngine)
    : m_color(color)
    , m_hasEngine(hasEngine)
{
    
}

Vehicle::~Vehicle() {
    
}

std::string move() {
    return "Vehicle moving";
}
