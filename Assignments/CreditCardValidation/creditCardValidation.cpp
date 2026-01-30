#include <iostream>
#include <vector>
#include "creditCardValidation.h"

using namespace std;

/*
    Number must have between 13 and 16 digits
    4 for Visa
    37 for American Express
    5 for Master Card
    6 for Discover
    
    1. Double every second digit from right to left
       If result is two-digit number, 
       add up the two digits to get single digit
    2. Add all single-digit numbers from Step 1
    3. Add all digits in odd places from right to left
    4. Sum the results from Step 2 and Step 3
    5. If result from Step 4 is divisible by 10,
       the card number is valid;
       otherwise it is invalid
*/

int main() {
    bool continueProgram = true;

    while (continueProgram) {
        unsigned long long int cardNumber;

        cout << "Enter a c/c number: ";
        cin >> cardNumber;

        // check if user entered a number
        if (cin.fail()) { // input failed (typed letter)
            cin.clear(); // clear bad state so we can re-read

            char discard;
            cin >> discard; // read input buffer and remove unwanted character
            cout << "Invalid input, credit card number is made up of integers" << endl;
            continue; // restart loop
        }

        if (isValid(cardNumber)) {
            cout << cardNumber << " is a valid credit card number" << endl;
        } else {
            cout << cardNumber << " is an invalid credit card number" << endl;
        } 

        cout << "Enter another c/c number? (Y/N)" << endl;

        char ans;
        cin >> ans;

        if (ans == 'N' || ans == 'n') {
            continueProgram = false;
        } else if (ans == 'Y' || ans == 'y') {
            continue;
        } else {
            cout << "Not a valid response" << endl;
            continueProgram = false;
        }
    }
}

bool isValid(unsigned long long int num) {
    if (num < 13 || num > 16) return false;

    int result = 0;

    result = sumOfDoubleEvenPlace(num) + sumOfOddPlace(num);

    // cout << "Result: " << result << endl;

    if (result % 10 == 0) {
        return true;
    } else {
        return false;
    }
}

int getDigit(int num) {
    return 0;
}

int sumOfOddPlace(unsigned long long int num) {
    int sum = 0; 

    // starts at the last digit (odd)
    while (num > 0) {

        int digit = num % 10; // last digit of num is now the odd place

        sum += digit; // add to total sum (no doubling)

        num /= 100; // remove two digits, the one we used and the next (even)
                    // jumps to next even place
    }

    return sum;
}

int sumOfDoubleEvenPlace(unsigned long long int num) {
    int sum = 0;

    num /= 10; // remove last digit so second digit is last digit (even)

    while (num > 0) {

        int digit = num % 10; // last digit of num is now the even place
        digit *= 2;           // even place digits get doubled

        // if result is 2 digits, split and add those digits
        if (digit > 9) 
            digit = digit / 10 + digit % 10; // seperate each digit

        sum += digit; // add to total sum

        num /= 100; // remove two digits, the one we used and the next (odd)
                    // jumps to next even place
    }

    return sum;
}


