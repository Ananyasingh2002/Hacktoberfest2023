//A simple program to implement three types of traversals in trees

#include<iostream>
using namespace std;

class Node
{
     public:
     int data;
     Node* left;
     Node* right;
     Node(int x)
     {
          data=x;
     }
};

Node* insert(int x)
{
     Node* ptr= new Node(x);
     ptr->left=NULL;
     ptr->right=NULL;
     return ptr;
}

void preOrder(Node* root)
{
     if(root!=NULL)
     {
          cout<<root->data<<'\t';
          preOrder(root->left);
          preOrder(root->right);
     }
}

void postOrder(Node* root)
{
     if(root!=NULL)
     {
          postOrder(root->left);
          postOrder(root->right);
          cout<<root->data<<'\t';
     }
}

void inOrder(Node* root)
{
     if(root!=NULL)
     {
          inOrder(root->left);
          cout<<root->data<<'\t';
          inOrder(root->right);
     }
}

int main()
{
     Node* root= insert(1); //N1
     Node* N2= insert(2);
     Node* N3= insert(3);
     Node* N4= insert(4);
     Node* N5= insert(5);

     root->left= N2;
     root->right= N3;
     N2->left= N4;
     N2->right= N5;
     
     /* Tree Structure:
               1
             /  \
            2    3
          /  \   
         4    5
     */

     cout<<"PreOrder Traversal\n";
     preOrder(root);
     cout<<"\nPostOrder Traversal\n";
     postOrder(root);
     cout<<"\nInOrder Traversal\n";
     inOrder(root);
     return 0;
}