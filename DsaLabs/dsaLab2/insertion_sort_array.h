#pragma once
#include  "stdbool.h"

/* STRUCTS */
typedef struct sort_array
{
	int* data;
	int size;

}SortArray;

int* insertionSortArray(const char* fName, bool print);