#include <iostream>

void foo();

struct IArray {
    int* arr;
    size_t size;
};

int main(int, char**) {

    int arr[] {1, 2, 3, 4, 5};

    size_t length = 5;
    int* dArr = new int[]{1, 2, 3, 4, 5};

    delete [] dArr;

    int arr[] {1, 2, 3};
    IArray arr1{arr, length};

    IArray arr2 {new int[] {1, 2, 3}, 3};
    delete [] arr2.arr;

}
