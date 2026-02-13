#include <iostream>
#include <utility>
#include <cmath>

int solveQuadratic(double, double, double);

std::pair<bool, std::pair<double, double>> solveQuadratic(double a, double b, double c) {
    double bSquared4ac = b * b - 4 * a * c;
    std::pair<double, double> solutions{0.0, 0.0};
    bool hasSolution = false;

    if (bSquared4ac >= 0) {
        solutions.first = ((-b + sqrt(bSquared4ac)) / 2 * a);
        solutions.second = ((-b - sqrt(bSquared4ac)) / 2 * a);

        hasSolution = true;
    }

    return {hasSolution, solutions};
}

int main() {
    auto solution = solveQuadratic(1, -3, 2);

    if (solution.first) {
        std::cout << "Problem has solution\n" << "The roots are: " << solution.second.first << " and " << solution.second.second << std::endl;
    } else {
        std::cout << "Problem does not have a solution" << std::endl;
    }
}


