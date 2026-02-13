#include <iostream>
#include <string>

int main(){
    // Initialize string
    std::string str = {"Hello"};

    std::cout << str << std::endl;



    // Traverse through string
    // With index
    for (int i = 0; i < str.size(); i++) {
        std::cout << str[i];
    }

    std::cout << std::endl;

    // Enhanced for loop
    for (char c : str) {
        std::cout << c;
        std::cout << '\n';
    }

    std::cout << std::endl;

    // Using iterators
    for (auto it = str.begin(); it != str.end(); it++) {
        std::cout << *it;
    }

    std::cout << std::endl;



    // Accessing characters
    char third = str[2]; // 3rd character in string
    std::cout << "Third character is " << third << std::endl;

    char last = str[str.size() - 1];
    std::cout << "Last character is " << last << std::endl;

    char second = str.at(2);
    std::cout << "Second character is " << second << std::endl;



    // String length
    std::cout << "String size: " << str.size() << std::endl;
    std::cout << "String length: " << str.length() << std::endl;



    // Concat strings
    std::string str1 = "Hello";
    std::string str2 = ", ";
    std::string str3 = "World";

    std::string greeting = str1 + str2 + str3;
    std::cout << greeting << std::endl;

    // Concat with append
    std::string greeting1 = str1.append(str2).append(str3);
    std::cout << greeting1 << std::endl;



    // Modify string
    std::string greet = "Hello";

    // Add character at end
    greet.push_back('!');
    std::cout << greet << std::endl;

    // Remove character at end
    greet.pop_back();
    std::cout << greet << std::endl;



    // Inserting a sub string
    std::string myString = "Hello World";

    // Insert at index 5
    myString.insert(5, " C++");
    std::cout << myString << std::endl;

    // Remove sub string
    myString.erase(5, 4);
    std::cout << myString << std::endl;

    // Get substring ("World")
    std::string result = myString.substr(6, 10);
    std::cout << result << std::endl;

    // Searching in a string
    int pos = myString.find("World");
    if (pos < myString.length()) {
        std::cout << pos << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }
}
