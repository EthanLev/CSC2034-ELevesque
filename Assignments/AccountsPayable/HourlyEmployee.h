#pragma once
#include "Employee.h"

class HourlyEmployee : public Employee {

private:
    double m_hourlyWage;
    int m_hours;

public:
    // Constructors
    HourlyEmployee(std::string, std::string, long long int, double, int);

    // Getters
    double getHourlyWage() const { return m_hourlyWage; }
    int getHours() const { return m_hours; }
    double getPaymentAmount() const override;
    void print(std::ostream& out) const override;

    // Setters
    void setHourlyWage(double num) { m_hourlyWage = num; }
    void setHours(int num) { m_hours = num; }

};