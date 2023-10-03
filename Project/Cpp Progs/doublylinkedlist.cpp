#include<iostream>
using namespace std;

struct node
{
  int num;
  struct node *preptr;
  struct node *nextptr;
} *stnode, *ennode;

void DlListcreation (int n);
void DlLinsertNodeAtBeginning (int num);
void displayDlList ();

int main ()
{
  int n, num1;
  stnode = NULL;
  ennode = NULL;

  cout << "Enter the number of nodes : ";
  cin >> n;
  DlListcreation (n);
  displayDlList ();
  cout << " Input data for insertion at beginning : ";
  cin >> num1;
  DlLinsertNodeAtBeginning (num1);
  displayDlList ();
  return 0;
}

void DlListcreation (int n)
{
    int i, num;
    struct node *fnNode;
    if (n >= 1)
    {
      stnode = (struct node *) malloc (sizeof (struct node));

      if (stnode != NULL)
	  {
	      cout << " Input data for node 1 : ";	
	      // assigning data in the first node
	      cin >> num;

	      stnode->num = num;
	      stnode->preptr = NULL;
	      stnode->nextptr = NULL;
	      ennode = stnode;
	      for (i = 2; i <= n; i++)
	      {
	         fnNode = (struct node *) malloc (sizeof (struct node));
	         if (fnNode != NULL)
		     {
		        cout << " Input data for node " << i << ": ";
		        cin >> num;
		        fnNode->num = num;
		        fnNode->preptr = ennode;	
		        // new node is linking with the previous node
		        fnNode->nextptr = NULL;
		        ennode->nextptr = fnNode;	
		        // previous node is linking with the new node
		        ennode = fnNode;	
		        // assign new node as last node
		     }
	         else
		     {
		        cout << " Memory can not be allocated.";
		        break;
		     }
	      }
	  }
      else
	  {
	     cout << " Memory can not be allocated.";
	  }
    }
}

void DlLinsertNodeAtBeginning (int num)
{
  struct node *newnode;
  if (stnode == NULL)
  {
    cout << " No data found in the list\n";
  } 
  else
  {
    newnode = (struct node *) malloc (sizeof (struct node));
    newnode->num = num;
    newnode->nextptr = stnode;	
    // next address of new node is linking with starting node
    newnode->preptr = NULL;	
    // set previous address field of new node is NULL
    stnode->preptr = newnode;	
    // previous address of starting node is linking with new node
    stnode = newnode;		
    // set the new node as starting node
  }
}

void displayDlList ()
{
  struct node *tmp;
  tmp = stnode;
  int n = 1;
  while (tmp != NULL)
  {
    cout << " node " << n << ": " << tmp->num << "\n";
    n++;
    tmp = tmp->nextptr;
  }
}
