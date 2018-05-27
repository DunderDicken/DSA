#include "merge_sort.h"
#include <math.h>

List* merge_sort_from_file(const char * fName, bool print)
{

	int* a = load_file(fName);

	List* A = array_2_list(a);

	merge_sort(A->nil->next);

	return A;
}

void merge_sort(ListElement* sourceList)
{
	ListElement* head = sourceList;
	ListElement* left;
	ListElement* right;

	//If the list is empty, return
	if (head->next == NULL)
	{
		return;
	}

	left_right_split(head, left, right);

	merge_sort(left);
	merge_sort(right);

	//merge(left,right);

	//if (p < r)
	//{
	//	int q = (int)floor((p + r) / 2);

	//	merge_sort(A, p, q); //Left
	//	merge_sort(A, q+1, r); //Right

	//	merge(A, p, q, r);

	//}
}

ListElement* merge(ListElement* left, ListElement* right)
{
	if (!left)
	{
		return right;
	}
	if (!right)
	{
		return left;
	}


	if (left->key < right->key)
	{
		left->next = merge(left, right->next);
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

List * array_2_list(int * a)
{
	List* list = createList();

	int size = a[0];
	for (int i = 1; i <= size; i++)
	{
		insert(list, newListElementWithKey(a[i]));
	}

	return list;	
}

void left_right_split(ListElement * head, ListElement * left, ListElement * right)
{
	ListElement* fast = head->next;
	ListElement* slow = head;

	while (fast != NULL)
	{
		fast = fast->next;

		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	

	
	/*'slow' is before the midpoint in the list, so split it in two
    at that point. */
}
