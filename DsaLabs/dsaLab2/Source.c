
#include <stdio.h>

#include "load_file.h"
#include "test_insertion_sort.h"

int main( int argc, char* argv[] )
{
	/* Runs the tests for insertion sort with both linked lists and arrays*/
	
	test_insertion_sort_LinkedList();
	test_insertion_sort_Array();
	
	getchar();
}