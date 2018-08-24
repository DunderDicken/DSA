#pragma once
/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include  "stdbool.h"

/*INCLUDE MY FILES*/
#include "LinkedList.h"

/*STRUCTS*/

typedef struct Adjacency_Matrix_Node {

	int data;
	int* outedges;

}Node;

typedef struct Graph_Sata_Strucuture {

	Node** matrix; //Matrix of nodes
	int NumOfNodes;					//Number of nodes in the Graph

}Graph;

/* UTILITY FUNCTIONS*/

//Createas a Graph with n vertices and returns it. Initilizes the Graph.
Graph* createGraph(int n);