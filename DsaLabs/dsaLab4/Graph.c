#include "Graph.h"

int * getNumVertices(Graph * G)
{
	int* numOfVertices = malloc(sizeof(int));
	*numOfVertices = G->NumOfNodes;

	return numOfVertices;
}

int* getNumEdges(Graph * G)
{
	int* edges = malloc(sizeof(int));;
	*edges = 0;


	for (int i = 0; i < G->NumOfNodes; ++i)
	{
		for (int j = 0; j < G->NumOfNodes; j++)
		{
			if (G->matrix[i][j].data != 0)
			{
				*edges = *edges + 1;
			}
		}

	}

	if (G->isDirected)
	{
		return edges;
	}

	//For undirected graph, the number of edges is half of the sum of all edges.
	*edges = *edges / 2;
	return edges;

}

List * getNeighbors(Graph * G, int v)
{
	v = v - 1;
	List* neighbors = createList();


	//OutNeighbors
	for (int i = 0; i < G->NumOfNodes; ++i)
	{
		if (G->matrix[i][v].data != 0)
		{
			int currentKey = i + 1;

			insert(neighbors, newListElementWithKey(currentKey));

		}
	}

	//for undirected graphs IN and OUT-neighbours are the same so we return
	if (G->isDirected == false)
	{
		return neighbors;
	}

	//InNeighbors
	for (int i = 0; i < G->NumOfNodes; ++i)
	{
		if (G->matrix[v][i].data != 0)
		{
			int currentKey = i + 1;

			//Check if key is already in list to avoid duplicates
			ListElement* lstEl = listSearch(neighbors, currentKey);

			if (lstEl->key != currentKey)
			{
				insert(neighbors, newListElementWithKey(currentKey));
			}
		}

	}

	return neighbors;
}

List * getInNeighbors(Graph * G, int v)
{
	v = v - 1;

	List* neighbors = createList();


	for (int i = 0; i < G->NumOfNodes; ++i)
	{

		if (G->matrix[i][v].data != 0)
		{
			insert(neighbors, newListElementWithKey(i + 1));
		}


	}

	return neighbors;
}

List * getOutNeighbors(Graph * G, int v)
{
	v = v - 1;

	List* neighbors = createList();


	for (int i = 0; i < G->NumOfNodes; ++i)
	{

		if (G->matrix[v][i].data != 0)
		{
			insert(neighbors, newListElementWithKey(i + 1));
		}

	}

	return neighbors;
}

bool hasEdge(Graph* G, int v1, int v2)
{
	if (G->matrix[v1 - 1][v2 - 1].data != 0)
	{
		return true;
	}
	return false;
}

void addDirectedEdge(Graph * G, int src, int dst)
{
	//Remove one from source and destination
	src = src - 1;
	dst = dst - 1;

	G->matrix[src][dst].data = true;

	G->isDirected = true;
}

void addUndirectedEdge(Graph * G, int v1, int v2)
{
	//Remove one from v1 and v2
	v1 = v1 - 1;
	v2 = v2 - 1;

	G->matrix[v1][v2].data = true;
	G->matrix[v2][v1].data = true;

	G->isDirected = false;
}

void createRandomUndirectedEdges(Graph* G, double sparsity)
{
	//Get random number
	time_t t;
	srand((unsigned)time(&t));

	int percentage = sparsity * 100; //Change sparsity to percentage

	//Go through and add edges on random based on sparsity
	for (int i = 0; i < G->NumOfNodes; i++)
	{
		for (int j = 0; j < G->NumOfNodes; j++)
		{
			int random = (rand() % 100 + 1);
			if (random < percentage && i != j ) // Nodes does not have an edge to themselves
			{
				if (!hasEdge(G,i+1,j+1)) //Check if edge already exists
				{
					addUndirectedEdge(G, i + 1, j + 1);
				}
				
			}
		}
	}

}

Graph * createGraph(int n)
{
	Graph* tmp = (Graph*)malloc(sizeof(Graph));
	tmp->NumOfNodes = n;
	tmp->isDirected = false;

	int rows = n;
	int columns = n;
	int initialEdges = 0;

	tmp->matrix = (Node**)malloc(rows * sizeof(Node*));

	for (int i = 0; i < rows; i++)
	{
		tmp->matrix[i] = (Node*)malloc(columns * sizeof(Node));

	}

	//initialize Graph
	for (int i = 0; i < rows; ++i)
	{

		for (int j = 0; j < columns; j++)
		{
			tmp->matrix[i][j].data = initialEdges;

		}

	}
	return tmp;
}

void printGraph(Graph* G)
{
	printf("    ");
	for (int i = 0; i < G->NumOfNodes; i++) {
		printf("%d ", i + 1);
	}
	printf("\n   ");

	for (int i = 0; i < G->NumOfNodes; i++) {
		printf("--");
	}
	printf("\n");
	for (int i = 0; i < G->NumOfNodes; i++)
	{
		if (i < 9) {
			printf(" %d| ", i + 1);
		}
		else {
			printf("%d| ", i + 1);
		}

		for (int j = 0; j < G->NumOfNodes; j++)
		{
			printf("%d ", G->matrix[i][j].data);
		}
		printf("\n");
	}
	printf("\n");
}

bool isConnected(Graph * G)
{
	int v = G->NumOfNodes;
	int e = *getNumEdges(G);
	int connected = (v*(v - 1)) / 2;

	if (e == connected)
	{
		return true;
	}
	return false;
}


