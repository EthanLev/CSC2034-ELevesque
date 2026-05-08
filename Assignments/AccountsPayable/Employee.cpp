#include "Employee.h"
#include <iostream>

Employee::Employee(std::string fname, std::string lname, long long int ssn)
    : m_fname(fname)
    , m_lname(lname)
    , m_ssn(ssn)
{}

double Employee::getPaymentAmount() const {
    return 0.0;
}

void Employee::print(std::ostream& out) const {
    out
        << "First Name: " << m_fname
        << "\nLast Name: " << m_lname
        << "\nSSN: " << m_ssn;
}

std::ostream& operator<<(std::ostream& out, Employee& e) {
    e.print(out);
    return out << std::endl;
}

