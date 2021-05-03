#ifndef __AL_GRAPH_DFS_H__
#define __AL_GRAPH_DFS_H__

#include "DLinkedList.h"
#include "CircularQueue.h"

// enum의 사용
enum { A, B, C, D, E, F, G, H, I, J };

// Undirected graph based on Adjacent List. 
typedef struct _ual {
	int numV;
	int numE;
	List* adjList;

	// 방문 여부를 헤더파일에 담아버렸다.
	int* visitInfo;

}ALGraph;

// Graph 초기화
void GraphInit(ALGraph* pg, int nv);

// Graph 리소스 해제
void GraphDestroy(ALGraph* pg);

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

// BFS 기반의 정점들 출력. (시작점에 따라서)
void BFSShowGraphVertex(ALGraph* pg, int startV);

#endif
