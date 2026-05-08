#include "CommissionEmployee.h"
#include <iostream>

CommissionEmployee::CommissionEmployee(std::string fname, std::string lname, long long int ssn, double sales, double commission)
    : Employee{fname, lname, ssn}
    , m_grossSales(sales)
    , m_commissionRate(commission)
{}

double CommissionEmployee::getPaymentAmount() const {
    return m_grossSales * m_commissionRate;
}

void CommissionEmployee::print(std::ostream& out) const {
    out << "CommissionEmployee\n";
    Employee::print(out);
    out << "\nGross Sales: " << m_grossSales
        << "\nCommission Rate: " << m_commissionRate
        << "\nWeekly Salary: " << getPaymentAmount();
}