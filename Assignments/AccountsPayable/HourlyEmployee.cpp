#include "HourlyEmployee.h"
#include <iostream>

HourlyEmployee::HourlyEmployee(std::string fname, std::string lname, long long int ssn, double wage, int hours)
    : Employee{fname, lname, ssn}
    , m_hourlyWage(wage)
    , m_hours(hours)
{}

double HourlyEmployee::getPaymentAmount() const {
    return m_hourlyWage * m_hours;
}

void HourlyEmployee::print(std::ostream& out) const {
    out << "HourlyEmployee\n";
    Employee::print(out);
    out << "\nHourly Wage: " << m_hourlyWage
        << "\nHours: " << m_hours
        << "\nWeekly Salary: " << getPaymentAmount();
}