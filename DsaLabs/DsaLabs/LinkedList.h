#pragma once


typedef struct list_element_t {

	int key;
	struct list_element_t *next;
	struct list_element_t *prev;

}ListElement;

typedef struct{

	struct list_element_t *head;
	int size;

}List;

//creates new empty list wich points to itself
List* createList();

//creates new empty ListElement
ListElement* newListElement();

//creates new ListElement with key
ListElement* newListElementWithKey(int k);

//prints out if list is empty or nor ( Does Head points to itself?)
isListEmpty(List*);

insert(List* list, ListElement* listElement);
