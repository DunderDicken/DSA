#pragma once

#include  "stdbool.h"

/* STRUCTS */
typedef struct merge_sort_array
{
	int* data;
	int size;

}MergeSortArray;

/* FUNCTIONS */

//Reads the file with numbers, put numbers in an array, sorts the array and returns it
int* quick_sort_from_file(const char* fName, bool print);

//Main quicksort function
void quick_sort(int* A, int p, int r);

//Partition function
int partition(int* A, int p, int r);

/* UTILITY FUNCTIONS */

//Swaps A[j] and A[i]
void exchange(int* A, int j, int i);