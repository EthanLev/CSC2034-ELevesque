#pragma once

#include <iostream>

class Date {
    int m_year {};
    int m_month {};
    int m_day {};

public:
    Date() {};
    Date(int year, int month, int day); // Contructor
    Date(Date d);

    int getYear() {return m_year;}
    int getMonth() {return m_month;}
    int getDay() {return m_day;}

    void print();
};