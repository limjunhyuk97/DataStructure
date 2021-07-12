#ifndef __AL_GRAPH_DFS_H__
#define __AL_GRAPH_DFS_H__

#include "DLinkedList.h"
#include "ArrayBaseStack.h"

// enum�� ���
enum { A, B, C, D, E, F, G, H, I, J };

// Undirected graph based on Adjacent List. 
typedef struct _ual {
	int numV;
	int numE;
	List* adjList;

	// �湮 ���θ� ������Ͽ� ��ƹ��ȴ�.
	int* visitInfo;

}ALGraph;

// Graph �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv);

// Graph ���ҽ� ����
void GraphDestroy(ALGraph* pg);

// ������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV);

// ������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg);

// DFS ����� ������ ���. (�������� ����)
void DFSShowGraphVertex(ALGraph* pg, int startV);

#endif