#include "Tests.h"

void test() {

	Graph* G = createGraph(5);



}

void EX1()
{
	/* Test for directed graph */
	printf("////////////////////////////////////////////////////// \n");
	printf("TEST FOR DIRECTED GRAPH: \n");

	int vertices = 5;
	Graph* Gd = createGraph(vertices);

	if (getNumVertices(Gd) == vertices) {
		printf("Number of vertices in G: %d \n", getNumVertices(Gd));
	}
	else
		printf("getNumVertices(G) returned wrong number");

	if (getNumEdges(Gd) != 0)
	{
		printf("ERROR! Wrong number of edges in Undirected Graph: %d , should be: 0 \n", getNumVertices(Gd));
	}
	else
		printf("Number of edges in G: %d \n", getNumEdges(Gd));


	addDirectedEdge(Gd, 0, 1);
	addDirectedEdge(Gd, 3, 1);
	addDirectedEdge(Gd, 4, 2);

	printf("Added directed edges: \n");
	printf("0->1  \n");
	printf("3->1  \n");
	printf("4->2  \n");

	if (getNumEdges(Gd) != 3)
	{
		printf("ERROR! Wrong number of edges in Undirected Graph: %d , should be: 0 \n", getNumVertices(Gd));
	}
	else
		printf("Number of edges in G: %d \n", getNumEdges(Gd));

	if (hasEdge(Gd, 0, 1) && hasEdge(Gd, 3, 1) && hasEdge(Gd, 2, 4) && !hasEdge(Gd, 3, 4))
	{
		printf("Has edge returned correct values: \n");
		printf("0->1 :%d \n", hasEdge(Gd, 0, 1));
		printf("3->1 :%d \n", hasEdge(Gd, 3, 1));
		printf("4->2 :%d \n", hasEdge(Gd, 2, 4));
		printf("3->4 :%d \n", hasEdge(Gd, 3, 4));
	}
	else
		printf("Has edge returned WRONG values \n");

	printf("IN-Neighbours: \n");
	for (int i = 0; i < Gd->size; i++)
	{
		printf("%d:", i);
		print_list(getInNeighbors(Gd, i));
	}


	printf("OUT-Neighbours: \n");
	for (int i = 0; i < Gd->size; i++)
	{
		printf("%d:", i);
		print_list(getOutNeighbors(Gd, i));
	}

	printf("Neighbours: \n");
	for (int i = 0; i < Gd->size; i++)
	{
		printf("%d:", i);
		print_list(getNeighbors(Gd, i));
	}


	printf("////////////////////////////////////////////////////// \n\n");
}

void EX2()
{
	/* Test for graph connectivity */
	printf("////////////////////////////////////////////////////// \n");
	printf("TEST FOR GRAPH CONNECTIVITY: \n");

	int vertices = 5;
	Graph* G1 = createGraph(vertices);
	Graph* G2 = createGraph(vertices);
	Graph* G3 = createGraph(vertices);

	printf("Number of nodes in  Graph: %d \n", getNumVertices(G1));
	printf("Number of edges in  Graph before: %d \n", getNumEdges(G1));

	double sparsity = 1;
	createRandomUndirectedEdges(G1, sparsity);
	printf("Number of edges in Graph after: %d \n", getNumEdges(G1));

	if (isConnected(G1)) {
		printf("isConnected returned correct value: %d \n\n", isConnected(G1));
	}
	else
		printf("isConnected returned wrong value \n\n");

	sparsity = 0;
	createRandomUndirectedEdges(G2, sparsity);
	printf("Number of edges in Graph G2 after: %d \n", getNumEdges(G2));

	if (getNumEdges(G2) == 0) {
		printf("CORRECT! Graph G2 has 0 egdes\n\n");
	}
	else
		printf("ERROR! G2 has more than 0 edges.\n\n");

	sparsity = 0.5;
	createRandomUndirectedEdges(G3, sparsity);
	printf("Number of edges in Graph G3 after: %d \n\n", getNumEdges(G3));

	if (getNumEdges(G3) > 0 && getNumEdges(G3) < 10) {
		printf("CORRECT! Graph G3 has >0  and <10 egdes\n\n");
	}
	else
		printf("ERROR! G3 wrong number of edges.\n\n");

	printf("////////////////////////////////////////////////////// \n\n");
}

