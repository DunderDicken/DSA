/*
	This implements a stack with doubly linked list.
*/
#pragma once
#include "LinkedList.h"

/*  STRUCTS  */
typedef struct {

	List* top;
	
}Stack;



/* CREATE NEW STACK */

//Creates an empty Stack with a linked list
Stack * createStack();


/* OPERATIONS */

//Check if the stack is empty, returns 1 if stack is empty
int isStackEmpty(Stack* stack);

//Push a stack with the given key k to the top of the stack
push(Stack* stack, int k);

//Returns the top element of the stack and then deletes it from the stack
int* pop(Stack* stack);

