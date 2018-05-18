#pragma once
#include "LinkedList.h"

/* STRUCTS */
typedef struct bit_array
{
	int* data;
	int size;

}BitArray;

BitArray* newBitArray();


nPow2_List(List* n, int k);

nPow2_Array(BitArray* n, int k);

void print_Bit_Array(BitArray *array);

void print_Bit_List(List* list);

int bit_to_int_array(BitArray* ba);

int bit_to_int_list(List* l);