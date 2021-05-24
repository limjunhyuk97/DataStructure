#include "graph.h"

Graph graph;

int main(void) {

	initGraph(&graph, 8);

	addEdge(&graph, 0, 1);
	addEdge(&graph, 1, 2);
	addEdge(&graph, 1, 3);
	addEdge(&graph, 1, 4);
	addEdge(&graph, 2, 7);
	addEdge(&graph, 3, 6);
	addEdge(&graph, 4, 6);
	addEdge(&graph, 4, 5);
	addEdge(&graph, 6, 7);
	addEdge(&graph, 5, 7);

	topSort(&graph);

	return 0;
}