#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__
#include "Declaration.h"

// Tree 구조, 구현
typedef int BTData;

typedef struct _bTreeNode {

	struct _bTreeNode* left;
	struct _bTreeNode* right;
	BTData data;

}BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode *sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode *sub);

void DeleteTree(BTreeNode* bt);

// Tree 탐색, Traverse의 구현
typedef void (*VisitFuncPtr)(BTData);

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

#endif
