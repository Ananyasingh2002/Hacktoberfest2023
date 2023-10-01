#include<iostream>
#include<vector>
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
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void calcPointers(Node* root,Node** first,Node** mid,Node** last,Node** prev){
    if(root==NULL){
        return ;
    }
    calcPointers(root->left,first,mid,last,prev);
    if(*prev && root->data<(*prev)->data){
        if(!*first){
            *first=*prev;
            *mid=root;
        }else{
            *last=root;
        }
    }
    *prev=root;
    calcPointers(root->right,first,mid,last,prev);
}
void restoreBST(Node* root){
    Node* first,*mid,*last,*prev;
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;
    calcPointers(root,&first,&mid,&last,&prev);

    //case 1
    if(first&&last){
        swap(&(first->data),&(last->data));
    }
    else if(first && mid){
        swap(&(first->data),&(mid->data));
    }
}
void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
int main()
{
    Node* root=new Node(6);
    root->left=new Node(9);
    root->right=new Node(3);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right->right=new Node(13);
    inorderPrint(root);
    cout<<endl;
    restoreBST(root);
    inorderPrint(root);
    return 0;
}