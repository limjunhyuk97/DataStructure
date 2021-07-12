#include "BinarySearchTree.h"

void BSTMakeAndInit(BTNode** pRoot) {

	// root���� ���� �־��ֱ� ������ ���̱� ������, �̸� ������ �ʴ´�.
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTNode* bst) {
	return GetData(bst);
}


// cNode�� ���ƴٴϸ鼭 Ȯ��!
void BSTInsert(BTNode** pRoot, BSTData data) {
	// ��ġ ã�� + �ߺ� ���� ����, ���ο� ��� ����, ���ο� ��� �߰� + root�� ��� ���
	// pNode, cNode, nNode�� ���ؼ� �����Ѵ�.
	
	BTNode* pNode = NULL;
	BTNode * cNode = *pRoot;
	BTNode* nNode = NULL;

	// ��ġ ã��
	while (cNode != NULL) {
		
		// �ߺ� ���� (Heap���� �ٸ���, BST�� �ߺ� key���� ������� �ʴ´�.)
		if (cNode->data == data)
			return;

		pNode = cNode;
		// ��ġ ã��
		if (cNode->data > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// ���ο� ��� ����
	nNode = MakeBTreeNode();
	SetData(nNode, data);

	// ���ο� ��� �߰�
	// root �߰��� �ƴѰ��
	if (pNode != NULL) {
		if (GetData(pNode) > data)
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	// root �߰��� ���
	else
		*pRoot = nNode;
}

// cNode�� ���ƴٴϸ鼭 Ȯ��!
BTNode* BSTSearch(BTNode* bst, BSTData target) {
	// cNode�� ���ؼ� �����Ѵ�.
	
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

	// pVRoot, root��尡 ������ ��츦 ����Ͽ� ����
	BTNode* pVRoot = MakeBTreeNode();
	BTNode* pNode = pVRoot;
	BTNode* cNode = *pRoot;
	BTNode* dNode;

	// pVRoot�� rsub�� *pRoot�� ����
	ChangeRightSubTree(pVRoot, *pRoot);

	// ��ġ ã��
	while (cNode != NULL && GetData(cNode) != target) {
		pNode = cNode;
		if (target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}

	// ã�� ���� ����
	if (cNode == NULL)
		return cNode;

	// ���� ��� dNode ���� + dNode�� ����صξ��ٰ� ��ȯ������ϴ� �ӽ�node
	dNode = cNode;

	// 1. dNode�� �ܸ������ ���
	if ((GetLeftSubTree(dNode) == NULL) && (GetRightSubTree(dNode) == NULL)) {

		// ��� ������ ������ ������ pNode�� ���ؼ�
		if (GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);
	}
	// ����� dNode ��ȯ�� ���� ����

	// 2. dNode�� ��尡 �Ѱ��� ���
	else if ((GetLeftSubTree(dNode) == NULL) || (GetRightSubTree(dNode) == NULL)) {
		BTNode* dcNode;

		// dNode�� �ڽ��� ���ʿ� �ִ���, �����ʿ� �ִ���
		if (GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		// ��� ������ ������ ������ pNode�� ���ؼ�
		if (GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);

	}
	// ����� dNode ��ȯ�� ���� ����

	// 3. dNode�� ��尡 �������� ���
	else {

		BTData tmpData;

		// ���� subtree���� ���� ���� key�� ���� ���(cNode) �߰�
		// cNode�� �θ��� pNode�� ����
		while (GetLeftSubTree(cNode) != NULL) {
			pNode = cNode;
			cNode = GetLeftSubTree(cNode);
		}

		// ���� ��� dNode�� �� ���� + dNode ���� ���� ��ȯ ���� ���
		tmpData = GetData(dNode);
		SetData(dNode, GetData(cNode));

		// ��� ������ ������ ������ pNode�� ���ؼ�
		// parent�� ������ �ڽ��̶��, parent�� ������ �ڽ��� �ڽ��� ������ �ڽ����� �ٲ۴�
		if (GetRightSubTree(pNode) == cNode) {
			ChangeRightSubTree(pNode, GetRightSubTree(cNode));
		}
		// paretn�� ���� �ڽ��̶��, parent�� ���� �ڽ��� �ڽ��� ������ �ڽ����� �ٲ۴�
		else {
			ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
		}

		// dNode ���� �� ����ؼ� ��ȯ
		// ��մ°�, ���� dNode�� �ƴ϶�, ������ ���ϸ� cNode�� Ʈ�� �������� ������� �� �����̴�.
		// dNode = cNode, cNode�� dNode ���� �� ������ ���ؼ� cNode�� ������ ���� �� ó�� ��ȯ���ش�.
		dNode = cNode;
		SetData(dNode, tmpData);
	}
	// ����� dNode ��ȯ�� ���� ����

	// root ��� ������ ��츦 �߰� ���
	// 1�ܰ迡�� pNode �����ʿ� NULL�� �ִ� �ܰ谡, ������ Ʈ�������� �ش�Ǵ°�.. ���� Ʈ���� root �� ������ ����
	// �߰������� root�� �����ϴ� �ܰ谡 �ʿ��ϴ�.
	if (GetRightSubTree(pVRoot) != *pRoot) {
		*pRoot = GetRightSubTree(pVRoot);
		// ��Ʈ ������ �������� ������ pRoot�� ���̻� ������ ��Ʈ��� ������ ���ϰ� �Ǵ� ��찡 ���� �� �ִ�.
		// ���� ��Ʈ ��尡 �ٲ�� �� ���, pRoot�� ��ȭ�� ��������� �Ѵ�.
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