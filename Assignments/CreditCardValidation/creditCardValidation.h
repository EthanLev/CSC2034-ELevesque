#include <iostream>
#include <vector>

using namespace std;

enum CardType
{
    INVALID,
    VISA,
    MASTERCARD,
    AMEX,
    DISCOVER
};

int getDigit(int);
int sumOfOddPlace(unsigned long long int);
int sumOfDoubleEvenPlace(unsigned long long int);
bool prefixMatched(unsigned long long int number, int d);
int getSize(unsigned long long int);
unsigned long long int getPrefix(unsigned long long int number, int k);
bool isValid(unsigned long long int);
CardType getCardType(unsigned long long int num);