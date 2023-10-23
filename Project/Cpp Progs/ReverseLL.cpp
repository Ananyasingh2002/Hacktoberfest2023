//Its a program to reverse a singly linked list using three pointers

#include<iostream>
using namespace std;

class Node
{
     public:
     int data;
     Node* next;
     Node(int x)
     {
          data=x;
     }
};

void insert(Node* head, int ele)
{
     Node* ptr= new Node(ele);
     while(head->next!=NULL)
     {
          head=head->next;
     }
     head->next= ptr;
     ptr->next= NULL;
}

void disp(Node* head)
{
     cout<<"The Linked list is :\t";
     while(head!=NULL)
     {
          cout<<head->data<<"\t";
          head= head->next;
     }
     cout<<"\n";
}

Node* rev(Node* head)
{
     Node* p= head;
     Node* q= head->next;
     Node* r= q->next;
     head->next=NULL;
     while(r!=NULL)
     {
          q->next=p;
          p=q;
          q=r;
          r=r->next;
     }
          q->next=p;
     return q;
}

int main()
{
     Node* head= new Node(10);
     head->next=NULL;
     insert(head, 20);
     insert(head, 30);
     insert(head, 40);
     insert(head, 50);
     insert(head, 60);
     insert(head, 70);
     disp(head);
     head= rev(head);
     disp(head);
     return 0;
}