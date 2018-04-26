#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#define NUM_TEST 10

int testPredecessor(){

	List* list1 = createList();
	int test[NUM_TEST] = { 1,2,3,4,5,6,7,8,9,10 };
	
	//Insert 10 new listElements to the list
	for (int i = 0; i < NUM_TEST; i++)
	{
		insert(list1, newListElementWithKey(test[i]));
	}

	predecessor(list1,listSearch(list1,1));
	predecessor(list1, listSearch(list1, 10));
	predecessor(list1, listSearch(list1, 5));

	free(list1);
	return 0;
}