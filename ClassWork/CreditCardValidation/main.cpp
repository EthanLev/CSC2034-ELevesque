#include <iostream>

bool isValid(unsigned long long int num);

int main(){
    bool continueProgram = true;

    while (continueProgram == true) {
        unsigned long long int cardNumber;
        int result = 0;

        std::cout << "Enter a c/c number: ";

        std::cin >> cardNumber;

        if (std::cin.fail()) {
            std::cout << "Not a valid c/c number\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        } else {
            std::cin.ignore(1000, '\n');
            
            //isValid(cardNumber);

            std::cout << "Enter another c/c number? (Y/N)\n";

            char ans;
            std::cin >> ans;
            if (ans == 'N' || ans == 'n') {
                continueProgram = false;
            } else if (ans == 'Y'|| ans == 'y') {
                continue;
            } else {
                std::cout << "Not a valid response\n";
            }
        }
    }
}

bool isValid(unsigned long long int num) {
    if (num < 13 || num > 16) return false;

    // extract first digit
    // extract first two digits

    // determine card type
    // first digit is 4 -> Visa
    // first digit is 5 -> MasterCard
    // first digits are 37 -> American Express
    // first digit is 6 -> Discover
    // None = invalid

    return true;
}

