#include "Graph.h"

#define WHITE 1
#define GRAY 2
#define BLACK 3

int getNumVertices(Graph * G)
{
	return G->size;
}

int getNumEdges(Graph * G)
{
	int* edges = malloc(sizeof(int));;
	*edges = 0;


	for (int i = 0; i < G->size; ++i)
	{
		for (int j = 0; j < G->size; j++)
		{
			if (G->matrix[i][j].data != 0)
			{
				*edges = *edges + 1;
			}
		}

	}

	if (G->isDirected)
	{
		return *edges;
	}

	//For undirected graph, the number of edges is half of the sum of all edges.
	*edges = *edges / 2;
	return *edges;

}

List * getNeighbors(Graph * G, int v)
{
	List* neighbors = createList();

	//OutNeighbors - Checks all edges from 'v'
	for (int i = 0; i < G->size; ++i)
	{
		if (G->matrix[v][i].data != 0)
		{
			int currentKey = i;
			insert(neighbors, newListElementWithKey(currentKey));
		}
	}

	//for undirected graphs IN and OUT-neighbours are the same so we return
	if (G->isDirected == false)
		return neighbors;


	//InNeighbors - Checks all Nodes in G if they have a edge to 'v'
	for (int i = 0; i < G->size; ++i)
	{
		if (G->matrix[i][v].data != 0)
		{
			int currentKey = i;

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
	List* neighbors = createList();

	//InNeighbors - Checks all Nodes in G if they have a edge to 'v'
	for (int i = 0; i < G->size; ++i)
	{
		if (G->matrix[i][v].data != 0)
		{
			int currentKey = i;

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

List * getOutNeighbors(Graph * G, int v)
{
	List* neighbors = createList();

	//OutNeighbors - Checks all edges from 'v'
	for (int i = 0; i < G->size; ++i)
	{
		if (G->matrix[v][i].data != 0)
		{
			int currentKey = i;
			insert(neighbors, newListElementWithKey(currentKey));
		}
	}

	return neighbors;
}

bool hasEdge(Graph* G, int v1, int v2)
{
	if (G->matrix[v1][v2].data != 0)
	{
		return true;
	}
	if (G->matrix[v2][v1].data != 0)
	{
		return true;
	}
	return false;
}

void addDirectedEdge(Graph * G, int src, int dst)
{
	G->matrix[src][dst].data = 1;
	G->matrix[src][dst].num = dst;
	G->isDirected = true;
}

void addUndirectedEdge(Graph * G, int v1, int v2)
{
	G->matrix[v1][v2].data = true;
	G->matrix[v2][v1].data = true;

	G->matrix[v1][v2].num = v2;
	G->matrix[v2][v1].num = v1;

	G->isDirected = false;
}

void createRandomUndirectedEdges(Graph* G, double sparsity)
{
	//Get random number
	time_t t;
	srand((unsigned)time(&t));

	int percentage = sparsity * 100; //Change sparsity to percentage

	//Go through and add edges on random based on sparsity
	for (int i = 0; i < G->size; i++)
	{
		for (int j = 0; j < G->size; j++)
		{
			int random = (rand() % 100 + 1);
			if (random < percentage && i != j) // Nodes does not have an edge to themselves
			{
				if (!hasEdge(G, i, j)) //Check if edge already exists
				{
					addUndirectedEdge(G, i, j);
				}

			}
		}
	}

}


void createDirectedEdgeRandomCost(Graph* G, int src, int dst, int edgeCostLowerBound, int edgeCostUpperBound)
{
	//Get random number
	srand((unsigned)time(NULL));
	int w = ((rand() % (edgeCostUpperBound - edgeCostLowerBound + 1) + edgeCostLowerBound));

	//Add edge
	addDirectedEdge(G, src, dst);
	//Add weight to that edge
	G->matrix[src][dst].data = w;
}

List* dijkstra(Graph* G, int weight, int src)
{
	int u;
	initialize_single_sort(G, src);
	
	List* S = createList(); //Creates empty list to store shortest path in.
	List* Q = createList(); //Create list to store vertices in
	for (int i = 0; i < G->size; i++)
	{
		insert(Q, newListElementWithKey(i)); //Stores number of edges in list to keep track of visited
	}

	print_list(Q);

	while (isListEmpty(Q) == 0) //While Q is not empty, not all edges is visited.
	{
		u = extract_min(G, Q);
		insert(S, newListElementWithKey(u));

		for (int i = 0; i < G->size; i++)
		{
			if (hasEdge(G,u,i) != 0) //Adj[u], if there is a edge from u->i
			{
				relax(G, u, i, G->matrix[u][i].data);
			}
		}
	}

	return S;
}

Graph * createGraph(int n)
{
	Graph* tmp = (Graph*)malloc(sizeof(Graph));
	tmp->size = n;
	tmp->isDirected = false;

	int rows = n;
	int columns = n;
	int initialEdges = 0;

	tmp->matrix = (Node**)malloc(rows * sizeof(Node*));

	for (int i = 0; i < rows; i++)
	{
		tmp->matrix[i] = (Node*)malloc(columns * sizeof(Node));
		tmp->matrix[i]->num = i;
	}

	//initialize Graph with zeros
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; j++)
		{
			tmp->matrix[i][j].data = initialEdges;
		}
	}


	return tmp;
}

bool isConnected(Graph * G)
{
	int v = G->size;
	int e = getNumEdges(G);
	int connected = (v*(v - 1)) / 2;

	if (e == connected)
	{
		return true;
	}
	return false;
}


List*  DFS(Graph * G)
{
	//List to hold topological sort
	List* topological = createList();

	//Mark every node as WHITE (1) and set the predecessor to NULL
	for (int i = 0; i < G->size; i++)
	{
		G->matrix[i]->color = WHITE;
		G->matrix[i]->predecessor = 99999999; //This represent infinity (NIL)
	}

	//Set time marker to 0
	G->time = 0;

	//DFS-vist-loop
	for (int i = 0; i < G->size; i++)
	{
		if (G->matrix[i]->color == WHITE)
		{
			DFS_VISIT(G, i, topological);
		}
	}

	return topological;
}

void  DFS_VISIT(Graph * G, int u, List* topological)
{
	G->time = G->time + 1;
	G->matrix[u]->discoveryTime = G->time;
	G->matrix[u]->color = GRAY;

	for (int i = 0; i < G->size; i++)
	{
		if (G->matrix[u][i].data != 0) //IF there is an edge
		{
			if (G->matrix[i]->color == WHITE) // And the node is WHITE
			{
				G->matrix[i]->predecessor = u;
				DFS_VISIT(G, i, topological);
			}
		}
	}

	G->matrix[u]->color = BLACK;
	G->time = G->time + 1;
	G->matrix[u]->finishTime = G->time;

	insert(topological, newListElementWithKey(u));

}

void relax(Graph* G, int src, int dst, int weight)
{
	if (G->matrix[dst]->d > (G->matrix[src]->d + weight))
	{
		G->matrix[dst]->d = (G->matrix[src]->d + weight);
		G->matrix[dst]->predecessor = src;
	}
}

void initialize_single_sort(Graph * G, int src)
{
	for (int i = 0; i < G->size; i++)
	{
		G->matrix[i]->d = 999999;			//This represent infinity (NIL);
		G->matrix[i]->predecessor = 999999; //This represent infinity (NIL);
	}

	G->matrix[src]->d = 0;
}

int extract_min(Graph* G, List* L)
{

	ListElement* curr = newListElement();
	curr = L->nil->next;
	printf("Curr.key: %d \n", curr->key);

	int minimum = G->matrix[curr->key]->d;
	int count = 0;

	while (curr != L->nil)
	{
		if (minimum > G->matrix[curr->key]->d)
		{
			minimum = G->matrix[curr->key]->d;
			count = curr->key;
		}
		curr = curr->next;
	}
	

	deleteElement(L, listSearch(L, count));
	return count;
}

List * shortestPath(Graph * G, int src, int dst)
{
	List* shortest = createList();
	insert(shortest, newListElementWithKey(dst));

	//Do the Dijkstra
	dijkstra(G, 0, src);
	printf("Pre of 33: %d\n", G->matrix[33]->predecessor);
	printf("Pre of 34: %d\n", G->matrix[34]->predecessor);
	printf("Pre of 35: %d\n", G->matrix[35]->predecessor);
	printf("Pre of 36: %d\n", G->matrix[36]->predecessor);
	printf("Pre of 25: %d\n", G->matrix[25]->predecessor);
	printf("Pre of 45: %d\n", G->matrix[45]->predecessor);
	printf("Pre of 55: %d\n", G->matrix[55]->predecessor);
	printf("Pre of 15: %d\n", G->matrix[15]->predecessor);
	printf("Pre of 39: %d\n", G->matrix[39]->predecessor);
	printf("Pre of 49: %d\n", G->matrix[49]->predecessor);
	printf("Pre of 59: %d\n", G->matrix[59]->predecessor);
	printf("Pre of 64: %d\n", G->matrix[64]->predecessor);
	

	//start at destination
	int pre = G->matrix[dst]->predecessor;

	while (pre != src)
	{
		insert(shortest, newListElementWithKey(pre));
		printf("pre: %d \n",pre);
		pre = G->matrix[pre]->predecessor;
	}

	insert(shortest, newListElementWithKey(src));
	return shortest;
}




