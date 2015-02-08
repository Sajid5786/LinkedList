// Implement a stack using linked list
// Implement a linear queue using linked list
// Implement a circular queue using linked list
// Implement a dequeue using linked list
// Implement a linear queue using stack

#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

struct Node
{
	int info;
	struct Node *next;
}; typedef struct Node node;

node* start;

// To create a node

node* fnCreateNode(int x)
{
	node *newptr;
	newptr = (node*)malloc(sizeof(node));
	newptr->info = x;
	newptr->next = NULL;
	return newptr;
}

// To implement a stack using linked list

void fnPushElementInAStack(int x)
{
	node *top = start;
	node *newptr = fnCreateNode(x);
	if (top == NULL)
	{
		top = newptr;
		start = top; // To modify the start pointer
		return;
	}
	top->next = newptr;
	top = newptr;
	start = top; // To modify the start pointer
}

void fnPopElementFromAStack()
{
	node *top = start;
}