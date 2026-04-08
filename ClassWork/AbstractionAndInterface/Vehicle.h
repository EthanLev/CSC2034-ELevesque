#pragma once
#include <iostream>
#include <string>

class Vehicle {
private:
    std::string m_color {};
    bool m_hasEngine {false};

public:
    Vehicle() {}
    Vehicle(std::string, bool);
    virtual ~Vehicle() {}

    std::string getColor() { return m_color; }
    bool hasEngine() { return m_hasEngine; }

    void paint(std::string color);
    virtual std::string move();
};