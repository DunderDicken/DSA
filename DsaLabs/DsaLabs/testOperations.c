#include <stdio.h>
#include <stdlib.h>

/*  Include my files */
#include "LinkedList.h"
#include "Stack.h"
#include "StackArray.h"
#include "Que.h"

/* Constants */
#define NUM_TEST 5  // This defines how many elements will be inserted, pusched etc..
#define TRUE 1
#define FALSE 0

/* Functions */
void testLinkedLIst();
void testStack();
void testArrayStack();
void testQueList();

int main() {

	/* TEST FUNCTIONS */
	/* Uncomment one at a time to test specific operations */

	//testLinkedLIst();
	//testStack();
	testArrayStack();
	//testQueList();
	

	getchar();
	return 0;
}


void testLinkedLIst()
{
	int num_of_fails = 0;

	/* Test 1. Create an empty list and check if it is empty. */
	
	List* lst = createList();
	
	//Test if the list is empty
	if (isListEmpty(lst) != FALSE)
	{
		printf("Test 1 failed! List was not empty after creation. \n");
		num_of_fails++;
	}

	/*-------------------------------------------------------------------*/
	/* Test 2. Insert a couple of numbers and check if the list is empty */

	//Insert NUM_TEST numbers of new listElements to the list
	for (int i = 0; i < NUM_TEST; i++)
	{
		insert(lst, newListElementWithKey(i + 1));
	}

	//Test if the list is empty
	if (isListEmpty(lst) == TRUE)
	{
		printf("Test 2 failed! List was empty after inserting numbers. \n");
		num_of_fails++;
	}

	/*------------------------------------------------------------------*/
	/* Test 3. Test the search function. */

	//create a known number and insert it to the list
	int known_number = 1337;
	insert(lst, newListElementWithKey(known_number));

	if (listSearch(lst, known_number)->key != known_number)
	{
		printf("Test 3 failed! Search did not return the known_number \n");
		num_of_fails++;
	}

	/*------------------------------------------------------------------*/
	/* Test 4. Test the delete function. */

	//Delete the element with the key known_number
	deleteElement(lst, listSearch(lst, known_number));

	if (listSearch(lst, known_number) != lst->nil)
	{
		printf("Test 4 failed! Search did not return nil while known number was deleted from list. \n");
		num_of_fails++;
	}

	/*------------------------------------------------------------------*/
	/* Test 5. Test Max and Min functions */
	int max = 10000;
	int min = 0;

	insert(lst, newListElementWithKey(max));
	insert(lst, newListElementWithKey(min));
	
	if (maximum(lst)->key != max)
	{
		printf("Test 5 failed! maximum() did not return given max value  \n");
		num_of_fails++;
	}
	if (minimum(lst)->key != min)
	{
		printf("Test 5 failed! minimum() did not return given min value  \n");
		num_of_fails++;
	}
	
	//Delete max and min elements
	deleteElement(lst, listSearch(lst, max));
	deleteElement(lst, listSearch(lst, min));

	/*------------------------------------------------------------------*/
	/* Test 6. Test successor and predecessor functions */

	int pre = 99,
		succ = 101,
		middle = 100;

	insert(lst, newListElementWithKey(pre));
	insert(lst, newListElementWithKey(succ));
	insert(lst, newListElementWithKey(middle));
	
	if (successor(lst, listSearch(lst,middle))->key != succ)
	{
		printf("Test 6 failed! successor() did not return given successor value  \n");
		num_of_fails++;
	}

	if (predecessor(lst, listSearch(lst, middle))->key != pre)
	{
		printf("Test 6 failed! predecessor() did not return given predecessor value  \n");
		num_of_fails++;
	}


	printf("TestLinkedList finished with %d number of failed tests. \n", num_of_fails);
	free(lst);
}


