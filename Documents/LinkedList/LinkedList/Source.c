#include <stdio.h>
#include <time.h>
#include "Utilities1.c"
#include "Utilities2.c"

struct Node
{
	int info;
	struct Node *next;
}; typedef struct Node node;

node* start = NULL;

// To display the list

void fnDisplay()
{
	printf("The new list looks like :\t");
	node *ptr = start;
	while (ptr != NULL)
	{
		printf("%d\t", ptr->info);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()
{
	clock_t begin, end;
	begin = clock();
	int choice, x, y;
	do
	{
		printf("Press 1 for Insertion in the beginning\nPress 2 for Insertion at the end\nPress 3  for Insertion after a particular element\nPress 4 for Insertion before a particular element\nPress 5 for Insertion at the ith position\nPress 6 for Insertion in a sorted order\nPress 0 to Exit\n");
		scanf("%d", &choice);

		if (choice == 0)
		{
			break;
		}

		printf("Enter the element to be inserted\n");
		scanf("%d", &x);

		switch (choice)
		{
		case 1: fnInsertAtFirst(x);
			break;
		case 2: fnInsertAtEnd(x);
			break;
		case 3: printf("After which element?\n");
			scanf("%d", &y);
			fnInsertAfterElement(y, x);
			break;
		case 4: printf("Before which element?\n");
			scanf("%d", &y);
			fnInsertBeforeElement(y, x);
			break;
		case 5: printf("At which position?\nNote 1st element has position 1\n");
			int pos;
			scanf("%d", &pos);
			fnInsertAtPosition(pos, x);
			break;
		case 6: fnInsertInSortedOrder(x);
			break;
		default: printf("Wrong choice!! Try Again\n");
		}
		fnDisplay();
	} while (1);

	do
	{
		printf("Press 1 for Deletion of the first node\nPress 2 for Deletion of the last node\nPress 3 for a particular node\nPress 4 for Deletion of the previous node\nPress 5 for Deletion of the successor node\nPress 6 Deletion of nodes having value greater than x\nPress 0 to Exit\n");
		scanf("%d", &choice);

		if (choice == 0)
		{
			break;
		}

		switch (choice)
		{
		case 1: fnDeleteFirstNode();
			break;
		case 2: fnDeleteLastNode();
			break;
		case 3: printf("Enter the element to be deleted\n");
			scanf("%d", &x);
			fnDeleteParticularNode(x);
			break;
		case 4: printf("Enter the element\n");
			scanf("%d", &x);
			fnDeletePreviousNode(x);
			break;
		case 5: printf("Enter the element\n");
			scanf("%d", &x);
			fnDeleteNextNode(x);
			break;
		case 6: printf("Enter the element\n");
			scanf("%d", &x);
			fnDeleteNodesGreaterThanValue(x);
			break;
		default:
			break;
		}
		fnDisplay();
	} while (1);
	end = clock();
	float diff = (float)end - begin;
	float time_taken = diff / CLOCKS_PER_SEC;
	printf("Time taken :\t%f", time);
	return 0;
}