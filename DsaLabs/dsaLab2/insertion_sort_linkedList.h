#pragma once

#include "LinkedList.h"
#include  "stdbool.h"

List* insertionSortList(const char* fName, bool print);

void sortedInsertList(List* list, ListElement* newElement);

List* array2List(int* a);

int* list2Array(List* list);

