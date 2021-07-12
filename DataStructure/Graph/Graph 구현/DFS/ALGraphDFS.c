#include "ALGraphDFS.h"

// ���� �Լ�
int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;
	else
		return 1;
}

// Graph �ʱ�ȭ
void GraphInit(ALGraph* pg, int nv) {

	pg->numE = 0;
	pg->numV = nv;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->visitInfo = (int*)malloc(sizeof(int) * nv);
	memset(pg->visitInfo, 0, sizeof(int) * nv);

	for (int i = 0; i < nv; ++i) {
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
		// list�� ����ִ� �׸���� ���ڰ� �������
	}

}

// Graph ���ҽ� ����
void GraphDestroy(ALGraph* pg) {
	if (pg->adjList != NULL) {
		free(pg->adjList);
	}
	if (pg->visitInfo != NULL) {
		free(pg->visitInfo);
	}
}

// ������ �߰�
void AddEdge(ALGraph* pg, int fromV, int toV) {
	// ����� ���Ḯ��Ʈ�̹Ƿ�, ����� ��ο� �߰����־�� �Ѵ�.
	FInsert(&(pg->adjList[fromV]), toV);
	FInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

// ������ ���� ���
void ShowGraphEdgeInfo(ALGraph* pg) {

	LData tmpData;

	for (int i = 0; i < pg->numV; ++i) {
		printf("%c�� ����� ���� : ", i + 65);
		if (LFirst(&(pg->adjList[i]), &tmpData)) {
			printf("%c ", tmpData + 65);
			while (LNext(&(pg->adjList[i]), &tmpData))
				printf("%c ", tmpData + 65);
		}
		printf("\n");
	}
}

// �����鿡 �湮�ϴ� �Ͱ� ���õ� �Լ�
int VisitVertex(ALGraph* pg, int visitV) {
	if (pg->visitInfo[visitV] == 0) {
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

// DFS ����� ������ ���. (�������� ����)
void DFSShowGraphVertex(ALGraph* pg, int startV) {
	
	Stack stack;

	// visitV�� nextV�� ���� ������ ���̴�. 
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, startV);
	SPush(&stack, visitV);
	SPush(&stack, visitV);
	
	// adjList[]�� ù��° ����� �����Ѵٸ�
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {

		// �湮 ������ vertex�� ���� ���·� �ʱ�ȭ
		int visitFlag = FALSE;

		// �湮�� ���� ���� vertice�� ã�Ҵٸ�
		if (VisitVertex(pg, nextV) == TRUE) {
			// �湮�� ������ vertice �ֱ�
			SPush(&stack, nextV);
			// if�� Ż�� �Ŀ� �ٱ� while������ ������ �ش� adjList[]�� �̵�
			visitV = nextV;
			visitFlag = TRUE;
		}

		// �湮�� ���� �ִ� vertice�� ���� �湮�̶��
		else {
			// �ش� adjList[] ��� ���鼭 �湮�� �� ���� vertice�� ã�´�.
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
				// �湮�� �� ���� vertice�� ã�Ҵٸ�
				if (VisitVertex(pg, nextV) == TRUE) {
					// �湮�� ������ vertice �ֱ�
					SPush(&stack, nextV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		// �湮���� vertice�� ���ٸ�
		if (visitFlag == FALSE) {
			// ������ ������� �ʴٸ�
			// �ٽ� SPop
			if (SIsEmpty(&stack) == TRUE) {
				break;
			}
			else
				visitV = SPop(&stack);
		}

	}

	// ������ Ž���� ���ؼ� �޸� �ʱ�ȭ
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

}