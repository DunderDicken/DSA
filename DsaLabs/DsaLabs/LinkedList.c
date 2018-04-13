#include "LinkedList.h"
#include <stdio.h>


List* createList()
{
	List* newList = (List*)malloc(sizeof(List));
	newList->head = malloc(sizeof(ListElement));

	newList->head->next = newList->head;
	newList->head->prev = newList->head;

	newList->size = 0;

	return newList;
}

ListElement* newListElement(int k)
{
	ListElement* newElement = malloc(sizeof(ListElement));

	newElement->key = k;
	newElement->next = NULL;
	newElement->prev = NULL;

	return newElement;
}

insert(List * list, ListElement * listElement)
{
	listElement->next = list->head->next;

	list->head->next->prev = listElement;

	list->head->next = listElement;

	listElement->prev = list->head;
}


isListEmpty(List* l)
{
	if (l->head->next == l->head)
	{
		printf("List is empty \n");
	}
	else
		printf("List is NOT empty ");
}