void testStack()
{
	/* CREATE A STACK AND POP IT, UNDERFLOW ERROR */
	Stack* stack1 = createStack();

	//Try to pop the empty stack
	int* return_value = pop(stack1);
	if (return_value != NULL)
	{
		printf("Expected a Underflow error, Stack is NOT empty. \n");
	}

	/*-------------------------------------------------------------------*/
	/* PUSH SOME NUMBERS TO THE STACK */

	//Create an array with numbers to push
	int test[NUM_TEST];
	for (int i = 0; i < NUM_TEST; i++)
	{
		test[i] = i + 1;
	}

	//Push NUM_TEST number of elements to the stack
	for (int i = 0; i < NUM_TEST; i++)
	{
		push(stack1, test[i]);
	}

	/*-------------------------------------------------------------------*/
	/* POP ALL ELEMENTS AND COPMARE THE ORDER */
	int wrong_numbers = 0;
	int expected_value;

	for (int i = 0; i < NUM_TEST; i++)
	{
		return_value = pop(stack1);

		//Check if returned value is equal to the reversed-order numbers.
		expected_value = test[(NUM_TEST - 1) - i];

		if (*return_value != expected_value)
		{
			wrong_numbers++;
		}
	
	}
	if (wrong_numbers != 0)
	{
		printf("Error! POP returned values in the wrong order %d times. \n", wrong_numbers);
	}
	/*-------------------------------------------------------------------*/

	printf("TestStack finished. \n");
	free(stack1);
}

void testArrayStack()
{
	/* CREATE A STACK AND POP IT, UNDERFLOW ERROR */
	StackArray* stack = createStackArray(NUM_TEST);

	//Try to pop the empty stack
	int* return_value = popStackArray(stack);
	if (return_value != NULL)
	{
		printf(" Expected Underflow error, Stack is NOT empty \n");
	}

	/*-------------------------------------------------------------------*/
	/* PUSH SOME NUMBERS TO THE STACK */

	//Push NUM_TEST number of elements to the stack
	for (int i = 0; i < NUM_TEST; i++)
	{
		pushStackArray(stack, i+1);
	}

	/*-------------------------------------------------------------------*/
	/* POP ALL ELEMENTS AND COPMARE THE ORDER */
	int wrong_numbers = 0;
	int expected_value;
 
	for (int i = 0; i < NUM_TEST; i++)
	{
		return_value = popStackArray(stack);

		//Check if returned value is equal to the reversed-order numbers.
		expected_value = (NUM_TEST - i);

		if (*return_value != expected_value)
		{
			wrong_numbers++;
		}

	}
	if (wrong_numbers != 0)
	{
		printf("Error! POP returned values in the wrong order %d times. \n", wrong_numbers);
	}

	/*-------------------------------------------------------------------*/
	/* PUSH UNTIL ARRAY IF FILLED, THEN PUSH ONE MORE ELEMENT, OVERFLOW ERROR */

	//Push elements until the array is filled 
	for (int i = 0; i < stack->size; i++)
	{
		pushStackArray(stack,(i+1));
	}
	//Push one more element, overflow error is expected
	pushStackArray(stack, stack->size + 1);

	/*-------------------------------------------------------------------*/

	printf("TestArrayStack finished. \n");
	free(stack);
}

void testQueList() {

	QueList* Q = createQueList();

	//Try to dequeue empty que, expected to return NULL beacuse que is empty
	int* return_value = dequeue(Q);
	if (return_value != NULL)
	{
		printf(" Expected Underflow error, Que is NOT empty \n");
	}

	//Enqueue NUM_TEST number of elements to que
	for (int i = 0; i < NUM_TEST; i++)
	{
		enqueue(Q, i+1);
	}

	////Uncommenting this should give an error in the next step:
	//dequeue(Q);
	//enqueue(Q, 1);
	

	//Try to dequeue all elements and check that the order is correct
	int wrongNumbers = 0;

	for (int i = 0; i < NUM_TEST; i++)
	{
		return_value = dequeue(Q);
		//printf("Return value: %d  \n", *return_value);

		if (*return_value != (i+1))
		{
			wrongNumbers++;
		}
	}
	if (wrongNumbers != 0)
	{
		printf(" Error! Dequeue returned value in wrong order. \n");
	}

	
	free(Q);
}