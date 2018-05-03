#include "Que.h"
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

QueList * createQueList()
{
	QueList * tmp_que = (QueList*)malloc(sizeof(QueList));
	tmp_que->list = createList();

	tmp_que->head = tmp_que->list->nil->next;
	tmp_que->tail = tmp_que->list->nil->prev;

	return tmp_que;
}

QueArray * createQueArray()
{
	QueArray* tmp_que = (QueArray*)malloc(sizeof(QueArray));


	return NULL;
}

int isQueListEmpty(QueList* q)
{
	return isListEmpty(q->list);
}

int isQueArrayEmpty(QueArray * q)
{
	return 0;
}


enqueue(QueList* q, int key)
{
	insert(q->list, newListElementWithKey(key));

	q->head = q->list->nil->next;
	q->tail = q->list->nil->prev;

}

enqueueArray(QueArray * q, int key)
{
}

int* dequeue(QueList* q)
{
	if (isQueListEmpty(q) == TRUE)
	{
		return NULL;
	}

	int* returnedKey = malloc(sizeof(int));

	*returnedKey = q->tail->key;

	deleteElement(q->list, q->tail);

	q->head = q->list->nil->next;
	q->tail = q->list->nil->prev;

	return returnedKey;
}

int * dequeueArray(QueArray * q)
{
	return NULL;
}
