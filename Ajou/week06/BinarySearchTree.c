#include "BinarySearchTree.h"

// BST 초기화
void InitBST(BTNode** pRoot) {
	*pRoot = NULL;
}

// BST 입력
int BSTInsert(BTNode** pRoot) {

	char name[23], region[42];
	int date;
	name[0] = 0;
	BTNode* cNode = *pRoot;
	BTNode* pNode = NULL;

	// 데이터 입력받기
	printf(INSERTMSG);
	printf(INSERTNAMEMSG);
	scanf_s("%s", name, 23); while (getchar() != '\n') {}
	printf(INSERTDATEMASG);
	scanf_s("%d", &date); while (getchar() != '\n') {}
	printf(INSERTREGION);
	scanf_s("%s", region, 42); while (getchar() != '\n') {}

	// 이상한 name 입력 제거
	if (name[0] == 0) {
		printf(INSERTINVALIDNAMEERRMSG);
		return FALSE;
	}

	// 중복 name일 경우 탈출 + pNode 위치 찾기
	while (cNode !=NULL) {
		if (strcmp(cNode->name, name) == 0) {
			printf(INSERTDUPLICATEERRMSG);
			return FALSE;
		}
		else if (strcmp(cNode->name, name) > 0) {
			pNode = cNode;
			cNode = getLeftSubTree(cNode);
		}
		else {
			pNode = cNode;
			cNode = getRightSubTree(cNode);
		}
	}

	// 새로운 노드 생성
	BTNode* newNode = makeBTNode();
	setBTNode(newNode, name, region, date);
	
	// 루트 노드일 경우에 대한 처리
	if (pNode == NULL) {
		*pRoot = newNode;
		printf(INSERTOKMSG);
		return TRUE;
	}

	// 루트 노드가 아닐 경우에 대한 처리
	if (strcmp(pNode->name, name) > 0) {
		setLeftSubTree(pNode, newNode);
	}
	else {
		setRightSubTree(pNode, newNode);
	}
	printf(INSERTOKMSG);

	return TRUE;
}

// BST 탐색 -> 출력
void BSTPrint(BTNode** pRoot) {

	BTNode* targetNode;
	char name[23];
	name[0] = 0;

	// 데이터 입력받기
	printf(SEARCHMSG);
	printf(SEARCHINPUTNAMEMSG);
	scanf_s("%s", name, 23); while (getchar() != '\n') {}

	if (name[0] == 0) {
		printf(SEARCHINVALIDNAMEERRMSG);
		return;
	}

	targetNode = BSTSearch(pRoot, name);

	// 일치하는 데이터가 없다면
	if (targetNode == NULL) {
		printf(SEARCHINVALIDNONAMEERRMSG);
		return;
	}

	// 일치하는 데이터가 있다면
	printf(SEARCHOKMSG);
	printf(PRINTNAMEMSG, targetNode->name);
	printf(PRINTDATEMSG, targetNode->date);
	printf(PRINTREGIONMSG, targetNode->region);
	return;
}

// BST 탐색
BTNode* BSTSearch(BTNode** pRoot, char *tName) {
	
	BTNode* cNode = *pRoot;

	// name 정보가 일치하는 node의 위치 찾기
	while (cNode != NULL) {
		if (strcmp(cNode->name, tName) == 0) {
			return cNode;
		}
		else if (strcmp(cNode->name, tName) < 0)
			cNode = getRightSubTree(cNode);
		else
			cNode = getLeftSubTree(cNode);
	}

	// name 정보가 일치하는 node가 없으면 예외처리
	return NULL;

}

