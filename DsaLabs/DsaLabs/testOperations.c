#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

int main() {

	List* list1 = createList();

	isListEmpty(list1);

	ListElement* el1 = newListElement();
	el1->key = 3;

	insert(list1, el1);
	

	isListEmpty(list1);

	int key = list1->head->next->key;

	printf("In list: %d \n", key);


	free(list1);
	return 0;
}