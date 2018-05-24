#pragma once

/* Include my files */
#include "insertion_sort_linkedList.h"
#include "insertion_sort_array.h"

/* Include given files */
#include "load_file.h"

/*FUNCTIONS*/

/* Linked Lists */

//Main test function with Linked List
void test_insertion_sort_LinkedList();

//Test if the result is correct
void test_sorted_list(List * sortedList, const char* fName, const char* sol_fName);

/* ----------------------------------------------------------------------------------- */
/* Arrays */

//Main test function with Arrays
void test_insertion_sort_Array();

//Test if the result is correct
void test_sorted_array(int* sortedArray, const char* fName, const char* sol_fName);