#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Stack.h"

#define NUM_TEST 3

void testInsert();

void testStack();

int main() {

	//testInsert();
	testStack();
	
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
		test[i] = rand() % 100;
	}

	//Try pop the empty stack
	int* return_value = pop(stack1);
	if (return_value == NULL)
	{
		printf("Underflow error! Stack is empty \n");
	}

	//Push NUM_TEST number of elements to the stack
	for (int i = 0; i < NUM_TEST; i++)
	{
		push(stack1, test[i]);
	}

	//Pop all elements and compare the order
	int wrong = 0;

	for (int i = 0; i < NUM_TEST; i++)
	{
		return_value = pop(stack1);

		if (*return_value != test[3])
		{
			wrong++;
		}
	
	}

	

	free(stack1);
}
