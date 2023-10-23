//Its a program to check if a singly linked list of characters is palindrome or not

#include<iostream>
using namespace std;

class Node
{
     public:
     char data;
     Node* prev;
     Node* next;
     Node(char x)
     {data=x;}
};

void insert(Node* head, char x)
{
     Node* ptr= new Node(x);
     while(head->next!=NULL)
     {
          head= head->next;
     }
     head->next=ptr;
     ptr->prev=head;
     ptr->next=NULL;
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

void palindrome(Node* head)
{
     int a=0, b=0;
     if(head==NULL)
     {
          cout<<"Palindrome";
          return;
     }
     Node* tail=head;
     while(tail->next!=NULL)
     {
          b++;
          tail=tail->next;
     }
     while(a<=b)
     {
          if(head->data!=tail->data)
          {
               cout<<"Not Palindrome\n";
               return;
          }
          head=head->next;
          tail=tail->prev;
          a++;b--;
     }
     cout<<"Palindrome\n";
}

int main()
{
     Node* head= new Node('A');
     head->next=NULL;
     insert(head,'B');
     insert(head,'C');
     insert(head,'B');
     palindrome(head);
     insert(head,'A');
     traversal(head);
     palindrome(head);
     insert(head,'B');
     palindrome(head);
     return 0;
}