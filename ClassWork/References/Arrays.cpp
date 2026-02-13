#include <iostream>
#include <array>

void printcArray(int[] , size_t);
void printStdArray(std::array<int, 3>&);

int main(int, char**){
    // C-style array
    int cArr[] {1, 2, 3};

    // C++ class for array
    std::array<int , 3> sArr {1, 2, 3};

    // Uninitialized C-style array
    std::string stNIArr[5];
    stNIArr[0] = "First";
    stNIArr[2] = "Second";
    stNIArr[3] = "Third";
    stNIArr[4] = "Fourth";

    for (size_t i = 0; i < std::size(stNIArr); i++) {
        //std::cout << stNIArr[i] << '\n';
    }  
    //std::cout << std::endl;

    for (size_t i = 0; i < sizeof(cArr) / sizeof(int); i++) {
        //std::cout << cArr[i] << ' ';
    }
    //std::cout << std::endl;

    for (auto x : stNIArr) {
        //std::cout << x << '\n';
    }
    //std::cout << std::endl;

    int nums[5];
    nums[0] = 0;
    nums[2] = 2;
    nums[3] = 3;
    nums[4] = 4;

    for (int num : nums) {
        //std::cout << num << '\n';
    }
    //std::cout << std::endl;

    printcArray(cArr, std::size(cArr));
    printStdArray(sArr);

    std::cout << "Original array: ";
    for (int num : sArr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void printcArray(int arr[], size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << '\n';
    }

    std::cout << std::endl;
}

// & passes reference so array isn't copied
void printStdArray(const std::array<int, 3>& arr) {
    // std::cout << "Standard Array: ";

    // for (size_t i = 0; i < arr.size(); i++) {
    //     arr[i] *= 2;
    // }

    for (int num : arr) {
        std::cout << num << " ";
    }

    std::cout << '\n' << "Size: " << arr.size();
    std::cout << std::endl;
}
