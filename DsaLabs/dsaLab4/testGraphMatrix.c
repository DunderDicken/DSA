
/*INCLUDE MY FILES*/
#include "testGraphMatrix.h"
#define NUM_OF_VERTICES 3
 
void testGraphMatrix() {

	/* Test for undirected graph */
	printf("////////////////////////////////////////////////////// \n");
	printf("TEST FOR UNDIRECTED GRAPH: \n");
	printf("////////////////////////////////////////////////////// \n");

	Graph* UD = createGraph(NUM_OF_VERTICES);
	
	//Print empty graph
	printGraph(UD);

	//Test that functions return correct known values

	if (*getNumVertices(UD) != NUM_OF_VERTICES)
	{
		printf("ERROR! Wrong number of nodes in Undirected Graph: %d , should be: %d \n", *getNumVertices(UD),NUM_OF_VERTICES);
	}
	else
		printf("Number of nodes in Undirected Graph: %d \n", *getNumVertices(UD));

	if (*getNumEdges(UD) != 0 )
	{
		printf("ERROR! Wrong number of edges in Undirected Graph: %d , should be: 0 \n", *getNumVertices(UD));
	}
	else
		printf("Number of edges in G: %d \n", *getNumEdges(UD));

	if (hasEdge(UD, 1, 2) != 0)
	{
		printf("ERROR! hasEgde(1,2) returned TRUE , should be FALSE \n");
	}else
		printf("hasEdge(1,2) returns: %d \n", hasEdge(UD, 1, 2));

	/* Adding som undirected egdes */
	addUndirectedEdge(UD, 1, 2);
	addUndirectedEdge(UD, 1, NUM_OF_VERTICES);
	addUndirectedEdge(UD, NUM_OF_VERTICES, 2);

	//Print graph
	printGraph(UD);

	//Test that functions return correct known values
	if (*getNumVertices(UD) != NUM_OF_VERTICES)
	{
		printf("ERROR! Wrong number of nodes in Undirected Graph: %d , should be %d \n", *getNumVertices(UD), NUM_OF_VERTICES);
	}
	else
		printf("Number of nodes in Undirected Graph: %d \n", *getNumVertices(UD));

	if (*getNumEdges(UD) != 3)
	{
		printf("ERROR! Wrong number of edges in Undirected Graph: %d , should be: 3 \n", *getNumVertices(UD));
	}
	else
		printf("Number of edges in G: %d \n", *getNumEdges(UD));

	if (hasEdge(UD, 1, 2) != true)
	{
		printf("ERROR!hasEgde(1,2) returned FALSE , should be TRUE\n");
	}
	else
		printf("hasEdge(1,2) returns: %d \n", hasEdge(UD, 1, 2));


	/* Checking neighbours */
	printf("All neghbours for: \n");
	for (int i = 1; i <= UD->NumOfNodes; i++)
	{
		printf("%d:", i );
		print_list(getNeighbors(UD, i));
	}
	printf("\n\n");



	/* Test for directed graph */
	printf("////////////////////////////////////////////////////// \n");
	printf("TEST FOR DIRECTED GRAPH: \n");
	printf("////////////////////////////////////////////////////// \n");

	Graph* DG = createGraph(NUM_OF_VERTICES);

	//Print empty graph
	printGraph(DG);

	/* Adding som undirected egdes */
	addDirectedEdge(DG, 1, 2);
	addDirectedEdge(DG, 1, NUM_OF_VERTICES);
	addDirectedEdge(DG, NUM_OF_VERTICES,1);

	printf("Added edges from: \n");
	printf("1 -> 2 \n");
	printf("1 -> %d \n", NUM_OF_VERTICES);
	printf("%d -> 1 \n", NUM_OF_VERTICES);

	//Print graph after adding som directed edges
	printGraph(DG);

	if (*getNumVertices(DG) != NUM_OF_VERTICES)
	{
		printf("ERROR! Wrong number of nodes in directed Graph: %d , should be %d \n", *getNumVertices(DG), NUM_OF_VERTICES);
	}
	else
		printf("Number of nodes in directed Graph: %d \n", *getNumVertices(DG));

	if (*getNumEdges(DG) != 3)
	{
		printf("ERROR! Wrong number of edges in directed Graph: %d , should be 3 \n", *getNumVertices(DG));
	}
	else
		printf("Number of edges in directed Graph: %d \n", *getNumEdges(DG));

	
	/* Checking neighbours */
	printf("All neghbours for: \n");
	for (int i = 1; i <= DG->NumOfNodes; i++)
	{
		printf("%d:", i);
		print_list(getNeighbors(DG, i));
	}
	printf("\n\n");

	printf("IN-neghbours for: \n");
	for (int i = 1; i <= DG->NumOfNodes; i++)
	{
		printf("%d:", i);
		print_list(getInNeighbors(DG, i));
	}
	printf("\n\n");

	printf("OUT-neghbours for: \n");
	for (int i = 1; i <= DG->NumOfNodes; i++)
	{
		printf("%d:", i);
		print_list(getOutNeighbors(DG, i));
	}
	printf("\n\n");


	printf("////////////////////////////////////////////////////// \n");
	printf("END OF TEST FOR EXCERSIE 1\n");
	printf("////////////////////////////////////////////////////// \n");
}

