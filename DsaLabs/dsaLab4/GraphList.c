
#include "GraphList.h"


int * getNumVertices(GraphList * G)
{
	int* numOfVertices = malloc(sizeof(int));
	*numOfVertices = G->numVertices;

	return numOfVertices;
}

int* getNumEdges(GraphList * G)
{
	int* numOfEdges = malloc(sizeof(int));
	*numOfEdges = G->numEdges;

	return numOfEdges;
}

List * getNeighbors(GraphList * G, int v)
{
	List* neighbors = createList();

	List* in = getInNeighbors(G, v);

	printf("In list of %d: \n",v);
	print_list(in);

	List* out = getOutNeighbors(G, v);
	printf("Out list of %d: \n",v);
	print_list(out);

	/*AdjListNode* tmp = G->array[v].head;

	while (tmp != NULL)
	{
		ListElement* listElement = newListElementWithKey(tmp->vertex);
		insert(neighbors, listElement);

		tmp = tmp->next;
	}
*/
	return neighbors;

}

List * getInNeighbors(GraphList * G, int v)
{
	List* inNeighbors = createList();

	//Go through all vertices
	for (int i = 0; i < G->numVertices; i++)
	{

		AdjListNode* tmp = G->array[i].head;

		while (tmp != NULL)
		{
			if (tmp->vertex == v)
			{
				ListElement* listElement = newListElementWithKey(i);
				insert(inNeighbors, listElement);
			}
			tmp = tmp->next;
		}

	}
	return inNeighbors;
}

List * getOutNeighbors(GraphList * G, int v)
{
	List* outNeighbors = createList();

	AdjListNode* tmp = G->array[v].head;

	while (tmp != NULL)
	{
		ListElement* listElement = newListElementWithKey(tmp->vertex);
		insert(outNeighbors, listElement);

		tmp = tmp->next;
	}

	return outNeighbors;
}

void addDirectedEdge(GraphList * G, int src, int dst)
{
	AdjListNode* newNode = newAdjListNode(dst);
	newNode->next = G->array[src].head;
	G->array[src].head = newNode;

	//Increase number of edges in GraphList
	G->numEdges++;
}

void addUndirectedEdge(GraphList * G, int v1, int v2)
{
	//Adds edge from v1 to v2
	AdjListNode* newNode = newAdjListNode(v2);
	newNode->next = G->array[v1].head;
	G->array[v1].head = newNode;

	//Add edge from v2 to v1
	newNode = newAdjListNode(v1);
	newNode->next = G->array[v2].head;
	G->array[v2].head = newNode;

	//Increase number of edges in GraphList
	G->numEdges++;
}

GraphList* createGraphList(int n)
{
	GraphList* graph = (GraphList*)malloc(sizeof(GraphList));
	graph->numVertices = n;
	graph->numEdges = 0;

	graph->array = (AdjList*)malloc(n * sizeof(AdjList));

	for (int i = 0; i < n; i++)
	{
		graph->array[i].head = NULL;
	}

	return graph;
}

AdjListNode * newAdjListNode(int v)
{
	AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
	newNode->vertex = v;
	newNode->weight = 0;
	newNode->next = NULL;

	return newNode;
}

void printGraphList(GraphList * G)
{
	printf("Adjacency list of vertex: \n");

	for (int i = 0; i < G->numVertices; i++)
	{
		AdjListNode* tmp = G->array[i].head;
		printf("%d: ", i);

		while (tmp)
		{
			printf("-> %d", tmp->vertex);
			tmp = tmp->next;
		}
		printf(" \n");
	}
}


