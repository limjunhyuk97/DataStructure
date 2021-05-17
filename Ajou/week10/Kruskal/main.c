#include "Graph.h"

Graph graph;
MST mst;

int main(void) {
	
	GraphInit(&graph, 8, 12);
	MakeEdge(&graph, 0, 3, 6);
	MakeEdge(&graph, 0, 7, 1);
	MakeEdge(&graph, 0, 1, 10);
	MakeEdge(&graph, 7, 3, 3);
	MakeEdge(&graph, 7, 4, 8);
	MakeEdge(&graph, 7, 6, 12);
	MakeEdge(&graph, 5, 1, 2);
	MakeEdge(&graph, 5, 4, 5);
	MakeEdge(&graph, 5, 6, 9);
	MakeEdge(&graph, 5, 2, 7);
	MakeEdge(&graph, 3, 2, 11);
	MakeEdge(&graph, 1, 2, 4);

	MakeMST(&graph, &mst);

	PrintMSTEdge(&mst);

	return 0;
}
