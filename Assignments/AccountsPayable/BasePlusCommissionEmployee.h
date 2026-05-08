#pragma once
#include "CommissionEmployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee {

private:
    double m_basePay;

public:
    // Constructors
    BasePlusCommissionEmployee(std::string, std::string, long long int, double, double, double);

    // Getters
    double getBasePay() const { return m_basePay; }
    double getPaymentAmount() const override;
    void print(std::ostream& out) const override;
    void addRaise() override;

    // Setters
    void setBasePay(double num) { m_basePay = num; }

};