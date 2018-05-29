#pragma once
/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>
#include  "stdbool.h"

/* INCLUDE MY FILES */
#include "load_file.h"
#include "LinkedList.h"


/* FUNCTIONS */

//Reads a file conatining numbers and returns a sorted DLL with sentinel
List* merge_sort_from_file(const char* fName, bool print);

//Main merge sort function
ListElement* merge_sort(ListElement* sourceElement);

//Merges two lists
ListElement* merge(ListElement* l, ListElement* r);

//Splits two lists
ListElement* left_right_split(ListElement* head);

/* UTILITY FRUNCTIONS */
List* array_2_list(int* a);

void printSingeList(ListElement* l);