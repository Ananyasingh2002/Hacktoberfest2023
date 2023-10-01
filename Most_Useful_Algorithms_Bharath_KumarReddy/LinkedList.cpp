#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    
    ~Node()
    {
        // memory free
        if( this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout << "Memory Free To Use" << endl;
    }
    
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp; // pointing temp = tail element
    tail = temp;
}

void insertAtMiddile(Node* &tail,Node *&head, int data, int position)
{

    // If the position to insert the element is 1
    // then we have to use this case
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 0; // to traverse till position to insert the element
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if(temp -> next == NULL)
    {
        insertAtTail(tail,data);
        // This is to updata the data
    }

    Node *elementToInsert = new Node(data);
    elementToInsert->next = temp->next;
    temp->next = elementToInsert;
}

void deleteNode(int position, Node* &head)
{
    // deleting first or start node
    if(position == 1)
    {
        Node* temp = head;
        head = head -> next;
        // memory free
        temp -> next = NULL;
        delete temp;
    }
    // deleting any middle of last node
    else
    {
        Node* current = head;
        Node* previous = NULL;
        int count = 1;
        while (count < position)
        {
            previous = current;
            current = current -> next;
            count++;
        }
        previous -> next = current -> next;
        current -> next = NULL;
        if(previous -> next == NULL)
        {
            // tail = previous;
        }
        // Alternate tail = current;
        // tail = current;
        delete current;
    }
    
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtTail(tail, 24);
    insertAtTail(tail, 25);

    insertAtHead(head, 12);

    insertAtMiddile(tail,head, 15, 3);
    insertAtMiddile(tail,head, 10, 1);
    cout << "Head " << head -> data << " Tail " << tail -> data << endl;
    print(head);
    return 0;
}
