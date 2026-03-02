#include "Date.h"

Date::Date(int year, int month, int day) // Initializer list
    :m_year{year},
     m_month{month},
     m_day{day}
{ 
}

Date::Date(Date& d) {
    m_year = d.m_year;
    m_month = d.m_month;
    m_day = d.m_day;
}

void Date::print() {
    std::cout << "Date: " << m_year << "/" << m_month << "/" << m_day << '\n';
}