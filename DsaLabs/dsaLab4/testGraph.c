/*INCLUDES*/
#include <stdio.h>
#include <stdlib.h>

/*INCLUDE MY FILES*/
#include "LinkedList.h"
#include "Graph.h"

#define NUM_OF_VERTICES 4

int main(int argc, char* argv[])
{
	/*
	int numOfVertices = 6;

	/*Graph* gUndirected = createGraph(numOfVertices);

	printf("Number of vertices in Undirected graph: %d \n", *getNumVertices(gUndirected));
	printf("Number of edges in Undirected graph: %d \n", *getNumEdges(gUndirected));

	printGraph(gUndirected);

	addUndirectedEdge(gUndirected, 0, 1);
	addUndirectedEdge(gUndirected, 0, 2);

	addUndirectedEdge(gUndirected, 0, 2);
	addUndirectedEdge(gUndirected, 3, 0);
	addUndirectedEdge(gUndirected, 3, 4);



	printf("After adding edges: \n");
	printGraph(gUndirected);
	printf("Number of edges in Undirected graph: %d \n", *getNumEdges(gUndirected));
	

	for (int i = 0; i < gUndirected->numVertices; i++)
	{
		List* neghbors = getNeighbors(gUndirected, i);
		printf("Print neighbors of %d: \n", i);
		print_list(neghbors);

	}
	
	List* neghbors = getNeighbors(gUndirected, 0);
	printf("Print neighbors of 0: \n");
	print_list(neghbors);

	neghbors = getNeighbors(gUndirected, );
	printf("Print neighbors of 3: \n");
	print_list(neghbors);

	neghbors = getNeighbors(gUndirected, 3);
	printf("Print neighbors of 3: \n");
	print_list(neghbors);

	neghbors = getNeighbors(gUndirected,3);
	printf("Print neighbors of 3: \n");
	print_list(neghbors); 
	*/

	Graph* directed = createGraph(NUM_OF_VERTICES);

	addUndirectedEdge(directed, 0, 1);
	
	
	

	printGraph(directed);
	
	for (int i = 0; i < directed->numVertices; i++)
	{
		List* neighbors = getNeighbors(directed, i);
		printf("Print neighbors of %d: \n", i);
		print_list(neighbors);

	}

	/*for (int i = 0; i < directed->numVertices; i++)
	{
		List* InNeighbors = getInNeighbors(directed, i);
		printf("Print InNeighbors of %d: \n", i);
		print_list(InNeighbors);

	}

	for (int i = 0; i < directed->numVertices; i++)
	{
		List* outNeighbors = getOutNeighbors(directed, i);
		printf("Print outNeighbors of %d: \n", i);
		print_list(outNeighbors);

	}*/

	getchar();
}
