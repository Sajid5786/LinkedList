#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int info;
	struct Node *next;
}; typedef struct Node node;

node *start;

// To create a node

node* fnCreateNode(int x)
{
	node *newptr;
	newptr = (node*)malloc(sizeof(node));
	newptr->info = x;
	newptr->next = NULL;
	return newptr;
}

// To insert an element in the beginning of the list

void fnInsertAtFirst(int x)
{
	node *newptr;
	newptr = fnCreateNode(x);
	if (start == NULL) // If the list is empty
	{
		start = newptr;
		return;
	}
	newptr->next = start;
	start = newptr;
}

// To insert the element at the end of the list

void fnInsertAtEnd(int x)
{
	node *newptr = fnCreateNode(x);
	if (start == NULL) // If the list is empty
	{
		start = newptr;
		return;
	}
	node *ptr = start;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	ptr->next = newptr;
}

// To insert the element 'x' after a particular element 'y'

void fnInsertAfterElement(int y, int x)
{
	node *ptr = start;
	int flag = 0; // Assuming the element is not present in the list
	while (ptr != NULL)
	{
		if (ptr->info == y)
		{
			flag = 1; // Element found in the list
			break;
		}
		ptr = ptr->next;
	}
	if (flag == 0)
	{
		printf("Element %d not present in the list!! HEnce %d cannot be inserted\n", y, x);
		return;
	}
	node *newptr = fnCreateNode(x);
	newptr->next = ptr->next;
	ptr->next = newptr;
}

// To insert the element 'x' before a particular element 'y'

void fnInsertBeforeElement(int y, int x)
{
	node *ptr = start;
	node *prevptr = ptr;
	int flag = 0; // Assuming the element is not present in the list
	while (ptr != NULL)
	{
		if (ptr->info == y)
		{
			flag = 1; // Element found in the list
			break;
		}
		prevptr = ptr;
		ptr = ptr->next;
	}
	if (flag == 0)
	{
		printf("Element %d not present in the list!! HEnce %d cannot be inserted\n", y, x);
		return;
	}
	node *newptr = fnCreateNode(x);
	if (ptr == start) // If element found is at the beginning of the list
	{
		newptr->next = ptr;
		start = newptr;
	}
	else
	{
		newptr->next = ptr;
		prevptr->next = newptr;
	}
}

// To insert the node at ith position
// First element is numbered position 1

void fnInsertAtPosition(int pos, int x)
{
	if (pos < 1)
	{
		printf("Error!! Postion entered should be greater than or equal to 1\n");
		return;
	}
	node *newptr = fnCreateNode(x);
	if (start == NULL)
	{
		start = newptr;
		return;
	}
	int count = 1;
	node *ptr = start;
	if (pos == 1) // If the element needs to be inserted in first position
	{
		newptr->next = ptr;
		start = newptr;
		return;
	}
	while (ptr != NULL && count != pos - 1)
	{
		count++;
		ptr = ptr->next;
	}
	if (ptr == NULL)
	{
		printf("Error!! Position out of bound.\n");
		return;
	}
	newptr->next = ptr->next;
	ptr->next = newptr;
}

// To insert the element in the sorted order

void fnInsertInSortedOrder(int x)
{
	printf("Note it is assumed that the list is sorted in the ascending order.\nIf not, then you may find unexpected results.\n");
	node *newptr = fnCreateNode(x);
	if (start == NULL) // If the element needs to be inserted in the beginning
	{
		start = newptr;
		return;
	}
	node *ptr = start;
	node *prevptr = ptr;
	while (ptr != NULL)
	{
		if (x > ptr->info)
		{
			prevptr = ptr;
			ptr = ptr->next;
		}
		else
			break;
	}
	if (ptr == start)
	{
		newptr->next = start;
		start = newptr;
	}
	else
	{
		newptr->next = ptr;
		prevptr->next = newptr;
	}
}