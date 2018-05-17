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

int bit_to_int(BitArray * ba)
{
	int sum = 0,
		value = 0;

	for (int i = 0; i < ba->size; i++) {

		if (ba->data[i])
		{
			sum = sum + 
		}
		/*value = ba->data[i] * (ba->size/)
		sum = sum + value;*/

	}
	return 0;
}
