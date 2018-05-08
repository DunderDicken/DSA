#include "StackArray.h"
#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define TRUE 1
#define FALSE 0

/* Creat new stack */
StackArray * createStackArray(int size)
{
	StackArray* tmp_stack = (StackArray*)malloc(sizeof(StackArray));

	tmp_stack->top = 0;
	tmp_stack->size = size;
	tmp_stack->data = (int*)malloc(size * sizeof(int));

	return tmp_stack;
}

/* OPERATIONS */

int isStackArrayEmpty(StackArray * stack)
{
	if (stack->top == 0)
	{
		return TRUE;
	}
	return FALSE;
}

int isStackArrayFull(StackArray * stack)
{
	if (stack->top >= stack->size)
	{
		return TRUE;
	}
	return FALSE;
}

pushStackArray(StackArray * stack, int k)
{
	if (isStackArrayFull(stack) == TRUE)
	{
		printf("Overflow error! Stack is full \n");
		printf("Could not push key: %d . \n", k);
		return;
	}

	stack->data[stack->top] = k;
	stack->top++;
	
}

int* popStackArray(StackArray * stack)
{
	if (isStackArrayEmpty(stack) == TRUE)
	{
		return NULL;
	}
	stack->top--;

	int* returnedKey = malloc(sizeof(int));

	*returnedKey = stack->data[stack->top];

	return returnedKey;
}