#ifndef __BTREE_H__
#define __BTREE_H__

#include "declaration.h"

typedef int BTData;

typedef struct _node {
	struct _node* left;
	struct _node* right;
	BTData data;
}BTreeNode;

BTreeNode* MakeBTreeNode();
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetRightSubTree(BTreeNode* bt);
BTreeNode* GetLeftSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* bt, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* bt, BTreeNode* sub);

void DeleteTree(BTreeNode* bt);

typedef void (*VisitFunc)(BTData);

void InorderTraverse(BTreeNode* bt, VisitFunc action);
void PreorderTraverse(BTreeNode* bt, VisitFunc action);
void PostorderTraverse(BTreeNode* bt, VisitFunc action);

#endif