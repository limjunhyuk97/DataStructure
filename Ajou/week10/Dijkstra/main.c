#include "graph.h"

Graph graph;
SPath spath;

int main(void) {

	GraphInit(&graph, 10, 7);

	AddEdge(&graph, A, B, 3);
	AddEdge(&graph, A, F, 2);
	AddEdge(&graph, F, E, 2);
	AddEdge(&graph, E, D, 11);
	AddEdge(&graph, E, G, 10);
	AddEdge(&graph, D, G, 4);
	AddEdge(&graph, D, C, 8);
	AddEdge(&graph, C, G, 18);
	AddEdge(&graph, B, D, 16);
	AddEdge(&graph, B, C, 17);

	FindSPath(&spath, &graph);
	
	return 0;
}
