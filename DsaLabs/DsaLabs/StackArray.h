/*
	This program implements a stack with an array.
*/

#pragma once

/* STRUCTS */
typedef struct stack_with_array
{
	int* data;
	int top;
	int size;

}StackArray;

/* CREATE NEW STACK */

//Creates an empty Stack with array
StackArray* createStackArray(int size);

/* OPERATIONS */

//Check if stack is empty, returns 1 if stack is empty
int isStackArrayEmpty(StackArray* stack);

//Check if stack is full, returns 1 if stack is full
int isStackArrayFull(StackArray * stack);

//Push a stack Element with the given key to the top of the stack
pushStackArray(StackArray* stack, int k);

//Returns the top element of the stack 
int* popStackArray(StackArray* stack);