#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "BinarySearchTree.h"


#define MAX_SIZE 15

/* TEST FUNCTIONS */
void test_Insert(Tree* T, int* arr, int max, int min);
void test_Search(Tree* T, int* numbers);
void test_Delete(Tree* T);
void test_Min_Max(Tree* T, int min, int max);
void test_Successor(Tree* T);
void Inorder_tree_walk(int* arr,int size);

/* UTILITY FUNCTIONS */
int random_int(int min, int max);

int main( int argc, char* argv[] )
{
	srand(time(NULL));

	//Numbers to insert
	int max = MAX_SIZE;
	int min = 1;
	int numbers[MAX_SIZE];

	//Insert min and max
	numbers[MAX_SIZE - 1] = max;
	numbers[MAX_SIZE - 2] = min;

	for (int i = 0; i < MAX_SIZE-2; i++)
	{
		numbers[i] = random_int(min,max);
	}
	
	/*------------------------------------------------------------------------------*/
	//Create the new Tree
	Tree* T = newTree();

	//Check if the new Tree is empty
	if (isTreeEmpty(T)) {
		printf("The newly created tree is empty as expected. \n");
	}
	else { printf("ERROR! The newly created tree is NOT empty. \n"); }

	/*------------------------------------------------------------------------------*/
	
	/* Test insert */
	test_Insert(T, numbers, max, min);

	/*------------------------------------------------------------------------------*/

	//Print the tree in order
	printf("In-order-tree-walk: \n");
	in_order_tree_walk(T->root);
	printf("\n\n");

	/*------------------------------------------------------------------------------*/

	/* Test search */
	test_Search(T, numbers);

	/* Test delete*/
	test_Delete(T);

	/* Test min/max */
	test_Min_Max(T, min, max);

	/* Test successor */
	test_Successor(T);

	/*------------------------------------------------------------------------------*/

	/* Try the inorder tree walk */

	printf("In-order-tree-walk: \n");
	Inorder_tree_walk(numbers, MAX_SIZE);
	printf("\n\n");

	/*------------------------------------------------------------------------------*/
	printf("END OF testOperations for BST. \n");
	getchar();
}

void test_Insert(Tree * T, int* arr, int max, int min)
{
	
	//Insert a couple of elements
	printf("Testing Inserting: \n");

	for (int i = 0; i < MAX_SIZE; i++)
	{
		tree_insert(T, newElement(arr[i]));
		printf("%d ", arr[i]);
	}
	printf("\n");

	if (isTreeEmpty(T)) {
		printf("ERROR! The tree is empty after inserting TreeElement(s) \n\n");
	}
	else
	{
		printf("Inserting worked as expected. \n\n");
	}
}

//Test tree_search
void test_Search(Tree * T,int* numbers)
{
	
	printf("Testing search function: \n");
	int wrong_result = 0;
	TreeElement* result = NULL;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		int key = numbers[i];
		result = tree_search(T->root, key);

		if (result->key != key)
			wrong_result++;

	}
	if (wrong_result != 0)
		printf("ERROR! Tree_search returned wrong answer %d times!", wrong_result);
	else { printf("Search worked as expected \n"); }
	printf("\n");

	printf("Testing iterative search function: \n");
	wrong_result = 0;
	result = NULL;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		int key = numbers[i];
		result = tree_search_iterative(T->root, key);

		if (result->key != key)
			wrong_result++;

	}
	if (wrong_result != 0)
		printf("ERROR! Tree_search_iteraivte returned wrong answer %d times!", wrong_result);
	else { printf("Iterative search worked as expected \n"); }
	printf("\n");
}

void test_Delete(Tree * T)
{
	printf("Testing Delete function: \n");

	//insert a known number
	int known_number = 1337;
	TreeElement* known_element = newElement(known_number);
	tree_insert(T, known_element);

	//Verify that it exists in the tree
	TreeElement* result = tree_search_iterative(T->root, known_number);
	
	if (result == known_element)
	{
		//delete known_element and verify that it no longer exists in tree
		tree_delete(T, result);
		
		result = tree_search_iterative(T->root, known_number);
		
		if (result != NULL)
		{
			printf("ERROR! Delete did not delete known number!\n");
			printf("result: %d \n", result->key);
		}
		else
		{
			printf("Delete worked as expected. \n");
		}
	}
	else
	{
		printf("ERROR inserting number to test delete function. \n");
	}
	printf("\n");
}

//Test minimum and maxmimum:
void test_Min_Max(Tree * T,int min, int max)
{
	printf("Test of minimum and maxmimum:  \n");

	TreeElement* result = NULL;

	/* Test MIN */
	result = tree_minimum(T->root);

	if (result->key != min)
		printf("ERROR! Minimum did not return minimum! Return value: %d, real min: %d", result->key, min);
	else { printf("minimum worked as expected. Min = %d \n", result->key); }

	/* Test MAX */
	result = tree_maximum(T->root);
	
	if (result->key != max)
		printf("ERROR! Maximum did not return real maximum! Return value: %d, real max: %d", result->key, max);
	else { printf("maximum worked as expected. Max = %d \n", result->key); }
	printf("\n");
}

//Test of successor function
void test_Successor(Tree * T)
{
	printf("Test of successor function: \n");
	TreeElement* result = NULL;

	//tree_insert a known successor to the tree
	int known_succ = T->root->key + 1;
	tree_insert(T, newElement(known_succ));

	//Try to find the known successor to root
	
	result = tree_successor(T->root);
	if (result->key == T->root->key)
	{
		printf("Successor worked as expected. But the keys are not distinct.\n");
		printf("Return value : %d, known_succ : %d, T.root.key = %d .\n", result->key, known_succ, T->root->key);
	}
	else if (result->key != known_succ)
		printf("ERROR! Successor did not return known successor! Return value: %d, known_succ: %d", result->key, known_succ);
	else { printf("Successor worked as expected. Return value: %d, known_succ: %d, T.root.key = %d .\n", result->key, known_succ, T->root->key); }
	printf("\n");
}

void Inorder_tree_walk(int* arr, int size)
{
	Tree* T = newTree();

	for (int i = 0; i < size; i++)
	{
		tree_insert(T, newElement(arr[i]));
	}

	in_order_tree_walk(T->root);
	
}

int random_int(int min, int max)
{
	return min + rand() % (max + 1 - min);
}
