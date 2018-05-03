#pragma once

typedef struct stack_with_array
{
	int* data;
	int top;
	int size;

}StackArray;

//Creates an empty Stack with array
StackArray* createStackArray(int size);

//Check if stack is empty, returns 1 if stack is empty
int isStackArrayEmpty(StackArray* stack);

//Push a stack Element with the given key to the top of the stack
pushStackArray(StackArray* stack, int k);

//Returns the top element of the stack 
int* popStackArray(StackArray* stack);