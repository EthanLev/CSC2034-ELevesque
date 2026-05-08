#include "SalariedEmployee.h"
#include <iostream>

SalariedEmployee::SalariedEmployee(std::string fname, std::string lname, long long int ssn, double salary)
    : Employee{fname, lname, ssn}
    , m_weeklySalary(salary)
{}

double SalariedEmployee::getPaymentAmount() const {
    return m_weeklySalary;
}

void SalariedEmployee::print(std::ostream& out) const {
    out << "SalariedEmployee\n";
    Employee::print(out);
    out << "\nWeekly Salary: " << getPaymentAmount();
}