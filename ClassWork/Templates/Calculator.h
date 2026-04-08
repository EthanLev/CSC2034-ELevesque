#pragma once

template <typename T>
class Calculator {
public:
    T add(T a, T b);
    T subtract(T a, T b);
    double divide(T a, T b);
    double multiply(T a, T b);
};

#include "Calculator.tpp"