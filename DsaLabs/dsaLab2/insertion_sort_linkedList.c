#include <stdio.h>
#include <stdlib.h>

#include "insertion_sort_linkedList.h"

void insertionSort(const char * fName)
{
	List* list = createList();

	int* a = load_file(fName);

	int size = a[0];
	for (int i = 1; i <= size; i++) // note this loops from 1 <= i <= size
	{
		insert(list, newListElementWithKey(a[i]));
	}

	
}
