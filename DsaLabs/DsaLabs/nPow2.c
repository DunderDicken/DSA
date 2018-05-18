#include "nPow2.h"

#include <stdio.h>
#include <stdlib.h>

/* CONSTANTS */
#define NUMBER_OF_BITS 8

BitArray* newBitArray() {
	BitArray* temp = (BitArray*)malloc(sizeof(BitArray));

	temp->data = (int*)malloc(NUMBER_OF_BITS * sizeof(int));
	temp->size = NUMBER_OF_BITS;

	return temp;
}

nPow2_List(List * n, int k)
{
	ListElement* old_top = n->nil->next;
	ListElement* old_bottom = n->nil->prev;

	n->nil->next = old_top->next;
	n->nil->next->prev = n->nil;
	n->nil->prev = old_top;

	old_top->next = n->nil;
	old_top->prev = old_bottom;

	old_bottom->next = old_top;

	

	
}

nPow2_Array(BitArray * n, int k)
{
	for (size_t i = 0; i < k; i++)
	{
		int temp = n->data[0];

		for (int i = 0; i < n->size - 1; i++)
		{
			n->data[i] = n->data[i + 1];
		}
		n->data[n->size - 1] = temp;
	}

}

void print_Bit_Array(BitArray * array)
{
	for (int i = 0; i < array->size; i++)
	{
		printf("%d ", array->data[i]);
	}
	printf(" \n");
}

void print_Bit_List(List * list)
{
	ListElement* tmp = list->nil->prev;

	while (tmp != list->nil)
	{
		printf("%d ", tmp->key);
		tmp = tmp->prev;
	}
	printf(" \n");
}

int bit_to_int(BitArray * ba)
{
	int sum = 0,
		valueOfPos = 1;

	for (int i = ba->size-1; i > 0; i--) {
		
		if (ba->data[i] == 1)
		{
			sum = sum + valueOfPos;
		}
		
		valueOfPos = valueOfPos * 2;
		
	}
	return sum;
}
