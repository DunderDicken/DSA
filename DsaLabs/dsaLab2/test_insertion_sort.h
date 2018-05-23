#pragma once
#include "insertion_sort_linkedList.h"
#include "insertion_sort_array.h"
#include "load_file.h"

/*Functions*/

void test_insertion_sort_LinkedList();
void test_insertion_sort_Array();

void test_sorted_list(List * sortedList, const char* fName, const char* sol_fName);
void test_sorted_array(int* sortedArray, const char* fName, const char* sol_fName);