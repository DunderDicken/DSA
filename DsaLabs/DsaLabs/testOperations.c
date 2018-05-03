#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Stack.h"
#include "StackArray.h"

#define NUM_TEST 3

void testInsert();
void testStack();
void testArrayStack();

int main() {

	//testInsert();
	//testStack();
	testArrayStack();

	return 0;
}


void testInsert()
{
	List* lst = createList();
	int return_value;

	//Test if the list is empty
	return_value = isListEmpty(lst);
	
	if (return_value == 0)
	{
		printf("Test failed. List was not empty \n");
	}

	//Insert 10 new listElements to the list
	for (int i = 1; i <= NUM_TEST; i++)
	{
		insert(lst, newListElementWithKey(i));
	}

	//Test if the list is empty
	return_value = isListEmpty(lst);
	if (return_value == 1)
	{
		printf("Test failed. List was empty \n");
	}

//	listelement* tmp = lst->nil->prev;
//	int i = 0;
//
////check if all keys in list is added correctly
//	while (tmp != lst->nil)
//	{
//		return_value = tmp->key;
//
//		if (return_value != test[i])
//		{
//			printf("test failed. missing number \n");
//		}
//		tmp = tmp->prev;
//		i++;
//		
//	}
	
}


void testStack()
{
	Stack* stack1 = createStack();
	int test[NUM_TEST];
	for (int i = 0; i < NUM_TEST; i++)
	{
		test[i] = i+1;
	}

	//Try pop the empty stack
	int* return_value = pop(stack1);
	if (return_value != NULL)
	{
		printf(" Expected Underflow error, Stack is NOT empty \n");
	}

	//Push NUM_TEST number of elements to the stack
	for (int i = 0; i < NUM_TEST; i++)
	{
		push(stack1, test[i]);
	}

	//Uncommenting this will give an error in the next step.
	//int* tmp = pop(stack1);
	//push(stack1, tmp + 1);

	//Pop all elements and compare the order
	int wrong = 0;

	for (int i = 0; i < NUM_TEST; i++)
	{
		return_value = pop(stack1);

		//Check if returned value is equal to reversed order numbers.
		if (*return_value != test[(NUM_TEST-1) - i])
		{
			wrong++;
		}
	
	}
	if (wrong != 0)
	{
		printf(" Error! POP returned value in wrong order. \n");
	}

	

	free(stack1);
}

void testArrayStack()
{
	StackArray* stack = createStackArray(NUM_TEST);

	//Try pop the empty stack
	int* return_value = popStackArray(stack);
	if (return_value != NULL)
	{
		printf(" Expected Underflow error, Stack is NOT empty \n");
	}

	//Push NUM_TEST number of elements to the stack
	for (int i = 0; i < NUM_TEST; i++)
	{
		pushStackArray(stack, i+1);
	}

	//Pop all elements and compare the order
	int wrong = 0;

	for (int i = 0; i < NUM_TEST; i++)
	{
		return_value = popStackArray(stack);

		//Check if returned value is equal to reversed order numbers.
		if (*return_value != (NUM_TEST - i))
		{
			wrong++;
		}

	}
	if (wrong != 0)
	{
		printf(" Error! POP returned value in wrong order. \n");
	}

	for (int i = 0; i < stack->size + 100; i++)
	{
		pushStackArray(stack, i + 1);
		printf("Pop nr: %d returned: %d  \n", i, stack->data[i]);

	}

}
