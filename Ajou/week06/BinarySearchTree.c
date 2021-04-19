#include "BinarySearchTree.h"

// BST �ʱ�ȭ
void InitBST(BTNode** pRoot) {
	*pRoot = NULL;
}

// BST �Է�
int BSTInsert(BTNode** pRoot) {

	char name[23], region[42];
	int date;
	name[0] = 0;
	BTNode* cNode = *pRoot;
	BTNode* pNode = NULL;

	// ������ �Է¹ޱ�
	printf(INSERTMSG);
	printf(INSERTNAMEMSG);
	scanf_s("%s", name, 23); while (getchar() != '\n') {}
	printf(INSERTDATEMASG);
	scanf_s("%d", &date); while (getchar() != '\n') {}
	printf(INSERTREGION);
	scanf_s("%s", region, 42); while (getchar() != '\n') {}

	// �̻��� name �Է� ����
	if (name[0] == 0) {
		printf(INSERTINVALIDNAMEERRMSG);
		return FALSE;
	}

	// �ߺ� name�� ��� Ż�� + pNode ��ġ ã��
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

	// ���ο� ��� ����
	BTNode* newNode = makeBTNode();
	setBTNode(newNode, name, region, date);
	
	// ��Ʈ ����� ��쿡 ���� ó��
	if (pNode == NULL) {
		*pRoot = newNode;
		printf(INSERTOKMSG);
		return TRUE;
	}

	// ��Ʈ ��尡 �ƴ� ��쿡 ���� ó��
	if (strcmp(pNode->name, name) > 0) {
		setLeftSubTree(pNode, newNode);
	}
	else {
		setRightSubTree(pNode, newNode);
	}
	printf(INSERTOKMSG);

	return TRUE;
}

// BST Ž�� -> ���
void BSTPrint(BTNode** pRoot) {

	BTNode* targetNode;
	char name[23];
	name[0] = 0;

	// ������ �Է¹ޱ�
	printf(SEARCHMSG);
	printf(SEARCHINPUTNAMEMSG);
	scanf_s("%s", name, 23); while (getchar() != '\n') {}

	if (name[0] == 0) {
		printf(SEARCHINVALIDNAMEERRMSG);
		return;
	}

	targetNode = BSTSearch(pRoot, name);

	// ��ġ�ϴ� �����Ͱ� ���ٸ�
	if (targetNode == NULL) {
		printf(SEARCHINVALIDNONAMEERRMSG);
		return;
	}

	// ��ġ�ϴ� �����Ͱ� �ִٸ�
	printf(SEARCHOKMSG);
	printf(PRINTNAMEMSG, targetNode->name);
	printf(PRINTDATEMSG, targetNode->date);
	printf(PRINTREGIONMSG, targetNode->region);
	return;
}

// BST Ž��
BTNode* BSTSearch(BTNode** pRoot, char *tName) {
	
	BTNode* cNode = *pRoot;

	// name ������ ��ġ�ϴ� node�� ��ġ ã��
	while (cNode != NULL) {
		if (strcmp(cNode->name, tName) == 0) {
			return cNode;
		}
		else if (strcmp(cNode->name, tName) < 0)
			cNode = getRightSubTree(cNode);
		else
			cNode = getLeftSubTree(cNode);
	}

	// name ������ ��ġ�ϴ� node�� ������ ����ó��
	return NULL;

}

