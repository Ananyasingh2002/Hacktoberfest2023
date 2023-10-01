#include<iostream>
#include<climits>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node* constructBST(int preorder[],int* preorderidx,int key, int min, int max, int n){
    if(*preorderidx>=n){
        return NULL;
    }
    Node* root=NULL;
    if(key>min && key<max){
        root=new Node(key);
        *preorderidx=*preorderidx+1;
        if(*preorderidx<n){
            root->left=constructBST(preorder,preorderidx,preorder[*preorderidx],min,key,n);
        }
        if(*preorderidx<n){
            root->right=constructBST(preorder,preorderidx,preorder[*preorderidx],key,max,n);
        }
    }
    return root;
}
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int pre[]={10,2,1,13,11};
    int n=5;
    int preorderidx=0;
    Node* root=constructBST(pre,&preorderidx,pre[0],INT_MIN,INT_MAX,n);
    preorder(root);
 return 0;
}