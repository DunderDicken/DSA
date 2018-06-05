/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>

/* INCLUDES MY FILES */
#include "BinarySearchTree.h"

TreeElement * newElement(int key)
{
	TreeElement* tmp = (TreeElement*)malloc(sizeof(TreeElement));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->parent = NULL;
	tmp->key = key;
	return tmp;
}

Tree * newTree()
{
	Tree* tmp = (Tree*)malloc(sizeof(Tree));
	tmp->root = NULL;

		/*(TreeElement*)malloc(sizeof(TreeElement));
	tmp->root->key = NULL;
	tmp->root->left = NULL;
	tmp->root->right = NULL;
	tmp->root->parent = NULL;*/

	return tmp;
}

bool isTreeEmpty(Tree * T)
{
	if (T->root == NULL )
	{
		return true;
	}
	return false;
}

void tree_insert(Tree* T, TreeElement* z)
{
	TreeElement* y = NULL;
	TreeElement* x = T->root;

	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	z->parent = y;

	if (y == NULL) // Tree was empty
	{
		T->root = z;
	}
	else if (z->key < y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
	
}

void tree_delete(Tree * T, TreeElement * z)
{
	if (z->left == NULL) //z has no left child
	{
		tree_transplant(T, z, z->right);
	}
	else if (z->right == NULL) //z has left child but no right child
	{
		tree_transplant(T, z, z->right);
	}
	else
	{
		TreeElement* y = tree_minimum(z->right); //y = successor of z

		if (y->parent != z)
		{
			tree_transplant(T, y, y->right);

			y->right = z->right;
			y->right->parent = y;
		}
		tree_transplant(T, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}

void tree_transplant(Tree * T, TreeElement * u, TreeElement * v)
{

	if (u->parent == NULL) //if u is the root of T
	{
		T->root = v;
	}
	else if (u == u->parent->left) // if u is a left child
	{
		u->parent->left = v;
	}
	else //if u is a right child
	{
		u->parent->right = v;
	}
	if (v != NULL)
	{
		v->parent = u->parent;
	}
}

TreeElement * tree_search(TreeElement * TE, int key)
{
	if (TE == NULL || key == TE->key)
	{
		return TE;
	}
	if (key<TE->key)
	{
		return tree_search(TE->left, key);
	}
	else
	{
		return tree_search(TE->right,key);
	}
}

TreeElement * tree_search_iterative(TreeElement * TE, int key)
{
	while (TE != NULL && key != TE->key)
	{
		if (key < TE->key)
		{
			TE = TE->left;
		}
		else
		{
			TE = TE->right;
		}
	}
	return TE;
}

TreeElement * tree_maximum(TreeElement * TE)
{
	while (TE->right != NULL)
	{
		TE = TE->right;
	}
	return TE;
}

TreeElement * tree_minimum(TreeElement * TE)
{
	while (TE->left != NULL)
	{
		TE = TE->left;
	}
	return TE;
}

TreeElement * tree_successor(TreeElement * TE)
{
	if (TE->right != NULL)
	{
		return tree_minimum(TE->right);
	}
	TreeElement* tmp = TE->parent;

	while (tmp != NULL && TE == tmp->right)
	{
		TE = tmp;
		tmp = tmp->parent;
	}
	return tmp;
}

void in_order_tree_walk(TreeElement * TE)
{
	if (TE != NULL)
	{
		in_order_tree_walk(TE->left);
		printf("%d ", TE->key);
		in_order_tree_walk(TE->right);
	}
	
}
