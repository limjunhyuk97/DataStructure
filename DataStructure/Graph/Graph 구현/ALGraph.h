#ifndef __AL_GRAPH_H__
#define __AL_GRAPH_H__

#include "DLinkedList.h"

// enum의 사용
enum {A, B, C, D, E, F, G, H, I, J};

// Undirected graph based on Adjacent List. 
typedef struct _ual {
	int numV;
	int numE;
	List* adjList;
}ALGraph;

// Graph 초기화
void GraphInit(ALGraph* pg, int nv);

// Graph 리소스 해제
void GraphDestroy(ALGraph* pg);

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

#endif