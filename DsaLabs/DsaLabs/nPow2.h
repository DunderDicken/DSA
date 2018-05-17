#pragma once
#include "LinkedList.h"

/* STRUCTS */
typedef struct bit_array
{
	int* data;
	int size;

}BitArray;

BitArray* newBitArray();

List* nPow2_List(List* n, int k);

nPow2_Array(BitArray* n, int k);

void print_Bit_Array(BitArray *array);

int bit_to_int(BitArray* ba);