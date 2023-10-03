// C++ Program to sort a linked list 0s, 1s or 2s
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
	public:
	int data;
	Node* next;
};

// Function to sort a linked list of 0s, 1s and 2s
void sortList(Node *head)
{
	int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0
	Node *ptr = head;

	/* count total number of '0', '1' and '2'
	* count[0] will store total number of '0's
	* count[1] will store total number of '1's
	* count[2] will store total number of '2's */
	while (ptr != NULL)
	{
		count[ptr->data] += 1;
		ptr = ptr->next;
	}

	int i = 0;
	ptr = head;

	/* Let say count[0] = n1, count[1] = n2 and count[2] = n3
	* now start traversing list from head node,
	* 1) fill the list with 0, till n1 > 0
	* 2) fill the list with 1, till n2 > 0
	* 3) fill the list with 2, till n3 > 0 */
	while (ptr != NULL)
	{
		if (count[i] == 0)
			++i;
		else
		{
			ptr->data = i;
			--count[i];
			ptr = ptr->next;
		}
	}
}

/* Function to push a node */
void push (Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = new Node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list of the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

/* Driver code*/
int main(void)
{
	Node *head = NULL;
	push(&head, 0);
	push(&head, 1);
	push(&head, 0);
	push(&head, 2);
	push(&head, 1);
	push(&head, 1);
	push(&head, 2);
	push(&head, 1);
	push(&head, 2);

	cout << "Linked List before Sorting\n";
	printList(head);

	sortList(head);

	cout << "Linked List after Sorting\n";
	printList(head);

	return 0;
}

// This code is contributed by rathbhupendra
