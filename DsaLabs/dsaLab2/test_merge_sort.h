#pragma once

/* Include my files */
#include "merge_sort.h"

/* Include given files */
#include "load_file.h"

/*FUNCTIONS*/

//Main test function with Linked List
void test_merge_sort();

//Test if the result is correct
void test_sorted_list(List * sortedList, const char* fName, const char* sol_fName);