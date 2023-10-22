//This code defines the searchMatrix function in a Solution class and then demonstrates how to use it to search for two different target values in a 2D matrix.

#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int row = 0;
        int column = matrix[0].size() - 1;
        while (column >= 0 && row <= matrix.size() - 1) {
            if (matrix[row][column] == target)
                return true;
            else if (target < matrix[row][column]) {
                column--;
            } else {
                row++;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 5;
    if (solution.searchMatrix(matrix, target)) {
        std::cout << "Target " << target << " found in the matrix." << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the matrix." << std::endl;
    }

    target = 15;
    if (solution.searchMatrix(matrix, target)) {
        std::cout << "Target " << target << " found in the matrix." << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the matrix." << std::endl;
    }

    return 0;
}
