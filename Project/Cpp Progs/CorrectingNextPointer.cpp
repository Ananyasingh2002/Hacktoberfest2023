//Its a program to correct a single wrongly pointed 'next' pointer in a doubly linked list and can also break a cycle

#include<iostream>
using namespace std;

class Node
{
     public:
     int data;
     Node* prev;
     Node* next;
     Node(int x)
     {data=x;}
};

Node* insert(Node* head, int x)
{
     Node* ptr= new Node(x);
     while(head->next!=NULL)
     {
          head= head->next;
     }
     head->next=ptr;
     ptr->prev=head;
     ptr->next=NULL;
     return ptr;
}

void traversal(Node* head)
{
     if(head==NULL)
     cout<<"Empty linked list";
     while(head!=NULL)
     {
          cout<<head->data<<"\t";
          head=head->next;
     }
}

void random(Node* head, Node* tail)
{
     Node* temp= head;
     while(temp->next!=NULL)
     {
          int var= temp->data;
          if(temp->next->prev!=temp)
          {
               while(tail->prev->data!=var)
               {tail=tail->prev;}
               temp->next=tail;
               break;
          }
          temp=temp->next;
     }
     cout<<"Error corrected!"<<endl;
}

int main()
{
     Node* head= new Node(10);
     head->next=NULL;
     Node* P1= insert(head,20);
     Node* P2= insert(head,30);
     Node* P3= insert(head,40);
     Node* P4= insert(head,50);
     Node* P5= insert(head,60);
     Node* tail= insert(head,70);
     P1->next = P5;
     random(head, tail);
     traversal(head);
     return 0;
}
