#include <stdio.h>

struct Node
{
	int info;
	struct Node *next;
}; typedef struct Node node;

node* start;

// Deletion of the first node of the list

void fnDeleteFirstNode()
{
	if (start == NULL)
	{
		printf("List is empty!!");
		return;
	}
	node *ptr = start;
	start = ptr->next;
	free(ptr);
}

// Deletion of the last node of the list

void fnDeleteLastNode()
{
	if (start == NULL)
	{
		printf("List is empty!!");
	}
	else
	{
		node *ptr = start;
		node *prevptr = ptr;
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
	if (x == start->info)
	{
		printf("Error!! Element %d is present in the first node of the list.\n", x);
		return;
	}
	node *ptr = start->next;
	node *prevptr = start;
	node *prevprevptr = prevptr;
	int flag = 0;
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
	node *nextptr = ptr->next;
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