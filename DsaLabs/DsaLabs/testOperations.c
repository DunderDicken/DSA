#include <stdio.h>

#include "LinkedList.h"

int main() {

	List* list1 = createList();

	isListEmpty(list1);


	free(list1);

	return 0;
}