// BST ����
BTNode* BSTDelete(BTNode** pRoot) {
	
	// ���� ��Ʈ ��� ����
	BTNode* pVRoot = makeBTNode();
	pVRoot->rsub = *pRoot;
	BTNode* pNode = pVRoot;
	BTNode* cNode = *pRoot;
	// dNode�� �ƿ��� node�� ó�����ֱ� ���� ���� �������̴�.
	BTNode* dNode;

	// �̸� ���� �Է� �ޱ�
	char name[23]; name[0] = 0;
	printf(CHANGEDATAMSG);
	printf(CHANGEINPUTNAMEDATAMSG);
	scanf_s("%s", name, 23); while (getchar() != '\n') {}

	if (name[0] == 0) {
		printf(CHANGEINVALIDNAMEERRMSG);
		return NULL;
	}
	
	// �Էµ� �̸��� ��ġ ã��
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

	// �Է��� �̸��� ��ġ�ϴ� �̸��� ���ٸ�
	if (cNode == NULL) {
		printf(CHANGEINVALIDDATAERRMSG);
		return NULL;
	}

	// 1. pNode�� �ܸ���尡 0���� ���
	if ((getLeftSubTree(cNode) == NULL) && (getRightSubTree(cNode) == NULL)) {
		if (getLeftSubTree(pNode) == cNode) {
			dNode = deleteLeftSubTree(pNode);
		}
		else {
			dNode = deleteRightSubTree(pNode);
		}
	}

	// 2. pNode�� �ܸ���尡 1���� ���
	else if ((getLeftSubTree(cNode) == NULL) || (getRightSubTree(cNode) == NULL)) {
		BTNode* dcNode;
		dNode = cNode;
		
		// cNode�� ���ʿ� �ڽ��� �ִ°� �����ʿ� �ڽ��� �ִ°�
		if (getLeftSubTree(cNode) != NULL) {
			dcNode = getLeftSubTree(cNode);
		}
		else {
			dcNode = getRightSubTree(cNode);
		}

		// pNode�� dcNode���̱�
		if (getLeftSubTree(pNode) == cNode) {
			setLeftSubTree(pNode, dcNode);
		}
		else {
			setRightSubTree(pNode, dcNode);
		}
	}

	// 3. pNode�� �ܸ���尡 2���� ���
	else {
		dNode = cNode;
		while (getLeftSubTree(cNode) != NULL) {
			pNode = cNode;
			cNode = getLeftSubTree(cNode);
		}

		setBTNode(dNode, cNode->name, cNode->region, cNode->date);
		// ���� ����� ã�� �������� �ʾҴٸ�
		if (getRightSubTree(pNode) == cNode) {
			setRightSubTree(pNode, getRightSubTree(cNode));
		}
		// ���� ����� ã�� �������ٸ�
		else {
			setLeftSubTree(pNode, getRightSubTree(cNode));
		}

		// Ȧ�γ��� node�� cNode�� dNode�� ó������� �Ѵ�!
		dNode = cNode;
	}

	// ��Ʈ ��尡 �ٲ����ȴٸ�, ���� �ٲ� ��Ʈ ��带 ��Ʈ���� ����������Ѵ�!
	if (getRightSubTree(pVRoot) != *pRoot) {
		*pRoot = getRightSubTree(pVRoot);
	}

	// ��������� ������ ���� root node�� ������ ����.
	free(pVRoot);
	printf(CANCELOKMSG);
	return dNode;
}

// BST ����
void BSTChange(BTNode** pRoot) {

	char name[23], data[50];
	BTNode* targetNode;

	// ������ �Է¹ޱ�
	printf(CHANGEDATAMSG);
	printf(CHANGEINPUTNAMEDATAMSG);
	scanf_s("%s", name, 23); while (getchar() != '\n') {}
	scanf_s("%s", data, 50); while (getchar() != '\n') {}

	targetNode = BSTSearch(pRoot, name);

	// ��ġ�ϴ� �����Ͱ� ���ٸ�
	if (targetNode == NULL) {
		printf(CHANGEINVALIDDATAERRMSG);
		return;
	}

	// ��ġ�ϴ� �����Ͱ� �ִٸ�
	// ��¥ �����͸� �Է¹޾Ҵٸ�
	if (data[0] >= '0' && data[0] <= '9') {
		targetNode->date = atoi(data);
	}
	// ���� �����͸� �Է¹޾Ҵٸ�
	else {
		strcpy_s(targetNode->region, 42, data);
	}

	printf(CHANGEOKMSG);
	printf(PRINTNAMEMSG, targetNode->name);
	printf(PRINTDATEMSG, targetNode->date);
	printf(PRINTREGIONMSG, targetNode->region);
	return;
}

