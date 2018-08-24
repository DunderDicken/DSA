#pragma once
/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include  "stdbool.h"

/*INCLUDE MY FILES*/
#include "LinkedList.h"

/*STRUCTS*/

//Represents a Node in a adjacency list
typedef struct Adjacency_List_Node {

	int vertex; //Data or Key of node
	int weight;
	struct Adjacency_List_Node* next;
	
}AdjListNode;

//Represents a adjacency List
typedef struct Adjacency_List {

	AdjListNode* head;

}AdjList;

//Represents a GraphListList.
//A GraphList is a array of adjacency lists
typedef struct GraphList_data_structure {

	int numVertices; // The size of the GraphList, number of vertices
	int numEdges; //Number of edges in the GraphList
	AdjList* array;

}GraphList;

/*FUNCTIONS*/


//Returns the number of vertices in GraphList G
int* getNumVertices(GraphList* G);

//Returns the number of edges in GraphList G
int* getNumEdges(GraphList* G);

//Returns all vertices connected to node v with any edge
List* getNeighbors(GraphList* G, int v);

//Returns all vertices connected to node v with any edge <-- fel
List* getInNeighbors(GraphList* G, int v);

//Returns all vertices connected to node v with any edge <-- fel
List* getOutNeighbors(GraphList* G, int v);

//Creates a directed edge from src to dst
void addDirectedEdge(GraphList* G, int src, int dst);

//Creates a undirected edge between v1 and v2
void addUndirectedEdge(GraphList* G, int v1, int v2);

/* UTILITY FUNCTIONS*/

//Createas a GraphList with n vertices and returns it. Initilizes the GraphList.
GraphList* createGraphList(int n);

//Creates a new AdjListNode
AdjListNode* newAdjListNode(int v);

//Prints the adjacency list representation of of GraphList G
void printGraphList(GraphList* G);

