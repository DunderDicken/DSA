#pragma once
/* INCLUDES */
#include  "stdbool.h"

/* STRUCTS */

/*Binary search Tree element*/
typedef struct BST_element {

	int key;
	struct BST_element * left;
	struct BST_element * right;
	struct BST_element * parent;
	
	
}TreeElement;

/* Binary search Tree*/
typedef struct BST_tree {
	
	TreeElement * root;
	
}Tree;

/* FUNCTIONS */

//Returns a pointer to a treeElement with given key
TreeElement * newElement(int key);

//Returns a ponter to a empty tree
Tree* newTree();

//Returns true if the tree is empty, otherwise returns false
bool isTreeEmpty(Tree* T);

//Insert a TreeElement TE to given Tree T
void tree_insert(Tree* T, TreeElement* TE);

//Deletes element z from tree T
void tree_delete(Tree* T, TreeElement* z);

//Replaces a subtree rooted at element u with the subtree rooted at element v
void tree_transplant(Tree* T, TreeElement* u, TreeElement* v);

//Searches the three for the given key and returns a pointer to it if it exist
//otherwise returns NULL.
TreeElement* tree_search(TreeElement* TE, int key);

TreeElement* tree_search_iterative(TreeElement* TE, int key);

//Returns a pointer to the element with the maximum key-value
TreeElement* tree_maximum(TreeElement* TE);

//Returns a pointer to the element with the minimum key-value
TreeElement* tree_minimum(TreeElement* TE);

//Returns a pointer to the treeElement with the smallest key that is greater than 
//the key of the given element TE. Returns NULL if TE has the biggest key.
TreeElement* tree_successor(TreeElement* TE);


/* UTILITY FUNCTIONS */

//Prints the Tree in order
void in_order_tree_walk(TreeElement* TE);
