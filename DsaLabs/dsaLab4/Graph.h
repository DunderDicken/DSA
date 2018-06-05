#pragma once
/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>

/*INCLUDE MY FILES*/
#include "LinkedList.h"

/*STRUCTS*/

//Represents a Node in a adjacency list
typedef struct Adj_List_Node {

	ListElement* node;
	
}AdjListNode;

//Represents a adjacency List
typedef struct Adj_List {

	AdjListNode* head;

}AdjList;

//Represents a Graph.
//A graph is a array of adjacency lists
typedef struct Graph_data_structure {

	int numVertices; // The size of the graph, number of vertices
	AdjList* array;

}Graph;

/*FUNCTIONS*/

//Createas a graph with n vertices and returns it. Initilizes the graph.
Graph* createGraph(int n);