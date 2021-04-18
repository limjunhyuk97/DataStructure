#include "BinarySearchTree.h"

void BSTMakeAndInit(BTNode** pRoot) {

	// root부터 값을 넣어주기 시작할 것이기 때문에, 미리 만들지 않는다.
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTNode* bst) {
	return GetData(bst);
}


// cNode가 돌아다니면서 확인!
void BSTInsert(BTNode** pRoot, BSTData data) {
	// 위치 찾기 + 중복 정보 무시, 새로운 노드 생성, 새로운 노드 추가 + root일 경우 고려
	// pNode, cNode, nNode를 통해서 구현한다.
	
	BTNode* pNode = NULL;
	BTNode * cNode = *pRoot;
	BTNode* nNode = NULL;

	// 위치 찾기
	while (cNode != NULL) {
		
		// 중복 제거 (Heap과는 다르게, BST는 중복 key값을 허용하지 않는다.)
		if (cNode->data == data)
			return;

		pNode = cNode;
		// 위치 찾기
		if (cNode->data > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// 새로운 노드 생성
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	// 새로운 노드 추가
	// root 추가가 아닌경우
	if (pNode != NULL) {
		if (GetData(pNode) > data)
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	// root 추가인 경우
	else
		*pRoot = nNode;
}

// cNode가 돌아다니면서 확인!
BTNode* BSTSearch(BTNode* bst, BSTData target) {
	// cNode를 통해서 구현한다.
	
	BTNode* cNode = bst;
	BTData data;

	while (cNode != NULL) {
		data = GetData(cNode);

		if (data == target)
			return cNode;
		if (data > target)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	return NULL;
}

BTNode* BSTRemove(BTNode** pRoot, BSTData target) {

	// pVRoot, root노드가 삭제될 경우를 대비하여 생성
	BTNode* pVRoot = MakeBTreeNode();
	BTNode* pNode = pVRoot;
	BTNode* cNode = *pRoot;
	BTNode* dNode;

	// pVRoot의 rsub로 *pRoot를 설정
	ChangeRightSubTree(pVRoot, *pRoot);

	// 위치 찾기
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// 찾는 것이 없다
	if (cNode == NULL)
		return cNode;

	// 삭제 대상 dNode 설정 + dNode는 백업해두었다가 반환해줘야하는 임시node
	dNode = cNode;

	// 1. dNode가 단말노드인 경우
	if ((GetLeftSubTree(dNode) == NULL) && (GetRightSubTree(dNode) == NULL)) {

		// 노드 변경의 과정은 무조건 pNode를 통해서
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	// 사라진 dNode 반환에 문제 없음

	// 2. dNode의 노드가 한개인 경우
	else if ((GetLeftSubTree(dNode) == NULL) || (GetRightSubTree(dNode) == NULL)) {
		BTNode* dcNode;

		// dNode의 자식이 왼쪽에 있는지, 오른쪽에 있는지
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		// 노드 변경의 과정은 무조건 pNode를 통해서
		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);

	}
	// 사라진 dNode 반환에 문제 없음

	// 3. dNode의 노드가 여러개인 경우
	else {

		BTData tmpData;

		// 우측 subtree에서 가장 작은 key값 갖는 노드(cNode) 발견
		// cNode의 부모노드 pNode로 유지
		while (GetLeftSubTree(cNode) != NULL) {
			pNode = cNode;
			cNode = GetLeftSubTree(cNode);
		}

		// 삭제 대상 dNode의 값 변경 + dNode 원래 값을 반환 위해 백업
		tmpData = GetData(dNode);
		SetData(dNode, GetData(cNode));

		// 노드 변경의 과정은 무조건 pNode를 통해서
		// parent의 오른쪽 자식이라면, parent의 오른쪽 자식을 자식의 오른쪽 자식으로 바꾼다
		if (GetRightSubTree(pNode) == cNode) {
			ChangeRightSubTree(pNode, GetRightSubTree(cNode));
		}
		// paretn의 왼쪽 자식이라면, parent의 왼쪽 자식을 자식의 오른쪽 자식으로 바꾼다
		else {
			ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
		}

		// dNode 원래 값 백업해서 반환
		// 재밌는건, 현재 dNode가 아니라, 엄밀히 말하면 cNode가 트리 구조에서 사라지게 된 상태이다.
		// dNode = cNode, cNode에 dNode 이전 값 대입을 통해서 cNode가 삭제된 것인 것 처럼 반환해준다.
		dNode = cNode;
		SetData(dNode, tmpData);
	}
	// 사라진 dNode 반환에 문제 없음

	// root 노드 제거의 경우를 추가 고려
	// 1단계에서 pNode 오른쪽에 NULL을 넣는 단계가, 가상의 트리에서만 해당되는것.. 실제 트리는 root 안 없어진 상태
	// 추가적으로 root를 제거하는 단계가 필요하다.
	if (GetRightSubTree(pVRoot) != *pRoot) {
		*pRoot = GetRightSubTree(pVRoot);
		// 루트 삭제의 과정에서 기존의 pRoot가 더이상 기존의 루트노드 구실을 못하게 되는 경우가 생길 수 있다.
		// 기존 루트 노드가 바뀌게 된 경우, pRoot의 변화를 갱신해줘야 한다.
	}

	free(pVRoot);
	return dNode;
}

void printKey(BTData data) {
	printf("%d ", data);
}

void BSTPrintAll(BTNode* bst) {
	InorderTraverse(bst, printKey);
}