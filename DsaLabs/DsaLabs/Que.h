#pragma once
#include "LinkedList.h"

typedef struct que_with_LinkedList {

	List* list;
	ListElement* head;
	ListElement* tail;

}QueList;

typedef struct que_with_array {

	int* data;
	int head;
	int tail;
	int size;

}QueArray;

QueList* createQueList();

QueArray* createQueArray();

int isQueListEmpty(QueList* q);

int isQueArrayEmpty(QueArray* q);

enqueue(QueList* q, int key);

enqueueArray(QueArray* q, int key);

int* dequeue(QueList* q);

int* dequeueArray(QueArray* q);