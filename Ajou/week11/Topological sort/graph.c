#include "graph.h"

#include <stdlib.h>
#include <stdio.h>

void initGraph(Graph* graph, int v) {
	
	graph->numV = v;
	graph->numE = 0;

	graph->predecessor = (int*)malloc(sizeof(int) * (graph->numV));
	graph->adjacencyList = (LL*)malloc(sizeof(LL) * (graph->numV));
	for (int i = 0; i < graph->numV; ++i) {
		initList(&(graph->adjacencyList[i]));
		graph->predecessor[i] = 0;
	}

}

void addEdge(Graph* graph, int v1, int v2) {

	graph->numE += 1;
	graph->predecessor[v2] += 1;
	listInsert(&(graph->adjacencyList[v1]), v2);

}

int topSort(Graph* graph) {

	Stack stack;
	initStack(&stack);
	int vertex, cnt = 0, next;

	printf(PRINTINTROMSG);

	// cycle �Ÿ��� predecessor�ִ� vertex ã��.
	for (int i = 0; i < graph->numV; ++i) {
		if (graph->predecessor[i] == 0) {
			Push(&stack, i);	// stack���� predecessor ���� �ε��� ��ȣ�� ���޵�.
			break;
		}
	}

	for (int i = 0; i < graph->numV; ++i) {

		if (i != 0) printf(" ->");
		
		// cycle ������ �����Ѵ�
		if (StackIsEmpty(&stack) == TRUE) {
			printf(PRINTCYCLEMSG);
			return FALSE;
		}

		// cycle ������ 1. �����ϰ�, 2. ���� immediate successor���� count -1, 3. ���� index ã��
		else {
			Pop(&stack, &vertex);
			printf(PRINTVERTEXMSG, vertex);
			for (int i = listFirst(&(graph->adjacencyList[vertex]), &next); i == TRUE; i = listNext(&(graph->adjacencyList[vertex]), &next)) {
				graph->predecessor[next] -= 1;
				if (graph->predecessor[next] == 0) {
					Push(&stack, next);
				}
			}
		}

	}

}