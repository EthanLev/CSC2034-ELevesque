#pragma once
#include <string>
#include <iostream>

class Employee {

private:
    std::string m_fname;
    std::string m_lname;
    long long int m_ssn;

public:
    // Constructors
    Employee(std::string, std::string, long long int);

    // Getters
    std::string getFirstName() const { return m_fname; }
    std::string getLastName() const { return m_lname; }
    int getSSN() const { return m_ssn; }

    // Setters
    void setFirstName(std::string fname) { m_fname = fname; }
    void setLastName(std::string lname) { m_lname = lname; }
    void setSSN(long long int ssn) { m_ssn = ssn; }

    virtual double getPaymentAmount() const;
    virtual void print(std::ostream& out) const;
    virtual void addRaise() {}

    friend std::ostream& operator<<(std::ostream& out, Employee& e);
};