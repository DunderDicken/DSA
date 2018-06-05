
#include "Graph.h"

Graph * createGraph(int n)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->numVertices = n;

	graph->array = (AdjList*) malloc(n * sizeof(AdjList));

	for (int i = 0; i < n; i++)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}
