#include <iostream>
#include "main.h"

int main(){
    Calculations(6, 4);
}

void Calculations(int num1, int num2) {
    SumOfNumbers(num1, num2);
    DifferenceOfNumbers(num1, num2);
    ProductOfNumbers(num1, num2);
    QuotientOfNumbers(num1, num2);
    RemainderOfNumbers(num1, num2);
}

void SumOfNumbers(int num1, int num2) {
    int sum = num1 + num2;
    std::cout << num1 << " + " << num2 << " = " << sum << '\n';
}

void DifferenceOfNumbers(int num1, int num2) {
    int difference = num1 - num2;
    std::cout << num1 << " - " << num2 << " = " << difference << '\n';
}

void ProductOfNumbers(int num1, int num2) {
    int product = num1 * num2;
    std::cout << num1 << " * " << num2 << " = " << product << '\n';
}

void QuotientOfNumbers(int num1, int num2) {
    int quotient = num1 / num2;
    std::cout << num1 << " / " << num2 << " = " << quotient << '\n';
}

void RemainderOfNumbers(int num1, int num2) {
    int quotient = num1 / num2;
    int remainder = num1 % num2;
    std::cout << "Remainder of " << num1 << " and " << num2 << " is " << remainder << '\n';
}

