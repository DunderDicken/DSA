#pragma once


typedef struct list_element_t {

	int key;
	struct list_element_t *next;
	struct list_element_t *prev;

}ListElement;

typedef struct{

	struct list_element_t *nil;
	int size;

}List;

//creates new empty list wich points to itself
List* createList();

//creates new empty ListElement
ListElement* newListElement();

//creates new ListElement with key
ListElement* newListElementWithKey(int k);

//Returns 0 if list is empty, otherwise returns 1 ( Does nil points to itself?)
int isListEmpty(List*);


//OPERATIONS

//Inserts element to list
insert(List* list, ListElement* listElement);

//Returns a pointer to a element in a list
ListElement* listSearch(List* list, int k);

//Deletes element listElement from given list
deleteElement(List* list, ListElement* listElement);

//Returns a pointer to the element with the smalles key in the list
ListElement* minimum(List* list);

//Returns a pointer to the element with the largest key in the list
ListElement* maximum(List* list);

//Returns a pointer to the next larger element from given element in a list
ListElement* successor(List* list, ListElement* listElement);

//Returns a pointer to the next smaller element from given element in a list
ListElement* predecessor(List* list, ListElement* listElement);


/*


PREDECESSOR.S; x/
A query that, given an element x whose key is from a totally ordered set S,
returns a pointer to the next smaller element in S, or NIL if x is the minimum
element.Part III Data Structures 231
In

*/