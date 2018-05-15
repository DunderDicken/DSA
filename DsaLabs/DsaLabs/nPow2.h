#pragma once
#include "LinkedList.h"

/* STRUCTS */
typedef struct bit_array
{
	int* data;
	int size;

}BitArray;

BitArray* newBitArray(int size);

List* nPow2_List(List* n, int k);

BitArray* nPow2_Array(BitArray* n, int k);