void EX4()
{
	/* Test for Activity manager */
	printf("////////////////////////////////////////////////////// \n");
	printf(" Test for Activity manager: \n");

	int vertices = 9;
	Graph* G1 = createGraph(vertices);

	//This is the Graph from the lab
	addDirectedEdge(G1, 0, 1); //1
	addDirectedEdge(G1, 0, 6); //2
	addDirectedEdge(G1, 1, 6); //3
	addDirectedEdge(G1, 1, 2); //4
	addDirectedEdge(G1, 2, 3); //5
	addDirectedEdge(G1, 7, 6); //6
	addDirectedEdge(G1, 4, 2); //7
	addDirectedEdge(G1, 4, 5); //8
	addDirectedEdge(G1, 5, 3); //9


	printf("Number of nodes in  Graph: %d \n", getNumVertices(G1));
	printf("Number of edges in  Graph: %d \n", getNumEdges(G1));

	printf("Topological order of graph: \n");
	List* topOrder = DFS(G1);
	print_list(topOrder);

	printf("Node, Discoverytime, Finishingtime, Predecessor (99999 = no predecessor) \n");
	for (int i = 0; i < G1->size; i++)
	{
		printf("%d: dT: %d fT: %d pre: %d  \n", i, G1->matrix[i]->discoveryTime, G1->matrix[i]->finishTime, G1->matrix[i]->predecessor);
	}


	printf("////////////////////////////////////////////////////// \n\n");
}

