#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "LinkedList.h"

typedef struct Graph {
	char data;
	LL* list;
}Graph;

void GraphInit(Graph* graph, char data, int args, ...);

#endif