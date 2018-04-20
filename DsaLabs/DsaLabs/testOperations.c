#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main() {

	List* list1 = createList();

	isListEmpty(list1);

	ListElement* el1 = newListElementWithKey(1);
	ListElement* el2 = newListElementWithKey(2);
	ListElement* el3 = newListElementWithKey(3);
	ListElement* el4 = newListElementWithKey(4);
	ListElement* el5 = newListElementWithKey(5);
	ListElement* el6 = newListElementWithKey(6);


	insert(list1, el1);
	insert(list1, el2);
	insert(list1, el3);
	insert(list1, el4);
	insert(list1, el5);
	
	predecessor(list1, listSearch(list1, 3));


	free(list1);
	
	return 0;
}