#include <iostream>

int main(){
    // unsigned int age;

    // std::cout << "Enter an age: ";
    // std::cin >> age;

    // while (age < 0) {
    //     std::cout << "invalid age";
    //     continue;
    // }

    // std::cout << "valid age";


    // do this while this is true
    // do {
    //     std::cout << "Enter an age: ";
    //     std::cin >> age;
    // } while (age < 0);

    enum class Food {
        APPLE,
        BANANA,
        PEACH,
        WATERMELON,
        CABBAGE,
        CARROT
    };

    enum class Fruit {
        APPLE,
        BANANA,
        PEACH
    };

    Food food = Food::APPLE;
    // std::cout << static_cast<int>(food); // static cast to int
    // std::cout << (int)(food); // old cast

    switch (food) {
        case Food::APPLE:
        case Food::BANANA:
        case Food::PEACH:
        case Food::WATERMELON:
            std::cout << "FRUIT";
            break;

        case Food::CABBAGE:
        case Food::CARROT:
            std::cout << "VEGETABLE";
            break;

        default:
            std::cout << "N/A";
            break;
    }

    std::cout << '\n';
}
