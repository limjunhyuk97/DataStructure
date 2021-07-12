#include "ALGraphDFS.h"

// 정렬 함수
int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;
	else
		return 1;
}

// Graph 초기화
void GraphInit(ALGraph* pg, int nv) {

	pg->numE = 0;
	pg->numV = nv;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->visitInfo = (int*)malloc(sizeof(int) * nv);
	memset(pg->visitInfo, 0, sizeof(int) * nv);

	for (int i = 0; i < nv; ++i) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
		// list에 들어있는 항목들을 예쁘게 출력해줌
	}

}

// Graph 리소스 해제
void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL) {
		free(pg->adjList);
	}
	if (pg->visitInfo != NULL) {
		free(pg->visitInfo);
	}
}

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV) {
	// 양방향 연결리스트이므로, 양방향 모두에 추가해주어야 한다.
	FInsert(&(pg->adjList[fromV]), toV);
	FInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg) {

	LData tmpData;

	for (int i = 0; i < pg->numV; ++i) {
		printf("%c와 연결된 정점 : ", i + 65);
		if (LFirst(&(pg->adjList[i]), &tmpData)) {
			printf("%c ", tmpData + 65);
			while (LNext(&(pg->adjList[i]), &tmpData))
				printf("%c ", tmpData + 65);
		}
		printf("\n");
	}
}

// 정점들에 방문하는 것과 관련된 함수
int VisitVertex(ALGraph* pg, int visitV) {
	if (pg->visitInfo[visitV] == 0) {
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

// DFS 기반의 정점들 출력. (시작점에 따라서)
void DFSShowGraphVertex(ALGraph* pg, int startV) {
	
	Stack stack;

	// visitV와 nextV를 통해 접근할 것이다. 
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, startV);
	SPush(&stack, visitV);
	SPush(&stack, visitV);
	
	// adjList[]에 첫번째 목록이 존재한다면
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {

		// 방문 가능한 vertex가 없는 상태로 초기화
		int visitFlag = FALSE;

		// 방문된 적이 없는 vertice를 찾았다면
		if (VisitVertex(pg, nextV) == TRUE) {
			// 방문한 적없는 vertice 넣기
			SPush(&stack, nextV);
			// if문 탈출 후에 바깥 while문으로 나가서 해당 adjList[]로 이동
			visitV = nextV;
			visitFlag = TRUE;
		}

		// 방문된 적이 있는 vertice에 대한 방문이라면
		else {
			// 해당 adjList[] 계속 돌면서 방문된 적 없는 vertice를 찾는다.
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
				// 방문한 적 없는 vertice를 찾았다면
				if (VisitVertex(pg, nextV) == TRUE) {
					// 방문한 적없는 vertice 넣기
					SPush(&stack, nextV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		// 방문안한 vertice가 없다면
		if (visitFlag == FALSE) {
			// 스택이 비어있지 않다면
			// 다시 SPop
			if (SIsEmpty(&stack) == TRUE) {
				break;
			}
			else
				visitV = SPop(&stack);
		}

	}

	// 이후의 탐색을 위해서 메모리 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

}