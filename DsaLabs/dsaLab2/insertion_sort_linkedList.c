#include <stdio.h>
#include <stdlib.h>
#include "load_file.h"
#include "LinkedList.h"
#include "insertion_sort_linkedList.h"

List* insertionSortList(const char * fName, bool print)
{
	//Load numbers from the file
	int* a = load_file(fName);
	int size = a[0];

	List* sortedList = createList();
	
	if (print)
		printf("Before sorting: ");

	//Outer loop of the insertion sorts function
	for (int j = 1; j <= size; j++)
	{
		ListElement* current = newListElementWithKey(a[j]);
		
		if (print)
			printf("%d ", a[j]);

		//Inner loop of insertion sort, Inserts the number in sorted order to the list
		sortedInsertList(sortedList, current);

	}
	if (print)
	{
		printf("\n");

		printf("After sorting:  ");
		print_list(sortedList);
		
	}
	

	return sortedList;
}

void sortedInsertList(List * list, ListElement * newElement)
{
	//If newElement is the first element in the list, insert at nil.next
	if (isListEmpty(list) )
	{
		insert(list, newElement);
	}

	//If the newElement is smaller than the first element in the sorted list
	//Insert at the beginning (nil.next)
	else if (list->nil->next->key >= newElement->key)
	{
		insert(list, newElement);
	}

	else
	{
		ListElement *current = list->nil->next;

		while (current->next != list->nil &&  newElement->key > current->next->key)
		{
			current = current->next;
		}

		newElement->next = current->next;

		//if the new element is not to be inserted at the end of the sorted list
		if (current->next != list->nil)
		{
			newElement->next->prev = newElement;
		}

		current->next = newElement;
		newElement->prev = current;

		//increase the size of the list
		list->size++;

	}
}

List * array2List(int * a)
{
	List* list = createList();

	int size = a[0];
	for (int i = 1; i <= size; i++) 
	{
		insert(list, newListElementWithKey(a[i]));
	}


	return list;
}

int * list2Array(List * list)
{
	ListElement* tmp = list->nil->next;

	int* array = (int*)malloc((list->size) * sizeof(int));

	for (int i = 0; i <= list->size; i++)
	{
		array[i] = tmp->key;
		tmp = tmp->next;

	}

	return array;

}

