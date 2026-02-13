#include <iostream>
#include <array>

void print(int&);
void printArr(std::array<int, 10>&);

int main() {
    int x{4};

    int& y{x};

    int z = 98;

    //print(z);

    std::array<int, 10> array;

    for (size_t i = 0; i < array.size(); i++) {
        array[i] = i;
    }

    printArr(array);

    for (int& num : array) {
        num = num * 2;
    }

    printArr(array);
}

void print(int& num) {
    std::cout << "Value: " << num << std::endl;
}

void printArr(std::array<int, 10>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }

    std::cout << std::endl;
}