#include <iostream>
using namespace std;

int main() {
    int num, reversedNum = 0, originalNum, remainder;


    cout << "Enter an integer: ";
    cin >> num;

    originalNum = num;  

    while (num != 0) {
        remainder = num % 10;  
        reversedNum = reversedNum * 10 + remainder; 
        num /= 10;  
    }

   
    if (originalNum == reversedNum) {
        cout << originalNum << " is a palindrome." << endl;
    } else {
        cout << originalNum << " is not a palindrome." << endl;
    }

    return 0;
}
