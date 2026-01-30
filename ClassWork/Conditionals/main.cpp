#include <iostream>

int main(){
    int num1 = 4;
    int num2;

    std::cout << "Enter a number: ";
    std::cin >> num2;

    num2 > num1 ? 
        std::cout << "Your number " << num2 << " is greater than " << num1 : 
        std::cout << "Your number " << num2 << " is less than " << num1;


    int ans = num2 > num1 ? num2 : num1;
        std::cout << std::endl << "The answer is " << ans << std::endl;

    // alternate
    if (num2 > num1) {
        ans = num2;
    } else {
        ans = num1;
    }
}
