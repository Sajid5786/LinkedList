#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include "Header.h"

struct Node
{
	int info;
	struct Node *next;
}; typedef struct Node node;

node* start = NULL;

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
	node *ptr;
	node *newptr = fnCreateNode(x);
	if (start == NULL) // If the list is empty
	{
		start = newptr;
		return;
	}
	ptr = start;
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
	node *newptr;
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
	newptr = fnCreateNode(x);
	newptr->next = ptr->next;
	ptr->next = newptr;
}

// To insert the element 'x' before a particular element 'y'

void fnInsertBeforeElement(int y, int x)
{
	node *ptr = start;
	node *prevptr = ptr;
	node *newptr;
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
	newptr = fnCreateNode(x);
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
	node *newptr, *ptr;
	int count;
	if (pos < 1)
	{
		printf("Error!! Postion entered should be greater than or equal to 1\n");
		return;
	}
	newptr = fnCreateNode(x);
	if (start == NULL)
	{
		start = newptr;
		return;
	}
	count = 1;
	ptr = start;
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
	node *ptr;
	node *prevptr;
	node *newptr = fnCreateNode(x);
	printf("Note it is assumed that the list is sorted in the ascending order.\nIf not, then you may find unexpected results.\n");
	if (start == NULL) // If the element needs to be inserted in the beginning
	{
		start = newptr;
		return;
	}
	ptr = start;
	prevptr = ptr;
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

// Deletion of the first node of the list

void fnDeleteFirstNode()
{
	node *ptr;
	if (start == NULL)
	{
		printf("List is empty!!");
		return;
	}
	ptr = start;
	start = ptr->next;
	free(ptr);
}

// Deletion of the last node of the list

void fnDeleteLastNode()
{
	node *ptr;
	node *prevptr;
	if (start == NULL)
	{
		printf("List is empty!!");
	}
	else
	{
		ptr = start;
		prevptr = ptr;
		while (ptr->next != NULL)
		{
			prevptr = ptr;
			ptr = ptr->next;
		}
		prevptr->next = NULL;
		free(ptr);
	}
}

// Deletion of a particular node say the node containing the element 'x'

void fnDeleteParticularNode(int x)
{
	node *ptr = start;
	node *prevptr = ptr;
	int flag = 0;
	while (ptr != NULL)
	{
		if (ptr->info == x)
		{
			flag = 1;
			break;
		}
		prevptr = ptr;
		ptr = ptr->next;
	}
	if (flag == 0)
	{
		printf("Element %d not found in the list", x);
		return;
	}
	prevptr->next = ptr->next;
	free(ptr);
}

// Deletion of the previous node of the node containing element 'x'

void fnDeletePreviousNode(int x)
{
	node *ptr, *prevptr, *prevprevptr;
	int flag;
	if (x == start->info)
	{
		printf("Error!! Element %d is present in the first node of the list.\n",x);
		return;
	}
	ptr = start->next;
	prevptr = start;
	prevprevptr = prevptr;
	flag = 0;
	while (ptr != NULL)
	{
		if (ptr->info == x)
		{
			flag = 1;
			break;
		}
		prevprevptr = prevptr;
		prevptr = ptr;
		ptr = ptr->next;
	}
	if (flag == 0)
	{
		printf("Element %d not found in the list", x);
		return;
	}

	if (ptr == start->next) // If the element is present in the second node of the list we need to delete the first node
		start = ptr;
	else
		prevprevptr->next = ptr;

	free(prevptr);
}

// Deletion of the successor node of the node containing the element 'x'

void fnDeleteNextNode(int x)
{
	node *ptr = start->next;
	node *nextptr;
	int flag = 0;
	while (ptr != NULL)
	{
		if (ptr->info == x)
		{
			flag = 1;
			break;
		}
		ptr = ptr->next;
	}
	if (flag == 0)
	{
		printf("Element %d not found in the list", x);
		return;
	}
	if (ptr->next == NULL)
	{
		printf("Error!! Element %d found at the end of the list\n", x);
		return;
	}
	nextptr = ptr->next;
	ptr->next = nextptr->next;
	free(nextptr);
}

// Delete all the nodes having value greater than x

void fnDeleteNodesGreaterThanValue(int x)
{
	node *ptr = start;
	node *prevptr = ptr;
	node *tempptr;
	while (ptr != NULL)
	{
		if (ptr->info > x)
		{
			tempptr = ptr;

			if (ptr == start) // If the first node has a value greater than x
				start = ptr->next;
			else
				prevptr->next = ptr->next;

			free(tempptr);
		}
		ptr = ptr->next;
	}
}

// To implement a stack using linked list



// To display the list

void fnDisplay()
{
	node *ptr = start;
	printf("The new list looks like :\t");
	while (ptr != NULL)
	{
		printf("%d\t", ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()
{
	char userContinue = 'a';
	int choice, insertChoice, x, y, pos;
	/*do
	{
		printf("Press 1 for Insertion\nPress 2 for Deletion\nPress 3  for Implementing Stack or Queue using List\nPress 4 to reverse a list\nPress 5 for Intersection or Union or Split\nPress 6 to Sort an unsorted list\nPress 7 for Addition or Product of two polynomials\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1: printf("Press 1 for Insertion in the beginning\nPress 2 for Insertion at the end\nPress 3  for Insertion after a particular element\nPress 4 for Insertion before a particular element\nPress 5 for Insertion at the ith position\nPress 6 for Insertion in a sorted order\n");
			scanf_s("%d", &insertChoice);
			printf("Enter the element to be inserted\n");
			scanf_s("%d", &x);
			switch (insertChoice)
			{
			case 1: fnInsertAtFirst(x);
				break;
			case 2: fnInsertAtEnd(x);
				break;
			case 3: printf("After which element?\n");
				scanf_s("%d", &y);
				fnInsertAfterElement(y, x);
				break;
			case 4: printf("Before which element?\n");
				scanf_s("%d", &y);
				fnInsertBeforeElement(y, x);
				break;
			case 5: printf("At which position?\nNote 1st element has position 1\n");
				scanf_s("%d", &pos);
				fnInsertAtPosition(pos, x);
				break;
			case 6: fnInsertInSortedOrder(x);
				break;
			default: printf("Wrong choice!! Try Again\n");
			}
			fnDisplay();
			printf("Press E to exit\n");
			scanf("%c", &userContinue);
			break;
		case 2: printf("Press 1 for Deletion of the first node\nPress 2 for Deletion of the last node\nPress 3 for a particular node\nPress 4 for Deletion of the previous node\nPress 5 for Deletion of the successor node\nPress 6 Deletion of nodes having value greater than x\n");
			scanf_s("%d", &insertChoice);
			switch (insertChoice)
			{
			case 1: fnDeleteFirstNode();
				break;
			case 2: fnDeleteLastNode();
				break;
			case 3: printf("Enter the element to be deleted");
				scanf_s("%d", &x);
				fnDeleteParticularNode(x);
				break;

			default:
				break;
			}
		}
	} while (userContinue != 'E' || userContinue != 'e');*/

	while (userContinue != 'e')
	{
		printf("Press 1 for Insertion in the beginning\nPress 2 for Insertion at the end\nPress 3  for Insertion after a particular element\nPress 4 for Insertion before a particular element\nPress 5 for Insertion at the ith position\nPress 6 for Insertion in a sorted order\n");
		scanf_s("%d", &insertChoice);
		printf("Enter the element to be inserted\n");
		scanf_s("%d", &x);
		switch (insertChoice)
		{
		case 1: fnInsertAtFirst(x);
			break;
		case 2: fnInsertAtEnd(x);
			break;
		case 3: printf("After which element?\n");
			scanf_s("%d", &y);
			fnInsertAfterElement(y, x);
			break;
		case 4: printf("Before which element?\n");
			scanf_s("%d", &y);
			fnInsertBeforeElement(y, x);
			break;
		case 5: printf("At which position?\nNote 1st element has position 1\n");
			scanf_s("%d", &pos);
			fnInsertAtPosition(pos, x);
			break;
		case 6: fnInsertInSortedOrder(x);
			break;
		default: printf("Wrong choice!! Try Again\n");
		}
		fnDisplay();
		printf("Press E to exit\n");
		scanf_s("%c", userContinue);
	}
	_getch();
	return 0;
}