#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isEvenOddTree(TreeNode* root) {
    if (!root) return true;

    queue<TreeNode*> q;
    q.push(root);
    int level = 0; // Initialize the level counter.

    while (!q.empty()) {
        int n = q.size();
        vector<int> level_vals;

        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();
            level_vals.push_back(node->val);

            if (level % 2 == 0) {
                // Even level, values should be strictly increasing.
                if (i > 0 && node->val <= level_vals[i - 1]) return false;
            } else {
                // Odd level, values should be strictly decreasing.
                if (i > 0 && node->val >= level_vals[i - 1]) return false;
            }

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        // Check for even or odd level.
        level++;
    }

    return true;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(10);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(7);

    bool result = isEvenOddTree(root);
    if (result) {
        cout << "The given tree is an even-odd tree." << endl;
    } else {
        cout << "The given tree is not an even-odd tree." << endl;
    }

    // Don't forget to free the memory allocated for the tree nodes.
    delete root->left->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