// BST 삭제
BTNode* BSTDelete(BTNode** pRoot) {
	
	// 가상 루트 노드 생성
	BTNode* pVRoot = makeBTNode();
	pVRoot->rsub = *pRoot;
	BTNode* pNode = pVRoot;
	BTNode* cNode = *pRoot;
	// dNode는 아웃된 node를 처리해주기 위해 만든 포인터이다.
	BTNode* dNode;

	// 이름 정보 입력 받기
	char name[23]; name[0] = 0;
	printf(CHANGEDATAMSG);
	printf(CHANGEINPUTNAMEDATAMSG);
	scanf_s("%s", name, 23); while (getchar() != '\n') {}

	if (name[0] == 0) {
		printf(CHANGEINVALIDNAMEERRMSG);
		return NULL;
	}
	
	// 입력된 이름의 위치 찾기
	while (cNode != NULL) {
		if (strcmp(cNode->name, name) == 0)
			break;
		else if (strcmp(cNode->name, name) > 0) {
			pNode = cNode;
			cNode = getLeftSubTree(cNode);
		}
		else {
			pNode = cNode;
			cNode = getRightSubTree(cNode);
		}
	}

	// 입력한 이름과 일치하는 이름이 없다면
	if (cNode == NULL) {
		printf(CHANGEINVALIDDATAERRMSG);
		return NULL;
	}

	// 1. pNode의 단말노드가 0개인 경우
	if ((getLeftSubTree(cNode) == NULL) && (getRightSubTree(cNode) == NULL)) {
		if (getLeftSubTree(pNode) == cNode) {
			dNode = deleteLeftSubTree(pNode);
		}
		else {
			dNode = deleteRightSubTree(pNode);
		}
	}

	// 2. pNode의 단말노드가 1개인 경우
	else if ((getLeftSubTree(cNode) == NULL) || (getRightSubTree(cNode) == NULL)) {
		BTNode* dcNode;
		dNode = cNode;
		
		// cNode의 왼쪽에 자식이 있는가 오른쪽에 자식이 있는가
		if (getLeftSubTree(cNode) != NULL) {
			dcNode = getLeftSubTree(cNode);
		}
		else {
			dcNode = getRightSubTree(cNode);
		}

		// pNode에 dcNode붙이기
		if (getLeftSubTree(pNode) == cNode) {
			setLeftSubTree(pNode, dcNode);
		}
		else {
			setRightSubTree(pNode, dcNode);
		}
	}

	// 3. pNode의 단말노드가 2개인 경우
	else {
		dNode = cNode;
		while (getLeftSubTree(cNode) != NULL) {
			pNode = cNode;
			cNode = getLeftSubTree(cNode);
		}

		setBTNode(dNode, cNode->name, cNode->region, cNode->date);
		// 변경 대상을 찾아 내려가지 않았다면
		if (getRightSubTree(pNode) == cNode) {
			setRightSubTree(pNode, getRightSubTree(cNode));
		}
		// 변경 대상을 찾아 내려갔다면
		else {
			setLeftSubTree(pNode, getRightSubTree(cNode));
		}

		// 홀로남은 node인 cNode를 dNode로 처리해줘야 한다!
		dNode = cNode;
	}

	// 루트 노드가 바뀌어버렸다면, 새로 바뀐 루트 노드를 루트노드로 인정해줘야한다!
	if (getRightSubTree(pVRoot) != *pRoot) {
		*pRoot = getRightSubTree(pVRoot);
	}

	// 생성해줬던 임의의 가상 root node는 해제해 주자.
	free(pVRoot);
	printf(CANCELOKMSG);
	return dNode;
}

// BST 변경
void BSTChange(BTNode** pRoot) {

	char name[23], data[50];
	BTNode* targetNode;

	// 데이터 입력받기
	printf(CHANGEDATAMSG);
	printf(CHANGEINPUTNAMEDATAMSG);
	scanf_s("%s", name, 23); while (getchar() != '\n') {}
	scanf_s("%s", data, 50); while (getchar() != '\n') {}

	targetNode = BSTSearch(pRoot, name);

	// 일치하는 데이터가 없다면
	if (targetNode == NULL) {
		printf(CHANGEINVALIDDATAERRMSG);
		return;
	}

	// 일치하는 데이터가 있다면
	// 날짜 데이터를 입력받았다면
	if (data[0] >= '0' && data[0] <= '9') {
		targetNode->date = atoi(data);
	}
	// 지역 데이터를 입력받았다면
	else {
		strcpy_s(targetNode->region, 42, data);
	}

	printf(CHANGEOKMSG);
	printf(PRINTNAMEMSG, targetNode->name);
	printf(PRINTDATEMSG, targetNode->date);
	printf(PRINTREGIONMSG, targetNode->region);
	return;
}

