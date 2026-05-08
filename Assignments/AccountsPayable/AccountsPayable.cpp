#include <iostream>
#include <vector>
#include <algorithm>

#include "Employee.h"
#include "SalariedEmployee.h"
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

std::vector<Employee*> payableEmployees;

void AccountPayable(Employee& e);

int main(int, char**){
    SalariedEmployee e1 {"Ethan", "Levesque", 1234567890, 1200.00};
    CommissionEmployee e2 {"Ethan", "Levesque", 1234567890, 5000.00, 2.5};
    HourlyEmployee e3 {"Ethan", "Levesque", 1234567890, 30.00, 40};
    BasePlusCommissionEmployee e4 {"Ethan", "Levesque", 1234567890, 3000.00, 1.5, 2500.00};

    // Add employees to vector
    payableEmployees.push_back(&e1);
    payableEmployees.push_back(&e2);
    payableEmployees.push_back(&e3);
    payableEmployees.push_back(&e4);

    // Add 10% raise to BasePlusCommissionEmployee's
    for (Employee* ref : payableEmployees) {
        ref->addRaise(); // function only in BasePlusCommossionEmployee class
    }

    // Sort by payment amount
    std::sort(payableEmployees.begin(), payableEmployees.end(),
        [](const Employee* a, const Employee* b) { // couldn't get it to work without pointers
            return a->getPaymentAmount() < b->getPaymentAmount();
        });

    // Traverse and print employees
    for (Employee* e : payableEmployees) {
        AccountPayable(*e);
    }
}

void AccountPayable(Employee& e) {
    std::cout << e << std::endl;
}
