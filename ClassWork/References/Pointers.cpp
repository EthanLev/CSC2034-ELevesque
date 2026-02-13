#include <iostream>

void addToVal(int* ptr);
double* findElement(double arr[], int size, double val);

int main() {
    int x{563}; // Assigned to some location on the stack, compiler knows how to handle it

    int& refX{x}; // Alias to x, compiler does same as above

    int* ptrX = &x; // Pointer to x, & is "address of" operator

    std::cout << "Address of x: " << ptrX << std::endl;

    std::cout << "Size of address: " << sizeof(ptrX) << std::endl;

    std::cout << "Dereference address of: " << *ptrX << std::endl;

    double val = 3.765;
    double* ptrG; // Holds garbage value, always initialize pointers
    double* ptrN{}; // Null pointer
    double* ptrVal{&val}; // Initialized to address of val

    ptrG = &val;

    std::cout << "Dereference ptrG: " << *ptrG << std::endl;

    double newVal = 9.45;
    double& refToVal{val};
    refToVal = newVal; // This is not a change of reference, it's an assignment
                       // Everything set to 9.45

    // Pointers can be redirected
    ptrVal = &newVal; // ptrVal = &val = 3.765 -> ptrVal = &newVal = 9.45

    *ptrVal = 345.67; // *... find what is in where pointer is at


    int value = 34;
    std::cout << "Value = " << value << std::endl;
    addToVal(&value);
    std::cout << "Value after modify = " << value << std::endl;

    double arr[] {1.1, 2.2, 3.3, 4.4};
    double* valPtr = findElement(arr, std::size(arr), 2);

    if (valPtr != nullptr) { // Or if(valPtr) -> will return true or false
        std::cout << "Value is: " << *valPtr << std::endl;
    }
}

void addToVal(int* ptr) {
    *ptr = *ptr + 5; // Read from location, add, and reinsert into location
}

double* findElement(double *arr, size_t size, int index) {
    double* ptr = arr;
    double* retPtr{nullptr};

    for (size_t i = 0; i < size; i++) {
        if (*ptr == index) {
            retPtr = ptr;
            break;
        }

        ptr++;
    }

    return retPtr;
}