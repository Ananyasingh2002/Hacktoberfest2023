#include <iostream>
using namespace std;

// Structure to represent a single element in the sparse matrix
struct Node {
    int row, col, value;
    Node* next;
};

// Class to represent the sparse matrix
class SparseMatrix {
private:
    int rows, cols;
    Node** matrix;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {
        matrix = new Node*[r];
        for (int i = 0; i < r; i++) {
            matrix[i] = nullptr;
        }
    }

    // Function to insert an element into the matrix
    void insert(int r, int c, int val) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node{r, c, val};
        newNode->next = matrix[r];
        matrix[r] = newNode;
    }

    // Function to display the sparse matrix
    void display() {
        for (int i = 0; i < rows; i++) {
            Node* current = matrix[i];
            for (int j = 0; j < cols; j++) {
                if (current && current->col == j) {
                    cout << current->value << " ";
                    current = current->next;
                } else {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int rows = 3, cols = 4;
    SparseMatrix matrix(rows, cols);

    matrix.insert(0, 0, 1);
    matrix.insert(0, 2, 2);
    matrix.insert(1, 1, 3);
    matrix.insert(2, 3, 4);

    cout << "Sparse Matrix:" << endl;
    matrix.display();

    return 0;
}
