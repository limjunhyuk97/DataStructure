#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "linkedList.h"
#include "stack.h"

#define PRINTINTROMSG "Topological sort의 결과\n\n"
#define PRINTCYCLEMSG "\nNetwork has a cycle.\n"
#define PRINTVERTEXMSG "Vertex %d"

typedef struct Graph {
	int numV;
	int numE;
	int* predecessor;			// 선행자 개수
	LL* adjacencyList;			// 인접 리스트
}Graph;

void initGraph(Graph* graph, int v);

void addEdge(Graph* graph, int v1, int v2);

int topSort(Graph* graph);

#endif