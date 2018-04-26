#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"

#define NUM_TEST 10

void testInsert(List* lst);
void testpredecessor(List* lst);

int main() {

	List* list1 = createList();

	//testInsert(list1);
	testPredecessor();
	

	

	free(list1);

	return 0;
}



void testInsert(List * lst)
{
	int test[NUM_TEST] = { 1,2,3,4,5,6,7,8,9,10 };
	int return_value;

	//Test if the list is empty
	return_value = isListEmpty(lst);
	
	if (return_value == 0)
	{
		printf("Test failed. List was not empty \n");
	}

	//Insert 10 new listElements to the list
	for (int i = 0; i < NUM_TEST; i++)
	{
		insert(lst, newListElementWithKey(test[i]));
	}

	//Test if the list is empty
	return_value = isListEmpty(lst);
	if (return_value == 1)
	{
		printf("Test failed. List was empty \n");
	}

	ListElement* tmp = lst->nil->prev;
	int i = 0;

//Check if all keys in list is added correctly
	while (tmp != lst->nil)
	{
		return_value = tmp->key;

		if (return_value != test[i])
		{
			printf("Test failed. Missing number \n");
		}
		tmp = tmp->prev;
		i++;
		
	}
	
}

void testpredecessor(List* lst) {

}