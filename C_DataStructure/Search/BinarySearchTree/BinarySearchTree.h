#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

// ����, ����, Ž���� �ֿ� ����̴�.

#include "BinaryTree.h"

// �ʱ�ȭ
void BSTMakeAndInit(BTNode** pRoot);

// ������ ��ȯ
BSTData BSTGetNodeData(BTNode* bst);

// ���� ����
void BSTInsert(BTNode** pRoot, BSTData data);

// ���� Ž��
BTNode* BSTSearch(BTNode* bst, BSTData target);

// ���� ����
BTNode* BSTRemove(BTNode** pRoot, BSTData target);

// ��� ���� ���
void BSTPrintAll(BTNode* bst);

#endif