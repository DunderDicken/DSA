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

	int vertex;
	int weight;
	struct Adjacency_List_Node* next;
	
}AdjListNode;

//Represents a adjacency List
typedef struct Adjacency_List {

	AdjListNode* head;

}AdjList;

//Represents a Graph.
//A graph is a array of adjacency lists
typedef struct Graph_data_structure {

	bool isDirected;
	int numVertices; // The size of the graph, number of vertices
	int numEdges; //Number of edges in the graph
	AdjList* array;

}Graph;

/*FUNCTIONS*/


//Returns the number of vertices in graph G
int* getNumVertices(Graph* G);

//Returns the number of edges in graph G
int* getNumEdges(Graph* G);

//Returns all vertices connected to node v with any edge
List* getNeighbors(Graph* G, int v);

//Returns all vertices connected to node v with any edge
List* getInNeighbors(Graph* G, int v);

//Returns all vertices connected to node v with any edge
List* getOutNeighbors(Graph* G, int v);

//Creates a directed edge from src to dst
void addDirectedEdge(Graph* G, int src, int dst);

//Creates a undirected edge between v1 and v2
void addUndirectedEdge(Graph* G, int v1, int v2);

/* UTILITY FUNCTIONS*/

//Createas a graph with n vertices and returns it. Initilizes the graph.
Graph* createGraph(int n);

//Creates a new AdjListNode
AdjListNode* newAdjListNode(int v);

//Prints the adjacency list representation of of graph G
void printGraph(Graph* G);

