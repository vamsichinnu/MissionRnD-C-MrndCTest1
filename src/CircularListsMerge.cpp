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
struct node * mergeing(struct node *head1, struct node *head2) {
	struct node *temp, *temp1, *res;
	if (head2&&head1)
	{
		res = (struct node *)malloc(sizeof(struct node) * 1);
		temp = (struct node *)malloc(sizeof(struct node) * 1);
		temp1 = (struct node *)malloc(sizeof(struct node) * 1);
		if (head1->data> head2->data)
		{
			temp = head1;
			head1 = head2;
			head2 = temp;
		}
		res = head1;
		while (head2 || head1)
		{

			if (head1&&head2)
			{
				if (head1->data <= head2->data)
				{

					temp = head1;
					head1 = head1->next;
				}
				else
				{
					temp1 = head2->next;
					head2->next = temp->next;
					temp->next = head2;
					head2 = temp1;
					temp = temp->next;
				}
			}
			else if (head1 == NULL&&head2)
			{
				temp->next = head2;
				break;
			}
			else if (head2 == NULL&&head1)
			{
				break;
			}
		}

		return res;
	}
	else if (head1 == NULL&&head2)
	{
		return head2;
	}
	else if (head2 == NULL&&head1)
	{
		return head1;
	}
	else
	{
		return NULL;
	}
}
int merge_circularlists(struct node **head1, struct node **head2){
	struct node *temp;
	int count = 0;
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (*head1&&*head2)
	{
		temp = *head1;
		while ((*head1)->next != temp)
		{
			(*head1) = (*head1)->next;
		}
		(*head1)->next = NULL;
		(*head1) = temp;
		temp = (*head2);
		while ((*head2)->next != temp)
		{
			(*head2) = (*head2)->next;
		}
		(*head2)->next = NULL;
		(*head2) = temp;
		(*head1) = mergeing(*head1, *head2);
		temp = (*head1);
		while ((*head1)->next != NULL)
		{
			(*head1) = (*head1)->next;
			count++;
		}
		(*head1)->next = temp;
		count++;
		return count;
	}
	else
	{
		return -1;
	}
}