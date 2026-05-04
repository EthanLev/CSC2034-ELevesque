#pragma once

#include <iostream>
#include <string>

class Address {
    std::string m_street;
    std::string m_city;
    std::string m_state;

public:
    Address(std::string street, std::string city, std::string state) 
        : m_street(street)
        , m_city(city)
        , m_state(state)
    {
        std::cout << "Address created" << std::endl;
    }

    ~Address() {
        std::cout << "Address destroyed" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, Address address) {
        out << address.m_street << ", " << address.m_city << ", " << address.m_state << std::endl;
        return out;
    }
};