#include<iostream>
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
Node* insertBST(Node* root,int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }else{
        //val>root->data
        root->right=insertBST(root->right,val);
    }
    return root;
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node* searchInBST(Node* root,int k){
    if(root==NULL){
        return NULL;
    }
    if(root->data==k){
        return root;
    }
    if(root->data>k){
        return searchInBST(root->left,k);
    }
    return searchInBST(root->right,k);
}
Node* inorderSucc(Node* root){
    Node* curr=root;
    while(curr&&curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* deleteInBST(Node* root,int k){
    if(k<root->data){
        root->left=deleteInBST(root->left,k);
    }
    else if(k>root->data){
        root->right=deleteInBST(root->right,k);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        //case 3
        Node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteInBST(root->right,temp->data);
    }
    return root;
}
int main()
{
    // Node* root=NULL;
    // root=insertBST(root,5);
    // insertBST(root,1);
    // insertBST(root,3);
    // insertBST(root,4);
    // insertBST(root,2);
    // insertBST(root,7);
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);
    //print inorder
    inorder(root);
    cout<<endl;
    // if(searchInBST(root,5)==NULL){
    //     cout<<"Not Found"<<endl;
    // }else{
    //     cout<<"Found"<<endl;
    // }
    deleteInBST(root,2);
    inorder(root);
 return 0;
}