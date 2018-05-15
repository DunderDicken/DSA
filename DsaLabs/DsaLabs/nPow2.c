#include "nPow2.h"

#include <stdio.h>
#include <stdlib.h>

BitArray* newBitArray(int size) {
	BitArray* temp = (BitArray*)malloc(sizeof(BitArray));

	temp->data = (int*)malloc(size * sizeof(int));
	temp->size = size;

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
