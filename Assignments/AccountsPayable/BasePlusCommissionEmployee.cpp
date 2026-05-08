#include "BasePlusCommissionEmployee.h"
#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(std::string fname, std::string lname, long long int ssn, double sales, double commission, double basePay)
    : CommissionEmployee{fname, lname, ssn, sales, commission}
    , m_basePay(basePay)
{}

double BasePlusCommissionEmployee::getPaymentAmount() const {
    return m_basePay + CommissionEmployee::getPaymentAmount();
}

void BasePlusCommissionEmployee::print(std::ostream& out) const {
    out << "BasePlusCommissionEmployee\n";
    CommissionEmployee::print(out);
    out << "\nBase Pay: " << m_basePay;
}

void BasePlusCommissionEmployee::addRaise() {
    m_basePay *= 1.10; // 10% raise
}