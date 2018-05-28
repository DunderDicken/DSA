
#include <stdio.h>
#include <stdlib.h>

#include "test_merge_sort.h"
#include "merge_sort.h"

/* Constants */
#define PRINT 1
#define DONT_PRINT 0

void test_merge_sort()
{
	printf("START OF TEST_MERGE_SORT WITH LINKED LIST \n\n");

	const char* fName;
	const char* sol_fName;

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10-1-problem";
	sol_fName = "sorting_problems/test-10-1-solution";

	printf("Merge sort with file \" %s \" starting: \n", fName);

	List* sortedList = merge_sort_from_file(fName, PRINT);
	test_sorted_list(sortedList, fName, sol_fName);


	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10-2-problem";
	sol_fName = "sorting_problems/test-10-2-solution";

	printf("Merge sort with file \" %s \" starting: \n", fName);

	sortedList = merge_sort_from_file(fName, PRINT);
	test_sorted_list(sortedList, fName, sol_fName);


	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10-3-problem";
	sol_fName = "sorting_problems/test-10-3-solution";

	printf("Merge sort with file \" %s \" starting: \n", fName);

	sortedList = merge_sort_from_file(fName, PRINT);
	test_sorted_list(sortedList, fName, sol_fName);


	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-100-2-problem";
	sol_fName = "sorting_problems/test-100-2-solution";

	printf("Merge sort with file \" %s \" starting: \n", fName);

	sortedList = merge_sort_from_file(fName, DONT_PRINT);
	test_sorted_list(sortedList, fName, sol_fName);


	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-1000-1-problem";
	sol_fName = "sorting_problems/test-1000-1-solution";

	printf("Merge sort with file \" %s \" starting: \n", fName);

	sortedList = merge_sort_from_file(fName, DONT_PRINT);
	test_sorted_list(sortedList, fName, sol_fName);


	/*-------------------------------------------------------------------------------*/

	printf("END OF TEST_MERGE_SORT WITH LINKED LIST \n");
	printf("////////////////////////////////////////////////// \n");
}