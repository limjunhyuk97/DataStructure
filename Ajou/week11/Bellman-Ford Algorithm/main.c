#include "graph.h"

Graph graph;

int main(void) {

	graphInit(&graph, 6, 8);

	addEdge(&graph, 0, 1, 10);
	addEdge(&graph, 0, 3, 20);
	addEdge(&graph, 3, 1, 20);
	addEdge(&graph, 1, 2, 60);
	addEdge(&graph, 3, 4, 30);
	addEdge(&graph, 2, 4, -30);
	addEdge(&graph, 2, 5, 20);
	addEdge(&graph, 4, 5, 10);

	printPath(&graph, 0);

	return 0;
}