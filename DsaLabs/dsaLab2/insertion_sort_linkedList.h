/*
	Implements a insertion sort algorithm with a Linked List
*/
#pragma once

/* Includes */
#include "LinkedList.h"
#include  "stdbool.h"


/* FUNCTIONS */

/*This is the function that is called from outside the file.
 *Takes a filename and a bool flag as input. The file is where
 *the numbers are. The flag tells the program to print the numbers or not  */
List* insertionSortList(const char* fName, bool print);

/* Inserts numbers from the file to the Linked list in sorted order */
void sortedInsertList(List* list, ListElement* newElement);


/* UTILITY FUNCTIONS */

/* Takes an array as input and returns a list with the same keys in the same order*/
List* array2List(int* a);

/* Takes an list as input and returns a array with the same keys in the same order*/
int* list2Array(List* list);

