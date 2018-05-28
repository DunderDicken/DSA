#pragma once
#include <stdio.h>
#include <stdlib.h>
#include  "stdbool.h"
#include "load_file.h"
#include "LinkedList.h"

/* STRUCTS */


List* merge_sort_from_file(const char* fName, bool print);

ListElement* merge_sort(ListElement* sourceElement);


ListElement* merge(ListElement* l, ListElement* r);

List* array_2_list(int* a);

ListElement* left_right_split(ListElement* head);

void printSingeList(ListElement* l);