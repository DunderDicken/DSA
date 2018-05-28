#pragma once

#include  "stdbool.h"

/* STRUCTS */
typedef struct merge_sort_array
{
	int* data;
	int size;

}MergeSortArray;

/* FUNCTIONS */
int* quick_sort_from_file(const char* fName, bool print);

void quick_sort(int* A, int p, int r);

int partition(int* A, int p, int r);

/* UTILITY FUNCTIONS */

void exchange(int* A, int j, int i);