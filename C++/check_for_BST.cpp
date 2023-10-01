#include<iostream>
#include<limits>
using namespace std;
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
//check for BST
bool isBST(Node* root, Node* min=NULL, Node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool leftValid=isBST(root->left,min,root);
    bool rightValid=isBST(root->right,root,max);
    return leftValid && rightValid;
}
int main()
{
    Node* root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(3);
    if(isBST(root1,NULL,NULL)){
        cout<<"VALID"<<endl;
    }else{
        cout<<"INVALID"<<endl;
    }
    return 0;
}
