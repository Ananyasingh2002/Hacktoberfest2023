#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

bool canTypeInOneRow(const std::string& word) {
    std::unordered_set<char> row1 = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
    std::unordered_set<char> row2 = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
    std::unordered_set<char> row3 = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

    char firstChar = std::tolower(word[0]);
    std::unordered_set<char> *targetRow;

    if (row1.find(firstChar) != row1.end()) {
        targetRow = &row1;
    } else if (row2.find(firstChar) != row2.end()) {
        targetRow = &row2;
    } else {
        targetRow = &row3;
    }

    for (char c : word) {
        if (targetRow->find(std::tolower(c)) == targetRow->end()) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string inputWord;
    std::cout << "Enter a word: ";
    std::cin >> inputWord;

    if (canTypeInOneRow(inputWord)) {
        std::cout << "The word '" << inputWord << "' can be typed using only one row on a QWERTY keyboard." << std::endl;
    } else {
        std::cout << "The word '" << inputWord << "' cannot be typed using only one row on a QWERTY keyboard." << std::endl;
    }

    return 0;
}
