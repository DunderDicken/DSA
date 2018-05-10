#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define TRUE 1
#define FALSE 0

/* Creat new queues */
QueueList * createQueueList()
{
	QueueList * tmp_Queue = (QueueList*)malloc(sizeof(QueueList));
	tmp_Queue->list = createList();

	tmp_Queue->head = tmp_Queue->list->nil->next;
	tmp_Queue->tail = tmp_Queue->list->nil->prev;

	return tmp_Queue;
}

QueueArray * createQueueArray(int length)
{
	QueueArray* tmp_Queue = (QueueArray*)malloc(sizeof(QueueArray));
	tmp_Queue->data = (int*)malloc(length * sizeof(int));


	tmp_Queue->head = 0;
	tmp_Queue->current_size = 0;
	tmp_Queue->tail = length -1;
	tmp_Queue->length = length;

	return tmp_Queue;
}

/* OPERATIONS */

int isQueueListEmpty(QueueList* q)
{
	return isListEmpty(q->list);
}

int isQueueArrayEmpty(QueueArray * q)
{
	if (q->current_size == 0)
	{
		return TRUE;
	}
	return FALSE;
}

int isQueueArrayFull(QueueArray * q)
{
	if (q->current_size == q->length)
	{
		return TRUE;
	}

	return FALSE;
}


enQueue(QueueList* q, int key)
{
	insert(q->list, newListElementWithKey(key));

	q->head = q->list->nil->prev;
	q->tail = q->list->nil->next;

}

enQueueArray(QueueArray * q, int key)
{
	

	if (isQueueArrayFull(q) == TRUE)
	{
		printf("Overflow error! Queue is full. \n");
		printf("Could not push key: %d . \n", key);
		return;
	}

	q->tail = (q->tail +1) % q->length;
	
	q->data[q->tail] = key;
	
	q->current_size++;
	
}

int* deQueue(QueueList* q)
{
	if (isQueueListEmpty(q) == TRUE)
	{
		return NULL;
	}

	int* returnedKey = malloc(sizeof(int));

	*returnedKey = q->head->key;

	deleteElement(q->list, q->head);

	q->head = q->list->nil->prev;
	q->tail = q->list->nil->next;

	return returnedKey;
}

int * deQueueArray(QueueArray * q)
{
	//Return null to indicate underflow error
	if (isQueueArrayEmpty(q) == TRUE)
	{
		return NULL;
	}

	int* returned_key = (int*)malloc(sizeof(int));

	*returned_key = q->data[q->head];
	
	q->head = (q->head + 1) % q->length;

	q->current_size--;	
	
	return returned_key;
}
