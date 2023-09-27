#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to calculate modular exponentiation
long long mod_pow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

// Function to perform the Fermat's Lettle primality test
bool is_prime(long long n, int testCount) {
    if (n <= 1)
        return false; // Numbers less than or equal to 1 are not prime

    if (n <= 3)
        return true; // 2 and 3 are prime numbers

    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < testCount; i++) {
        long long a = 1 + rand() % (n - 1); // Generate a random witness
        if (mod_pow(a, n - 1, n) != 1)
            return false; // If the test fails, n is not prime
    }

    return true; // If all tests pass, n is probably prime
}

int main() {
    string ch;
    while (true) {
        cout << "\n1: Check Prime or Not\n2: Exit\nEnter your Choice: ";
        cin >> ch;
        if (ch == "1") {
            long long a;
            int test;
            cout << "\nEnter the Number: ";
            cin >> a;

            cout << "\nEnter Number of Tests: ";
            cin >> test;

            if (is_prime(a, test)) {
                cout << "\nThe Number " << a << " is Probably Prime\n";
            } else {
                cout << "\nThe Number " << a << " is Not Prime\n";
            }
        } else if (ch == "2") {
            cout << "\nThanks for Using the Program\n";
            break; // Exit the program
        } else {
            cout << "\nWrong Choice. Try Again\n";
        }
    }

    return 0; // Exit the program
}
