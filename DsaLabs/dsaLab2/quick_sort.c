
/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Include my files */
#include "load_file.h"
#include "quick_sort.h"
#include "insertion_sort_array.h"

int * quick_sort_from_file(const char * fName, bool print)
{
	//Reading file and storing the size from the first element
	int* from_file = load_file(fName);
	int size = from_file[0];

	if (print) {
		printf("Before sorting: ");

		for (int i = 1; i <= size; i++)
		{
			printf(" %d", from_file[i]);
		}
		printf("\n");
	}

	/* Do the quicksort */
	quick_sort(from_file, 1, size);

	////Creating and initalizing the final sorted array
	MergeSortArray* result = (MergeSortArray*)malloc(sizeof(MergeSortArray));
	result->size = size;
	result->data = (int*)malloc(size * sizeof(int));

	//Add result array to the new array without the first element
	for (int i = 1; i <= size; i++)
	{
		result->data[i - 1] = from_file[i];
	}

	if (print) {
		printf("After sorting:  ");

		for (int i = 0; i < size; i++)
		{
			printf(" %d", result->data[i]);
		}
		printf("\n");
	}
	return result->data;
}

void quick_sort(int* A, int p, int r)
{
	
	if (p < r)
	{
		int q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);

	}
}

int partition(int * A, int p, int r)
{
	
	int x = A[r];
	int i = p - 1;

	for (int j = p; j <= (r-1); j++)
	{
		if (A[j] <= x)
		{
			i = i + 1;
			exchange(A, j, i);
		}
	}

	exchange(A, i+1, r);

	return i+1;
}


void exchange(int* A, int j, int i)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}