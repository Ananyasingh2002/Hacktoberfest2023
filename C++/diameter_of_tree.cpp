#include<iostream>
#include<queue>
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
// int height(Node* root){
//     if(root==NULL){
//         return 0;
//     }
//     int lheight=height(root->left);
//     int rheight=height(root->right);
//     return max(lheight,rheight)+1;
// }
// int diam(Node* root){
//     if(root==NULL){
//         return 0;
//     }
//     int lheight=height(root->left);
//     int rheight=height(root->right);
//     int currDiam=lheight+rheight+1;
//     int ldiam=diam(root->left);
//     int rdiam=diam(root->right);
//     return max(currDiam,max(ldiam,rdiam));
// }
int diam(Node* root,int* height){
    if(root==NULL){
        *height=0;
        return 0;
    }
    int lh=0;int rh=0;
    int ldiam=diam(root->left,&lh);
    int rdiam=diam(root->right,&rh);
    int currDiam=lh+rh+1;
    *height=max(lh,rh)+1;
    return max(currDiam,max(ldiam,rdiam));
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    int height=0;
    cout<<diam(root,&height);
    return 0;
}