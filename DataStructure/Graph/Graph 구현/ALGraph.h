#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "DLinkedList.h"

// enum�� ���
enum {A, B, C, D, E, F, G, H, I, J};

// Undirected graph based on Adjacent List. 
typedef struct _ual {
	int numV;
	int numE;
	List* adjList;
}ALGraph;

// Graph �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv);

// Graph ���ҽ� ����
void GraphDestroy(ALGraph* pg);

// ������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV);

// ������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

#endif