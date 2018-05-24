/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Include my files */
#include "load_file.h"
#include "insertion_sort_array.h"


int * insertionSortArray(const char * fName, bool print)
{
	//Reading file and storing the size from the first element
	int* from_file = load_file(fName);
	int size = from_file[0];

	//Creating and initalizing the final sorted array
	SortArray* a = (SortArray*)malloc(sizeof(SortArray));
	a->size = size;
	a->data = (int*)malloc(size * sizeof(int));


	if (print) {
		printf("Before sorting: ");

		for (int i = 1; i <= size; i++)
		{
			printf("%d ", from_file[i]);
		}
		printf("\n");
	}

	/* Main Insertion sort function */
	for (int j = 2; j <= a->size; j++)
	{
		int key = from_file[j];
		int i = j - 1;
		while (i  > 0 && from_file[i] > key)
		{
			from_file[i + 1] = from_file[i];
			i--;
		}
		from_file[i + 1] = key;
	}

	//Add sorted array to the new array without the first element
	for (int i = 1; i <= size; i++)
	{
		a->data[i - 1] = from_file[i];
	}

	if (print) {
		printf("After sorting:  ");

		for (int i = 0; i < a->size; i++)
		{
			printf("%d ", a->data[i]);
		}
		printf("\n");
	}

	//Return the new sorted array
	return a->data;
}
