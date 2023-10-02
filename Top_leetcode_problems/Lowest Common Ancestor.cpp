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
    vector<TreeNode*> nodeToRootPath(TreeNode* root,int value){
    if(root->val==value){
        vector<TreeNode*>path;
        path.push_back(root);
        return path;
    }
    vector<TreeNode*>result;
    if(root->left!=NULL){
       result= nodeToRootPath(root->left,value);
       if(result.size()>0){
        result.push_back(root);
       }
    }
    if(result.size()==0){
    if(root->right!=NULL){
        result=nodeToRootPath(root->right,value);
        if(result.size()>0){
        result.push_back(root);
       }
    }
    }
    return result;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>path1=nodeToRootPath(root,p->val);
        vector<TreeNode*>path2=nodeToRootPath(root,q->val);
        int i=path1.size()-1;
        int j=path2.size()-1;
        TreeNode* result=NULL;
          while(i>=0 && j>=0){
                if(path1[i]->val==path2[j]->val){
                        result=path1[i];
                    }
                    else{
                        break;
                    }
                    i--;
                    j--;
    }
        return result;
    }
};
