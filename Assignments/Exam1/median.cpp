#include "median.h"

int main() {
    std::vector<double> nums;
    collectData(nums);

    if (nums.empty()) {
        std::cout << "No data entered.\n";
        return 0;
    }

    double median = findMedian(nums);
    std::cout << "Median: " << median << std::endl;
}

void collectData(std::vector<double>& nums) {
    while (true) {
        double num;
        std::cout << "Enter numbers one at a time. Enter a negative number to continue: ";
        std::cin >> num;

        if (num < 0)
            break;

        nums.push_back(num);
    }

    std::sort(nums.begin(), nums.end());
    printArray(nums);
}

double findMedian(const std::vector<double>& nums) {
    size_t size = nums.size();
    size_t middle = size / 2;

    if (size % 2 == 1)
        // odd number of data points, the median is the middle number
        return nums[middle];
    else
        // even number of data points, the median is the average of the two middle numbers
        return (nums[middle - 1] + nums[middle]) / 2.0;
}

void printArray(const std::vector<double>& nums) {
    for (double n : nums)
        std::cout << n << " ";
    std::cout << std::endl;
}