void EX5()
{
	/* Test for Shortest Path*/
	printf("////////////////////////////////////////////////////// \n");
	printf(" Test for Shortest Path: \n");


	int vertices = 3;
	Graph* G1 = createGraph(vertices);

	int lower = 1;
	int upper = 10;
	createDirectedEdgeRandomCost(G1, 0, 2, lower, upper);
	int cost = G1->matrix[0][2].data;

	if (getNumEdges(G1) == 1 && cost <= upper && cost >= lower)
	{
		printf("CORRECT! Cost of edge 0-> 2: %d \n", G1->matrix[0][2].data);
		printf("Number of edges in  Graph: %d \n", getNumEdges(G1));
	}
	else
		printf("Number of edges in  Graph: \n");


	/* Test for Dijkstra*/
	printf("////////////////////////////////////////////////////// \n");
	printf(" Test Dijkstra: \n");

	vertices = 4;
	Graph* G2 = createGraph(vertices);

	lower = 1;
	upper = 10;
	createDirectedEdgeRandomCost(G2, 0, 1, lower, upper);
	createDirectedEdgeRandomCost(G2, 1, 2, lower, upper);
	createDirectedEdgeRandomCost(G2, 2, 3, lower, upper);


	dijkstra(G2, 0, 0);

	printf("Node: cost, Predecessor (99999 = no predecessor) \n");
	for (int i = 0; i < G2->size; i++)
	{
		printf("%d: cost: %d pre: %d  \n", i, G2->matrix[i]->d, G2->matrix[i]->predecessor);
	}
	int pre1 = G2->matrix[1]->predecessor;
	int pre2 = G2->matrix[2]->predecessor;
	int pre3 = G2->matrix[3]->predecessor;

	if (pre3 == 2 && pre2 == 1 && pre1 == 0)
	{
		printf("Correct! Dijkstra's worked! \n");
	}
	else
		printf("ERROR! Dijkstra's did not work. \n");
	printf("////////////////////////////////////////////////////// \n\n");

	/* Test for Shortest path problem*/
	printf("////////////////////////////////////////////////////// \n");
	printf(" Test for Shortest path problem: \n");

	vertices = 100;
	Graph* G3 = createGraph(vertices);
	lower = 1;
	upper = 10;
	
	//Add all edges for map
	for (int i = 0; i < G3->size; i++)
	{
		//Add edges to closest nodes
		if (((i + 1) % 10) != 0 && i != 99)
		{
			createDirectedEdgeRandomCost(G3, i, i + 1, lower, upper);
			createDirectedEdgeRandomCost(G3, i + 1, i, lower, upper);
		}

		//Add edges to upper and lower edges
		if (i + 10 < G3->size)
		{
			createDirectedEdgeRandomCost(G3, i, i + 10, lower, upper);
			createDirectedEdgeRandomCost(G3, i + 10, i, lower, upper);
		}

	}

	//Remove unwanted nodes
	List* unwantedNodes = createList();
	createUnwantedList(unwantedNodes);

	ListElement* tmp = unwantedNodes->nil->next;
	while (tmp != unwantedNodes->nil)
	{
		removeUnwanted(G3, tmp->key);
		tmp = tmp->next;
	}

	printf("edge from 25-> 35: %d \n", hasEdge(G3,25,35));
	printf("edge from 45-> 35: %d \n", hasEdge(G3, 45, 35));
	printf("edge from 34-> 35: %d \n", hasEdge(G3, 34, 35));
	printf("edge from 36-> 35: %d \n", hasEdge(G3, 36, 35));

	printf("edge from 37, 36): %d \n", hasEdge(G3, 37, 36));
	printf("edge from  38, 37: %d \n", hasEdge(G3, 38, 37));
	printf("edge from 39, 38: %d \n", hasEdge(G3, 39, 38));
	printf("edge from  49, 39: %d \n", hasEdge(G3, 49, 39));

	printf("edge from 59, 49) %d \n", hasEdge(G3, 59, 49));
	printf("edge from  69, 59: %d \n", hasEdge(G3, 69, 59));
	printf("edge from 79, 69): %d \n", hasEdge(G3, 79, 69));
	printf("edge from 89, 79: %d \n", hasEdge(G3, 89, 79));
	printf("edge from  99, 89: %d \n", hasEdge(G3, 99, 89));

	printf("edge from 98, 99): %d \n", hasEdge(G3, 98, 99));
	printf("edge from  97, 98: %d \n", hasEdge(G3, 97, 98));
	printf("edge from 96, 97: %d \n", hasEdge(G3, 96, 97));
	printf("edge from  95, 96): %d \n", hasEdge(G3, 95, 96));
	printf("edge from 94, 95): %d \n", hasEdge(G3, 94, 95));
	printf("edge from 93, 94): %d \n", hasEdge(G3, 93, 94));
	printf("edge from 92, 93: %d \n", hasEdge(G3, 92, 93));

	printf("edge from 91, 92): %d \n", hasEdge(G3, 91, 92));
	printf("edge from 90, 91): %d \n", hasEdge(G3, 90, 91));
	printf("edge from 80, 90): %d \n", hasEdge(G3, 80, 90));
	printf("edge from  70, 80): %d \n", hasEdge(G3, 70, 80));
	printf("edge from  60, 70: %d \n", hasEdge(G3, 60, 70));
	printf("edge from 50, 60: %d \n", hasEdge(G3, 50, 60));
	printf("edge from 40, 50): %d \n", hasEdge(G3, 40, 50));

	printf("edge from 30, 40: %d \n", hasEdge(G3, 30, 40));
	printf("edge from 20, 30: %d \n", hasEdge(G3, 20, 30));
	printf("edge from 10, 20: %d \n", hasEdge(G3, 10, 20));
	printf("edge from  0, 10): %d \n", hasEdge(G3, 0, 10));


	//My interpretation is that (1,1) = vertex 0 and (6,4)= vertex 35
	List* shortestPathsList = createList();
	shortestPathsList = shortestPath(G3, 0, 56);
	print_list(shortestPathsList);

	printf("Pre of 35: %d\n", G3->matrix[35]->predecessor);
	printf("Pre of 56: %d\n", G3->matrix[56]->predecessor);


}

void createUnwantedList(List * L)
{
	insert(L, newListElementWithKey(4));
	insert(L, newListElementWithKey(14));
	insert(L, newListElementWithKey(24));
	insert(L, newListElementWithKey(34));
	insert(L, newListElementWithKey(44));
	insert(L, newListElementWithKey(54));
	insert(L, newListElementWithKey(64));
	insert(L, newListElementWithKey(74));
	insert(L, newListElementWithKey(84));

	//insert(L, newListElementWithKey(45));
	//insert(L, newListElementWithKey(46));
	//insert(L, newListElementWithKey(47));
	//insert(L, newListElementWithKey(48));

	//insert(L, newListElementWithKey(83));
	//insert(L, newListElementWithKey(82));
	//insert(L, newListElementWithKey(81));

}

void removeUnwanted(Graph* G, int target)
{
	if (target >= 10)
	{
		G->matrix[target - 10][target].data = 0;
	}
	if (target <= 90)
	{
		G->matrix[target + 10][target].data = 0;
	}
	if (target < 99)
	{
		G->matrix[target + 1][target].data = 0;
	}
	if (target > 0)
	{
		G->matrix[target - 1][target].data = 0;
	}
	

	for (int i = 0; i < G->size; i++)
	{
		G->matrix[target][i].data = 0;
	}

}
