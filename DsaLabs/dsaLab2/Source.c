
#include <stdio.h>

#include "load_file.h"
#include "test_insertion_sort.h"
#include "test_merge_sort.h"
#include "test_quick_sort.h"

int main( int argc, char* argv[] )
{
	/* Runs the tests for insertion sort with both linked lists and arrays*/
	
	/*test_insertion_sort_LinkedList();
	test_insertion_sort_Array();
	test_merge_sort();*/
	test_quick_sort();

	getchar();
}