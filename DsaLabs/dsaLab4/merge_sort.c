#include "merge_sort.h"
#include <math.h>

List* merge_sort_from_list(List* A, bool print)
{
	/* Init linked list for merge sort, remove pointers to sentinel*/
	A->nil->next->prev = NULL;
	A->nil->prev->next = NULL;

	if (print)
	{
		printf("Before sorting: ");
		printSingeList(A->nil->next);
	}

	/* Do the merge sort*/
	ListElement* result = merge_sort(A->nil->next);
	
	/* Add back prev-pointers and pointers to sentinel, making the list doubly linked again*/
	A->nil->next = result;
	result->prev = A->nil;

	ListElement* temp = A->nil->next;
	while (temp->next != NULL)
	{
		temp->next->prev = temp;
		temp = temp->next;
	}
	temp->next = A->nil;

	if (print)
	{
		printf("After sorting:	");
		print_list(A);
	}
	
	/* Return the final doubly linked list with sentinel */
	return A;
}

/* Main merge sort function */
ListElement* merge_sort(ListElement* sourceElement)
{
	
	//If the list is empty, return the source element
	if (sourceElement == NULL || sourceElement->next == NULL)
	{
		return sourceElement;
	}

	/* Split the list to two lists */
	ListElement* second = left_right_split(sourceElement);

	/* Recursive function for the two lists */
	sourceElement = merge_sort(sourceElement);
	second = merge_sort(second);

	/* Merge the two lists and return */
	return merge(sourceElement,second);

}

/* Merge two lists */
ListElement* merge(ListElement* left, ListElement* right)
{
	/* If one list is empty, return the other list */
	if (!left)
	{
		return right;
	}
	if (!right)
	{
		return left;
	}

	/* Merge based on the smallest key */
	if (left->key < right->key)
	{
		left->next = merge(left->next, right);
		left->next->prev = left;
		left->prev = NULL;
		return left;

	}
	else
	{
		right->next = merge(left, right->next);
		right->next->prev = right;
		right->prev = NULL;
		return right;
	}
	
}

/* Takes an array and returns a doubly linked list with sentinel */
List * array_2_list(int * a)
{
	List* list = createList();

	int size = a[0];

	// Starts from the [1] element in the array, because this is only the size of the array
	for (int i = 1; i <= size; i++)
	{
		insert(list, newListElementWithKey(a[i]));
	}

	return list;	
}

/*	Splits the list to two lists. * 
 *	Uses the fast/slow method.	  */
ListElement* left_right_split(ListElement * head)
{
	ListElement* fast = head;
	ListElement* slow = head;

	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListElement *temp = slow->next;
	slow->next = NULL;
	return temp;

}

/* Prints a single linked list, where NULL is a mark for the end of the list*/
void printSingeList(ListElement * l)
{
	while (l != NULL)
	{
		printf("%d ", l->key);
		l = l->next;
	}
	printf("\n");
}
