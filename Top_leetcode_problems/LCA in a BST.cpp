/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        if(root->val == p->val || root->val == q->val)
        {
            return root;
        }
        TreeNode*left = lowestCommonAncestor(root->left,p,q);
        TreeNode*right = lowestCommonAncestor(root->right,p,q);

        if(left ==  NULL && right == NULL)
        {
            return NULL;
        }
        if(left != NULL && right == NULL)
        {
            return left;
        }
        if(right != NULL && left == NULL)
        {
            return right;
        }
        else{
            return root;
        }
    }
};