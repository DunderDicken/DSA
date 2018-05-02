#pragma once
#include "LinkedList.h"

typedef struct {

	List* top;
	
}Stack;

typedef struct stack_with_array
{
	int* top;


}StackArray;

//////Operations

//Creates an empty Stack
Stack * createStack();
StackArray* createStackArray(int size);

//Check if stack is empty, returns 1 if stack is empty
int isStackEmpty(Stack* stack);

//Push a stack Element with the given key to the top of the stack
push(Stack* stack, int k);

//Returns the top element of the stack and then deletes it from the stack
int* pop(Stack* stack);