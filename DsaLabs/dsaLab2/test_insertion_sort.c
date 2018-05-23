#include <stdio.h>
#include "insertion_sort_linkedList.h"
#include "load_file.h"

/* Constants */
#define PRINT 1
#define DONT_PRINT 0

/*Functions*/
void test_sorted_list(List * sortedList, const char* fName, const char* sol_fName);
void test_insertion_sort_LinkedList();
void test_insertion_sort_Array();

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

void test_insertion_sort_Array()
{
	const char* fName;
	const char* sol_fName;

	fName = "sorting_problems/test-10-1-problem";
	sol_fName = "sorting_problems/test-10-1-solution";

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
