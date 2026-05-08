#pragma once
#include "Employee.h"

class SalariedEmployee : public Employee {

private:
    double m_weeklySalary;

public:
    // Constructors
    SalariedEmployee(std::string, std::string, long long int, double);

    // Getters
    double getWeeklySalary() const { return m_weeklySalary; }
    double getPaymentAmount() const override;
    void print(std::ostream& out) const override;

    // Setters
    void setWeeklySalary(double num) { m_weeklySalary = num; }
};