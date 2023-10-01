#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head=n;
}
void insertAtTail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp=head;
     while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int length(node* &head){
    int l=0;
    node* temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
void deleteAtHead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}
int removeDuplicacy(node* &head,int x){
    int count=0;
    if(head==NULL){
        return 0;
    }
    if(head->data==x){
        deleteAtHead(head);
        count++;
    }
    node* temp=head;
    while(temp->next!=NULL){
        if(temp->next->data==x){
            temp->next=temp->next->next;
            count++;
        }
        else{
            temp=temp->next;
        }
    }
    return count;
}
int main()
{
    node* head=NULL;
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,5);
    insertAtTail(head,2);
    insertAtTail(head,2);
    insertAtTail(head,9);
    display(head);
    int k=2;
    int c=removeDuplicacy(head,k);
    display(head);
    cout<<"No. of "<<k<<" are "<<c<<endl;
 return 0;
}