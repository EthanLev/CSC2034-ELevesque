#pragma once
#include "Employee.h"

class CommissionEmployee : public Employee {

private:
    double m_grossSales;
    double m_commissionRate;

public:
    // Constructors
    CommissionEmployee(std::string, std::string, long long int, double, double);

    // Getters
    double getGrossSales() const { return m_grossSales; }
    double getCommissionRate() const { return m_commissionRate; }
    double getPaymentAmount() const override;
    void print(std::ostream& out) const override;

    // Setters
    void setGrossSales(double num) { m_grossSales = num; }
    void setCommissionRate(double num) { m_commissionRate = num; }

};