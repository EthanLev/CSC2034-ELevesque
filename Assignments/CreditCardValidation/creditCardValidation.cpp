#include "creditCardValidation.h"

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
            CardType type = getCardType(cardNumber);

            switch (type) {
                case VISA:          cout << "Valid Visa" << endl; break;
                case MASTERCARD:    cout << "Valid Mastercard" << endl; break;
                case DISCOVER:      cout << "Valid Discover" << endl; break;
                case AMEX:          cout << "Valid American Express" << endl; break;
                default:            cout << "Valid number, unknown issuer" << endl; break;
            
            }
        } else {
            cout << "Invalid card number" << endl;
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

// checks if a card number passes Luhn check
bool isValid(unsigned long long int num) {
    // fails if prefix or length is invalid
    if (getCardType(num) == INVALID)
        return false;

    int sum = sumOfDoubleEvenPlace(num) + sumOfOddPlace(num);

    return (sum % 10 == 0);
}

// adds digits if number has 2 digits
int getDigit(int num) {
    if (num < 10) 
        return num; // already single digit

    return num / 10 + num % 10; // split and add digits
}

// counts how many digits in number
int getSize(unsigned long long int num) {
    int count = 0;

    while (num > 0) {
        count ++; // count
        num /= 10; // remove last digit
    }

    return count;
}

// returns first k digits of number
unsigned long long int getPrefix(unsigned long long int num, int k) {
    int size = getSize(num);

    if (size <= k) 
        return num; // number already as short as k

    // remove digits from end until k digits left
    for (int i = 0; i < size - k; i++) {
        num /= 10;
    }

    return num;
}

// checks if number starts with a certain prefix
bool prefixMatched(unsigned long long int num, int d)
{
    int prefixLength = getSize(d);      // how many digits in d
    return getPrefix(num, prefixLength) == d;
}

// returns the type of credit card  from number
CardType getCardType(unsigned long long int num) {
    int size = getSize(num);

    // check card num length
    if (size < 13 || size > 16) {
        return INVALID;
    }

    // get prefixes
    unsigned long long int firstDigit = getPrefix(num, 1);
    unsigned long long int firstTwo = getPrefix(num, 2);

    if (firstDigit == 4)
        return VISA;
    
    if (firstDigit == 5)
        return MASTERCARD;

    if (firstDigit == 6) 
        return DISCOVER;

    if (firstTwo == 37) 
        return AMEX;

    return INVALID;
}

// returns sum of digits in off place
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

// returns the sum of doubled digits in even place
int sumOfDoubleEvenPlace(unsigned long long int num) {
    int sum = 0;

    num /= 10; // remove last digit so second digit is last digit (even)

    while (num > 0) {

        int digit = num % 10; // last digit of num is now the even place
        digit *= 2;           // even place digits get doubled

        // if result is 2 digits, split and add those digits
        digit = getDigit(digit);

        sum += digit; // add to total sum

        num /= 100; // remove two digits, the one we used and the next (odd)
                    // jumps to next even place
    }

    return sum;
}


