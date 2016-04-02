/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2)
{
	int count=0;
	struct node*tmp;
	if (head1 == NULL && head2 == NULL) {
		return NULL;
	}

	if (head1 == NULL) {
		return head2;
	}

	if (head2 == NULL) {
		return head1;
	}

	// Ensure that list A starts with the smaller number
	if (head1->data > head2->data) {
		tmp = head2;
		head2 = head1;
		head1 = tmp;
	}

	node *listHead = head1;

	while (head2) {
		// Advance through nodes in list A until the next node
		// has data bigger than data at current node of list B
		while (head1->next != NULL &&
			head2->data > head1->next->data) {
			head1 = head1->next;
		}

		// Insert current node in list B into list A
		node* nextB = head2->next;
		head2->next = head1->next;
		head1->next = head2;
		head2 = nextB;
	}
	tmp = listhead;
	while (tmp != NULL)
	{
		count += 1;
		tmp = tmp->next;
	}
	count += 1;

	return count;
}