/* Includes */
#include <stdio.h>
#include "test_insertion_sort.h"

/* Constants */
#define PRINT 1
#define DONT_PRINT 0



/* insertion sort test function with Linked list */
void test_insertion_sort_LinkedList()
{
	printf("START OF TEST_INSERTION_SORT WITH LINKED LIST \n\n");

	const char* fName;
	const char* sol_fName; 

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10-1-problem";
	sol_fName = "sorting_problems/test-10-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	List* sortedList = insertionSortList(fName,PRINT);
	test_sorted_list(sortedList, fName, sol_fName);


	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10-2-problem";
	sol_fName = "sorting_problems/test-10-2-solution";
	
	printf("Insertion sort with file \" %s \" starting: \n", fName);

	sortedList = insertionSortList(fName,PRINT);
	test_sorted_list(sortedList, fName, sol_fName);
	
	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-100-1-problem";
	sol_fName = "sorting_problems/test-100-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);
	
	sortedList = insertionSortList(fName, DONT_PRINT);
	test_sorted_list(sortedList, fName, sol_fName);

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-1000-1-problem";
	sol_fName = "sorting_problems/test-1000-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	sortedList = insertionSortList(fName, DONT_PRINT);
	test_sorted_list(sortedList, fName, sol_fName);

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10000-1-problem";
	sol_fName = "sorting_problems/test-10000-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	sortedList = insertionSortList(fName, DONT_PRINT);
	test_sorted_list(sortedList, fName, sol_fName);

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10000-2-problem";
	sol_fName = "sorting_problems/test-10000-2-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	sortedList = insertionSortList(fName, DONT_PRINT);
	test_sorted_list(sortedList, fName, sol_fName);

	/*-------------------------------------------------------------------------------*/

	/*This one takes a long time */

	/*
	fName = "sorting_problems/test-100000-1-problem";
	sol_fName = "sorting_problems/test-100000-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	sortedList = insertionSortList(fName, DONT_PRINT);
	test_sorted_list(sortedList, fName, sol_fName);
	*/

	/*-------------------------------------------------------------------------------*/
	printf("END OF TEST_INSERTION_SORT WITH LINKED LIST \n");
	printf("////////////////////////////////////////////////// \n");

	
}

/* insertion sort test function with Array */
void test_insertion_sort_Array()
{
	printf("START OF TEST_INSERTION_SORT WITH AN ARRAY \n\n");

	const char* fName;
	const char* sol_fName;

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10-1-problem";
	sol_fName = "sorting_problems/test-10-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	int* a = insertionSortArray(fName, PRINT);
	test_sorted_array(a,fName,sol_fName);

	/*-------------------------------------------------------------------------------*/
	fName = "sorting_problems/test-10-2-problem";
	sol_fName = "sorting_problems/test-10-2-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	a = insertionSortArray(fName, PRINT);
	test_sorted_array(a, fName, sol_fName);
	
	/*-------------------------------------------------------------------------------*/
	fName = "sorting_problems/test-100-2-problem";
	sol_fName = "sorting_problems/test-100-2-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	a = insertionSortArray(fName, DONT_PRINT);
	test_sorted_array(a, fName, sol_fName);

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-1000-1-problem";
	sol_fName = "sorting_problems/test-1000-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	a = insertionSortArray(fName, DONT_PRINT);
	test_sorted_array(a, fName, sol_fName);

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10000-1-problem";
	sol_fName = "sorting_problems/test-10000-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	a = insertionSortArray(fName, DONT_PRINT);
	test_sorted_array(a, fName, sol_fName);

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-100000-1-problem";
	sol_fName = "sorting_problems/test-100000-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	a = insertionSortArray(fName, DONT_PRINT);
	test_sorted_array(a, fName, sol_fName);

	/*-------------------------------------------------------------------------------*/

	printf("END OF TEST_INSERTION_SORT WITH ARRAY \n");
	printf("////////////////////////////////////////////////// \n");
}

/*Takes the sorted list, converts it to an array and uses the test_solution() function, prints result */
void test_sorted_list(List * sortedList, const char* fName, const char* sol_fName)
{
	int* a = list2Array(sortedList);

	if (test_solution(sol_fName, a)) {
		printf("Insertion sort with file \" %s \" was successful \n", fName);
		printf("\n");
	}
	else
	{
		printf("ERROR! Insertion sort with file \" %s \" was UNSUCCESSFUL!\n", fName);
		printf("\n");
	}

}

/*Takes the sorted array and uses the test_solution() function, prints result */
void test_sorted_array(int * sortedArray, const char * fName, const char * sol_fName)
{

	if (test_solution(sol_fName, sortedArray)) {
		printf("Insertion sort with file \" %s \" was successful \n", fName);
		printf("\n");
	}
	else
	{
		printf("ERROR! Insertion sort with file \" %s \" was UNSUCCESSFUL!\n", fName);
		printf("\n");
	}
}
