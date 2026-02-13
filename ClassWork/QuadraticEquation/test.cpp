#include <utility>   // for std::pair
#include <cmath>     // for std::sqrt

// Solves ax^2 + bx + c = 0
// Returns a pair: first = true if real roots exist, false otherwise
// second = pair of roots (valid only if first is true)
std::pair<bool, std::pair<double, double>> solveQuadratic(double a, double b, double c) {
    if (a == 0) {
        // Not a quadratic, bx + c = 0
        if (b == 0) {
            return {false, {0, 0}}; // No solution
        } else {
            double root = -c / b;
            return {true, {root, root}};
        }
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        // No real roots
        return {false, {0, 0}};
    }

    double sqrtDisc = std::sqrt(discriminant);
    double root1 = (-b + sqrtDisc) / (2 * a);
    double root2 = (-b - sqrtDisc) / (2 * a);

    return {true, {root1, root2}};
}
