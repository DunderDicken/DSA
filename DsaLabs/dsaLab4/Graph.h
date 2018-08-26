#pragma once
/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>
#include  "stdbool.h"
#include <time.h>

/*INCLUDE MY FILES*/
#include "LinkedList.h"


/*STRUCTS*/

typedef struct Adjacency_Matrix_Node {

	int data;
	int* outedges;

}Node;

typedef struct Graph_Sata_Strucuture {

	Node** matrix;  //Matrix of nodes
	int NumOfNodes;	//Number of nodes in the Graph
	bool isDirected;

}Graph;

/*FUNCTIONS*/

//Returns the number of vertices in GraphList G
int * getNumVertices(Graph * G);

//Returns the number of edges in GraphList G
int * getNumEdges(Graph * G);

//Returns all vertices connected to node v with any edge
List* getNeighbors(Graph* G, int v);

//Returns a list of all vertices v' connected to node v with an edge (v', v)
List * getInNeighbors(Graph * G, int v);

//Returns a list of all vertices v' connected to node v with an edge (v, v')
List * getOutNeighbors(Graph * G, int v);

//Returns true (1) if there is an edge between v1 and v2 and false (0) otherwise.
bool hasEdge(Graph* G,int v1, int v2);

//Creates a directed edge from src to dst
void addDirectedEdge(Graph* G, int src, int dst);

//Creates a undirected edge between v1 and v2
void addUndirectedEdge(Graph * G, int v1, int v2);

//Creates undirected edges between Nodes in G based on sparsity. Sparsity = 0 = No edges, Sparsity = 1 = Fully connected
void createRandomUndirectedEdges(Graph* G, double sparsity);

/* UTILITY FUNCTIONS*/

//Createas a Graph with n vertices and returns it. Initilizes the Graph.
Graph* createGraph(int n);

//Prints the graph
void printGraph(Graph* G);

//Returns true (1) if G is connected, otherwise false (0)
bool isConnected(Graph* G);
