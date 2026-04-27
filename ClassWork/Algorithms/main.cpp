#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <list>
#include <vector>

int main(int, char**){
    std::list<int> li(6); // list of 6 integers

    // Fill list with numbers starting from 0
    std::iota(li.begin(), li.end(), 0);
    for (int i : li) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Find value in list
    auto it = std::find(std::begin(li), std::end(li), 3);
    if (it == li.end()) {
        std::cout << "Could not find value in list\n";
    } else {
        std::cout << "Found value in list at index " << std::distance(it, li.begin()) << "\n";
    }

    // Sort and reverse
    std::vector<int> vec{7, -3, 6, 2, -5, 0, 4};

    // Sort
    std::sort(vec.begin(), vec.end());
    for (int i : vec) { // for loop with iterators
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Reverse
    std::reverse(vec.begin(), vec.end());
    for (int i : vec) { // for loop with iterators
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // for_each using lambda function to increment each element
    // [capture list] (parameter list) -> return type { statements }
    std::for_each(std::begin(vec), std::end(vec), [](int& x) { x++; });

    std::for_each(std::begin(vec), std::end(vec), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    // Demonstrate capture list in lambda function
    int sum = 0; // can't see sum, add to capture list
    for_each(vec.begin(), vec.end(), [&sum](int x) { sum += x; });
    std::cout << "Sum is " << sum << std::endl;

    // Copy elements from one container to another
    std::list<int> li1(vec.size());
    std::copy(vec.begin(), vec.end(), li1.begin());
    std::for_each(li1.begin(), li1.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;

    // Transform and copy elements from one container to another
    std::list<int> li2(li1.size());
    std::transform(li1.begin(), li1.end(), li2.begin(), [](int n) { return 2 * n; });
    std::for_each(li2.begin(), li2.end(), [](int x) { std::cout << x << ' '; });
    std::cout << std::endl;
    
    // copy_if, cout_if
    auto is_negative = [](int n) { return n < 0; };
    int negCount = std::count_if(li2.begin(), li2.end(), is_negative);
    std::vector<int> vec1(negCount);
    std::copy_if(li2.begin(), li2.end(), vec1.begin(), is_negative);

    // copy, ostream_iterator
    // Copy contents of container to std::cout
    // Seperate elements with a space
    auto output = std::ostream_iterator<int>(std::cout, " ");
    std::copy(vec1.begin(), vec1.end(), output);
    std::cout << std::endl;
}
