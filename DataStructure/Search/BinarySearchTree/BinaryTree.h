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

// Binary Search Tree를 위해서 새로 추가된 기능
// Remove : 트리에서의 삭제 O, 메모리 해제 X -> 메모리 반환
BTNode* RemoveLeftSubTree(BTNode* bt);
BTNode* RemoveRightSubTree(BTNode* bt);
// Change : sub트리 위치 밀어 올리기, 메모리 해제 X
void ChangeLeftSubTree(BTNode* root, BTNode* sub);
void ChangeRightSubTree(BTNode* root, BTNode* sub);

typedef void (*VisitFunc)(BTData data);

void InorderTraverse(BTNode* bt, VisitFunc action);
void PreorderTraverse(BTNode* bt, VisitFunc action);
void PostorderTraverse(BTNode* bt, VisitFunc action);

#endif