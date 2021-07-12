#include "ALGraphBFS.h"

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
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
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

// BFS 기반의 정점들 출력. (시작점에 따라서) : queue와 array를 이용한다
void BFSShowGraphVertex(ALGraph* pg, int startV) {
	
	Queue queue;

	int visitV = startV;
	int nextV;

	QueueInit(&queue);
	VisitVertex(pg, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV)) {

		if (VisitVertex(pg, nextV) == TRUE)
			Enqueue(&queue, nextV);

		while (LNext(&(pg->adjList[visitV]), &nextV)) {
			if (VisitVertex(pg, nextV) == TRUE)
				Enqueue(&queue, nextV);
		}

		if (QIsEmpty(&queue) == TRUE)
			break;
		else {
			visitV = Dequeue(&queue);
		}

	}

	// 나아-중에 다시 쓸 때를 위한 memset
	memset(pg->visitInfo, 0, (sizeof(int)) * (pg->numV));

}
