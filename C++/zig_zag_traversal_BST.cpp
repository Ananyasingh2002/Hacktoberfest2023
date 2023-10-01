#include<iostream>
#include<stack>
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
void zigzagTraversal(Node* root){
    if(root==NULL){
        return;
    }
    stack<Node*> currLvl;
    stack<Node*> nextLvl;
    bool leftToRight=true;
    currLvl.push(root);
    while(!currLvl.empty()){
        Node* temp=currLvl.top();
        currLvl.pop();

        if(temp){
        cout<<temp->data<<" ";
        if(leftToRight){
            if(temp->left){
                nextLvl.push(temp->left);
            }
            if(temp->right){
                nextLvl.push(temp->right);
            }
        }
        //Right to left
        else{
            if(temp->right){
                nextLvl.push(temp->right);
            }
            if(temp->left){
                nextLvl.push(temp->left);
            }
        }
        }
        if(currLvl.empty()){
            leftToRight=!leftToRight;
            swap(currLvl,nextLvl);
        }
    }
}
int main(int argc, char const *argv[])
{
    Node* root=new Node(12);
    root->left=new Node(9);
    root->right=new Node(15);
    root->left->left=new Node(5);
    root->left->right=new Node(10);
    zigzagTraversal(root);
    cout<<endl;
    return 0;
}