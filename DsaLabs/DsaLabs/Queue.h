/*
	This program implements Queues with a linked list and with an array.
*/

#pragma once
#include "LinkedList.h"

/* STRUCTS */

/*Ex_4:*/
typedef struct Queue_with_LinkedList {

	List* list;
	ListElement* head;
	ListElement* tail;

}QueueList;

/*Ex_5:*/
typedef struct Queue_with_array {

	int* data;
	int head,
		tail,
		length,
		current_size;

}QueueArray;

/* CREATE NEW QueueS */
QueueList* createQueueList(); //Ex_4

QueueArray* createQueueArray(int length); //Ex_5

/* OPERATIONS */

//Returns 0 if que is empty, otherwise returns 1
int isQueueListEmpty(QueueList* q); //Ex_4

//Returns 0 if que is empty, otherwise returns 1
int isQueueArrayEmpty(QueueArray* q);

//Returns 1 if que is full, otherwise returns 0
int isQueueArrayFull(QueueArray* q);

//Enqueues an element with key k
enQueue(QueueList* q, int key); //Ex_4

enQueueArray(QueueArray* q, int key); //Ex_4

//Returns the element in the head of the queue, returns NULL if queue is empty. 
int* deQueue(QueueList* q); //Ex_4

int* deQueueArray(QueueArray* q);