void testGraphConnectivity()
{
	/* Test for graph connectivity */
	printf("////////////////////////////////////////////////////// \n");
	printf("TEST FOR GRAPH CONNECTIVITY: \n");
	printf("////////////////////////////////////////////////////// \n");

	Graph* G = createGraph(NUM_OF_VERTICES);
	
	printf("Number of nodes in  Graph: %d \n", *getNumVertices(G));
	printf("Number of edges in  Graph before: %d \n", *getNumEdges(G));

	double sparsity = 1;
	createRandomUndirectedEdges(G, sparsity);
	
	printGraph(G);

	printf("Number of edges in Graph after: %d \n", *getNumEdges(G));
	printf("isConnected returned: %d \n", isConnected(G));

	printf("////////////////////////////////////////////////////// \n");
	printf("END OF TEST FOR GRAPH CONNECTIVITY: \n");
	printf("////////////////////////////////////////////////////// \n");
		
}

void testDFS()
{
	/* Test for DFS */
	printf("////////////////////////////////////////////////////// \n");
	printf("TEST FOR DFS: \n");
	printf("////////////////////////////////////////////////////// \n");
	Graph* G = createGraph(3);
	printGraph(G);

	printf("Add edges: \n 1->2 \n 2->3 \n");

	addDirectedEdge(G, 1, 2);
	addDirectedEdge(G, 2, 3);
	printGraph(G);

	DFS(G);

	printf("DFS Gives: \n");

	printGraphTimes(G);

	printf("////////////////////////////////////////////////////// \n");
	printf("END OF TEST FOR DFS: \n");
	printf("////////////////////////////////////////////////////// \n");
}

void testAddEdgeCost()
{
	Graph* G = createGraph(NUM_OF_VERTICES);

	/*printf("Add edges: \n 1->2 \n 1-> 3 \n");

	addDirectedEdge(G, 1, 2);
	addDirectedEdge(G, 1, 3);*/

	double sparsity = 1;
	createRandomUndirectedEdges(G, sparsity);
	printGraph(G);

	printf("Add edge cost from 1->2 between 1 and 10.\n");
	createDirectedEdgeRandomCost(G, 1, 2, 1, 10);
	printGraph(G);

	List* shortest = dijkstra(G, 0);
	print_list(shortest);
	
}

void test()
{
	printf("THIS IS TEST! \n\n");

	Graph* G = createGraph(5);

	for (int i = 0; i < G->NumOfNodes; i++)
	{
		printf("%d \n", G->matrix[i]->key);
	}

}
