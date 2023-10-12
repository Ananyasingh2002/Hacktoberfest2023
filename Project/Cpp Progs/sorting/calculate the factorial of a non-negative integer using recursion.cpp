#include <iostream>

unsigned long long calculateFactorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return static_cast<unsigned long long>(n) * calculateFactorial(n - 1);
    }
}

int main() {
    int number;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> number;

    if (number < 0) {
        std::cout << "Factorial is undefined for negative numbers.\n";
    } else {
        unsigned long long factorial = calculateFactorial(number);
        std::cout << "Factorial of " << number << " is " << factorial << "\n";
    }

    return 0;
}
