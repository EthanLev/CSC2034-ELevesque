#include "Calculator.h"

template <typename T>
T Calculator<T>::add(T a, T b) { return a + b; }

template <typename T>
T Calculator<T>::subtract(T a, T b) { return a - b; }

template <typename T>
double Calculator<T>::divide(T a, T b) { return a / b; }

template <typename T>
double Calculator<T>::multiply(T a, T b) { return a * b; }