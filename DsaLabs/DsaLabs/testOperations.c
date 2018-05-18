#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*  Include my files */
#include "LinkedList.h"
#include "Stack.h"
#include "StackArray.h"
#include "Queue.h"
#include "nPow2.h"

/* Constants */
#define NUM_TEST 3  // This defines how many elements will be inserted, pusched, enqueued etc..
#define TRUE 1
#define FALSE 0
#define NUM_OF_BITS 8 // This defines how many "bits" will be in the list and array for test_nPow2()
#define NUM_OF_LEFTSHIFT 2 //This defines how many times the functions shifts left in test_nPow2()

/* Test functions */
void testLinkedLIst();
void testStack();
void testArrayStack();
void testQueueList();
void testQueueArray();
void test_nPow2();

/* Other functions */
int calc_expected_value(int arr[], int size, int num_of_left_shift);

int main() {

	/* TEST FUNCTIONS */
	/* Uncomment one at a time to test specific operations */

	//testLinkedLIst();
	//testStack();
	//testArrayStack();
	//testQueueList();
	//testQueueArray();
	test_nPow2();

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

void testQueueList() {

	/* CREATE A QUEUE AND DEQUEUE IT, UNDERFLOW ERROR */
	QueueList* Q = createQueueList();

	//Expected to return NULL beacuse Queue is empty
	int* return_value = deQueue(Q);
	if (return_value != NULL)
	{
		printf(" Expected a Underflow error, Queue is NOT empty \n");
	}

	/*-------------------------------------------------------------------*/
	/* ENQUE A FEW ITEMS */

	//Enqueue NUM_TEST number of elements to Queue
	for (int i = 0; i < NUM_TEST; i++)
	{
		enQueue(Q, i+1);
	}

	/*-------------------------------------------------------------------*/
	/* DEQUEUE ALL ELEMENTS AND COPMARE THE ORDER */
	int wrongNumbers = 0;
	int expected_value;

	for (int i = 0; i < NUM_TEST; i++)
	{
		return_value = deQueue(Q);
		expected_value = (i + 1);

		if (*return_value != expected_value)
		{
			wrongNumbers++;
		}
	}
	if (wrongNumbers != 0)
	{
		printf(" Error! DeQueue returned value(s) in wrong order %d times. \n", wrongNumbers);
	}
	/*-------------------------------------------------------------------*/


	printf(" Queue test finished. \n");
	free(Q);
}

void testQueueArray() {

	/* CREATE A QUEUE AND DEQUEUE IT, UNDERFLOW ERROR */
	QueueArray* Q = createQueueArray(NUM_TEST);

	int* returned_value = deQueueArray(Q);

	if (returned_value != NULL)
	{
		printf(" Expected a Underflow error, Queue is NOT empty \n");
	}

	/*-------------------------------------------------------------------*/
	/* ENQUE A FEW ITEMS */

	for (int i = 0; i < Q->length; i++)
	{
		enQueueArray(Q, i + 1);
	}

	/*-------------------------------------------------------------------*/
	/* DEQUEUE ALL ELEMENTS AND COPMARE THE ORDER */

	int wrong_numbers = 0;
	int expected_value;

	for (int i = 0; i < Q->length; i++)
	{
		returned_value = deQueueArray(Q);

		expected_value = i + 1;

		if (*returned_value != expected_value)
		{
			wrong_numbers++;
		}
	}
	if (wrong_numbers != 0)
	{
		printf("Error! deQueArray returned numbers in wrong order %d times. \n", wrong_numbers);
	}
	/*---------------------------------------------------------------------*/
	/* ENQUEUE ELEMENTS UNTIL ARRAY IS FULL, THEN ONE MORE; OVERFLOW ERROR */

	for (int i = 0; i < Q->length; i++)
	{
		enQueueArray(Q, i + 1);
	}

	//Expected Overflow error
	enQueueArray(Q, Q->length + 1);

	/*---------------------------------------------------------------------*/

	printf(" Test of Queue with array finnisched. \n");
	free(Q);

}

void test_nPow2()
{
	//The binary number representation
	int binaryNum[NUM_OF_BITS] = { 0,0,0,1,0,1,1,1 };
	
	//Calulate expected value after the nPow2() functions
	int expected_value = calc_expected_value(binaryNum, NUM_OF_BITS, NUM_OF_LEFTSHIFT);

	/****************************************************************************/
	/* a)	Input is an array:  */

	BitArray* BA = newBitArray();

	/* Insert all elements in the array and print the elements */
	for (int i = 0; i < BA->size; i++)
	{
		BA->data[i] = binaryNum[i];
	}

	printf("Bit array before nPow2: \n");
	print_Bit_Array(BA);
	printf("Int value of BitArray: %d  \n", bit_to_int_array(BA));
	printf("\n");

	/* Perform the nPow2 and print the result, check for error */
	nPow2_Array(BA, NUM_OF_LEFTSHIFT);

	if (bit_to_int_array(BA) != expected_value)
	{
		printf("error! int value of Bit array: %d != expected value: %d After nPow2\n", bit_to_int_array(BA), expected_value);
	}

	printf("Bit array after left shifting %d times: \n",NUM_OF_LEFTSHIFT);
	print_Bit_Array(BA);
	printf("Int value of BitArray: %d  \n", bit_to_int_array(BA));
	printf("\n");

	/****************************************************************************/
	/* b)  Input is an Linked List */

	List* list = createList();
	
	/* Insert all elements in the list and print the list */
	for (int i = (NUM_OF_BITS - 1) ; i >= 0; i--)
	{
		insert(list, newListElementWithKey(binaryNum[i]));
	}

	printf("List before nPow2: \n");
	print_Bit_List(list);
	printf("Int value of list: %d  \n", bit_to_int_list(list));
	printf("\n");

	/* Perform the nPow2 and print the result, check for error */
	nPow2_List(list,NUM_OF_LEFTSHIFT);

	if (bit_to_int_list(list) != expected_value)
	{
		printf("error! int value of Bit List: %d != expected value: %d After nPow2\n", bit_to_int_list(list), expected_value);
	}

	printf("List after left shifting %d times: \n", NUM_OF_LEFTSHIFT);
	print_Bit_List(list);
	printf("Int value of list: %d  \n", bit_to_int_list(list));
	printf("\n");

	/****************************************************************************/
	free(list);
}

int calc_expected_value(int arr[], int size, int num_of_left_shift)
{
	int sum = 0,
		value_of_pos = 1;

	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] == 1) {
			sum = sum + value_of_pos;
		}
		value_of_pos = value_of_pos * 2;
	}

	return sum*(pow(2,num_of_left_shift));
}


