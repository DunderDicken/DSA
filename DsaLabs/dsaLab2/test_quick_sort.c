/* Includes */
#include <stdio.h>
#include "test_quick_sort.h"

/* Constants */
#define PRINT 1
#define DONT_PRINT 0

void test_quick_sort()
{
	printf("START OF QUICKSORT TEST \n\n");

	const char* fName;
	const char* sol_fName;

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10-1-problem";
	sol_fName = "sorting_problems/test-10-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	int* a = quick_sort_from_file(fName, PRINT);
	test_sorted_array(a, fName, sol_fName);


	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-10-3-problem";
	sol_fName = "sorting_problems/test-10-3-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	a = quick_sort_from_file(fName, PRINT);
	test_sorted_array(a, fName, sol_fName);

	/*-------------------------------------------------------------------------------*/

	fName = "sorting_problems/test-100-1-problem";
	sol_fName = "sorting_problems/test-100-1-solution";

	printf("Insertion sort with file \" %s \" starting: \n", fName);

	a = quick_sort_from_file(fName, DONT_PRINT);
	test_sorted_array(a, fName, sol_fName);

	/*-------------------------------------------------------------------------------*/
	printf("END OF QUICKSORT TEST \n");
	printf("////////////////////////////////////////////////// \n");
}
