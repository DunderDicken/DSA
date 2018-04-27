#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>


List* createList()
{
	List* newList = (List*)malloc(sizeof(List));
	newList->nil = (ListElement*)malloc(sizeof(ListElement));

	newList->nil->next = newList->nil;
	newList->nil->prev = newList->nil;

	newList->size = 0;

	return newList;
}

ListElement* newListElement()
{
	ListElement* newElement = malloc(sizeof(ListElement));

	newElement->key;
	newElement->next = NULL;
	newElement->prev = NULL;

	return newElement;
}

ListElement * newListElementWithKey(int k)
{
	ListElement* newElement = malloc(sizeof(ListElement));

	newElement->key = k;
	newElement->next = NULL;
	newElement->prev = NULL;

	return newElement;
}

int isListEmpty(List* lst)
{
	if (lst->nil->next == lst->nil)
	{
		return 1;
	}

	return 0;
}

insert(List * list, ListElement * listElement)
{
	listElement->next = list->nil->next;

	list->nil->next->prev = listElement;

	list->nil->next = listElement;

	listElement->prev = list->nil;

	list->size++;
}

ListElement * listSearch(List * list, int k)
{
	ListElement* tmp = list->nil->next;

	while (tmp != list->nil && tmp->key != k)
	{
		tmp = tmp->next;
	}
	return tmp;
}

deleteElement(List * list, ListElement * listElement)
{
	listElement->prev->next = listElement->next;
	listElement->next->prev = listElement->prev;

	free(listElement);
}

ListElement * minimum(List * list)
{
	ListElement * tmp = list->nil->next;
	ListElement * min = tmp;

	while (tmp != list->nil)
	{
		if (min->key > tmp->key)
		{
			min = tmp;
		}
		tmp = tmp->next;
	}
	return min;
}

ListElement * maximum(List * list)
{
	ListElement * tmp = list->nil->next;
	ListElement * max = tmp;

	while (tmp != list->nil)
	{
		if (max->key < tmp->key)
		{
			max = tmp;
		}
		tmp = tmp->next;
	}
	return max;
}

ListElement * successor(List * list, ListElement * listElement)
{
	ListElement * tmp = list->nil->next;
	ListElement * succ = listElement;

	while (tmp != list->nil)
	{
		//First update
		if (succ == listElement && tmp->key > succ->key)
		{
			succ = tmp;
		}

		if (tmp->key > listElement->key && tmp->key < succ->key)
		{
			succ->key = tmp->key;

		}
		tmp = tmp->next;
	}

	//if listElement.key is the largest number, return nil.
	if (succ == listElement)
	{
		succ = list->nil;
	}

	return succ;
}



ListElement * predecessor(List * list, ListElement * listElement)
{
	ListElement * tmp = list->nil->next;
	ListElement * pre = listElement;

	while (tmp != list->nil)
	{
		//First update
		if (pre == listElement && tmp->key < pre->key)
		{
			pre = tmp;
		}

		if (tmp->key < listElement->key && tmp->key > pre->key)
		{
			pre->key = tmp->key;

		}
		tmp = tmp->next;
	}

	//if listElement.key is the largest number, return nil.
	if (pre == listElement)
	{
		pre = list->nil;
	}

	return pre;
}

