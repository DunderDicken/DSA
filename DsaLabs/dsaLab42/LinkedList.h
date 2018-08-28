/*	
	This implements a doubly linked list with a sentinel. 
	The sentinel is called "nil" in the List struct.
*/
#pragma once


/*  STRUCTS  */

typedef struct list_element_t {

	int key;
	struct list_element_t *next;
	struct list_element_t *prev;

}ListElement;

typedef struct{

	struct list_element_t *nil;
	int size;

}List;
 
/* CREATE NEW ELEMENTS AND LISTS */

//creates new empty list (Nil points to itself)
List* createList();

//creates new empty ListElement
ListElement* newListElement();

//creates new ListElement with key
ListElement* newListElementWithKey(int k);

//Returns 0 if list is empty, otherwise returns 1 ( Does nil points to itself?)
int isListEmpty(List*);


/* DYNAMIC SET OPERATIONS */

//Inserts given element to given list
insert(List* list, ListElement* listElement);

//Returns a pointer to a element in a given list with given key
ListElement* listSearch(List* list, int k);

//Deletes element listElement from given list
void deleteElement(List* list, ListElement* listElement);

//Returns a pointer to the element with the smalles key in the list
ListElement* minimum(List* list);

//Returns a pointer to the element with the largest key in the list
ListElement* maximum(List* list);

//Returns a pointer to the next larger element from given element in a list
ListElement* successor(List* list, ListElement* listElement);

//Returns a pointer to the next smaller element from given element in a list
ListElement* predecessor(List* list, ListElement* listElement);

//Prints the list from nil.next to nil
void print_list(List * list);
