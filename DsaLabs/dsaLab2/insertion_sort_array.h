#pragma once
#include  "stdbool.h"

/* STRUCTS */
typedef struct sort_array
{
	int* data;
	int size;

}SortArray;

/* FUNCTIONS */

//Sorts the numbers stored in the file with the given filename. 
//Setting print to TRUE will print the numbers.
int* insertionSortArray(const char* fName, bool print);