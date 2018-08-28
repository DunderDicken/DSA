#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
 
#define TRUE 1
#define FALSE 0

Stack * createStack()
{
	Stack * tmp_stack = (Stack*)malloc(sizeof(Stack));
	tmp_stack->top = createList();


	return tmp_stack;
}


int isStackEmpty(Stack* stack)
{
	return isListEmpty(stack->top);
}



push(Stack* stack, int k)
{
	insert(stack->top, newListElementWithKey(k));
}



int* pop(Stack * stack)
{
	if (isStackEmpty(stack) == 1)
	{
		return NULL;
	}
	
	int* returnedKey = malloc(sizeof(int));

	*returnedKey = stack->top->nil->next->key;

	deleteElement(stack->top,stack->top->nil->next);

	return returnedKey;

}



