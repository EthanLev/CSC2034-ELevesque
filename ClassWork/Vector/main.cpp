#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    
    // DECLARING AND INITIALIZING
    // empty vector
    std::vector<int> v1;

    // with or without '='
    std::vector<int> v2{1, 2, 3};

    // TRAVERSING
    for (int i = 0; i < v2.size(); i++) {
        //std::cout << v2[i] << " ";
        std::cout << v2.at(i) << " ";
    }
    std::cout << std::endl;

    for (int x : v2) {
        std::cout << x;
    }
    std::cout << std::endl;

    // INSERT AT END
    std::vector<char> vc {'b', 'c', 'a'};
    vc.push_back('e');

    for (char c : vc) {
        std::cout << c;
    }
    std::cout << std::endl;

    // INSERT AT BEGINNING
    vc.insert(vc.begin(), 'd');

    for (auto c : vc) {
        std::cout << c;
    }
    std::cout << std::endl;

    // INSERT AT INDEX
    int index = 3;
    vc.insert(vc.begin() + index, 'f');

    for (auto c : vc) {
        std::cout << c;
    }
    std::cout << std::endl;

    // REMOVE FROM END
    vc.pop_back();

    for (auto c : vc) {
        std::cout << c;
    }
    std::cout << std::endl;

    // REMOVE FROM BEGINNING
    vc.erase(vc.begin() + 3);

    for (auto c : vc) {
        std::cout << c;
    }
    std::cout << std::endl;

    // REMOVE FROM INDEX
    vc.erase(std::find(vc.begin(), vc.end(), 'c'));

    for (auto c : vc) {
        std::cout << c;
    }
    std::cout << std::endl;

    // CHECK IF EMPTY
    if (!vc.empty()) {
        std::cout << "Not empty";
    } else {
        std::cout << "Is empty";
    }
}
