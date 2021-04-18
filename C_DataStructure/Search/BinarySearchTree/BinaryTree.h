#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#include "Declaration.h"

typedef struct BTreeNode {
	struct BTreeNode* lsub;
	struct BTreeNode* rsub;
	BTData data;
}BTNode;

BTNode* MakeBTreeNode(void);
BTData GetData(BTNode* bt);
void SetData(BTNode* bt, BTData data);

void MakeLeftSubTree(BTNode* root, BTNode* sub);
void MakeRightSubTree(BTNode* root, BTNode* sub);

BTNode* GetLeftSubTree(BTNode* root);
BTNode* GetRightSubTree(BTNode* root);

// Binary Search Tree�� ���ؼ� ���� �߰��� ���
// Remove : Ʈ�������� ���� O, �޸� ���� X -> �޸� ��ȯ
BTNode* RemoveLeftSubTree(BTNode* bt);
BTNode* RemoveRightSubTree(BTNode* bt);
// Change : subƮ�� ��ġ �о� �ø���, �޸� ���� X
void ChangeLeftSubTree(BTNode* root, BTNode* sub);
void ChangeRightSubTree(BTNode* root, BTNode* sub);

typedef void (*VisitFunc)(BTData data);

void InorderTraverse(BTNode* bt, VisitFunc action);
void PreorderTraverse(BTNode* bt, VisitFunc action);
void PostorderTraverse(BTNode* bt, VisitFunc action);

#endif