#pragma once

#include <string>
#include <iostream>
#include <Address.h>

class Person {
    std::string m_name;
    int m_age;
    std::unique_ptr<Address> m_address;

public:
    Person(std::string name, int age)
        : m_name(name)
        , m_age(age)
    {
        std::cout << "Person created" << std::endl;
    }

    ~Person() {
        std::cout << "Person destroyed" << std::endl;
    }

    std::string getName() const { return m_name; }
    int getAge() const { return m_age; }

    void setAddress(std::unique_ptr<Address> addr) {
        m_address = std::move(addr);
    }

    friend std::ostream& operator<<(std::ostream& out, const Person& p) {
        out << p.m_name << ' ' << p.m_age << std::endl;
        return out;
    }
};