#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "Declaration.h"
#include "PriorityQueue.h"

typedef struct Graph {
	int numV;
	int numE;
	int vP;
	PQ eArr;
}Graph;

typedef struct MST {
	int numV;
	int numE;
	int vArr[MAX_LEN];
	edge* mstEdge;
	int flag;
}MST;

void GraphInit(Graph* graph, int numV, int numE);

void MakeEdge(Graph* graph, int v1, int v2, int cost);

void MakeMST(Graph* graph, MST *mst);

void PrintMSTEdge(MST* mst);

#endif
