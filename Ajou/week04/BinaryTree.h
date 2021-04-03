#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__
#include "Declaration.h"

typedef int BTData;

typedef struct Node {
	struct Node* left;
	struct Node* right;
	BTData data;
}BTNode;

BTNode* MakeNode();
void SetNodeData(BTNode* node, BTData data);
BTData GetNodeData(BTNode* node);

BTNode* GetRightSubNode(BTNode* node);
BTNode* GetLeftSubNode(BTNode* node);

void SetRightSubNode(BTNode* rootNode, BTNode* subNode);
void SetLeftSubNode(BTNode* rootNode, BTNode* subNode);

typedef void (*ActFunc)(BTNode *);

void InorderTraversal(BTNode* node, ActFunc action);
void PreorderTraversal(BTNode* node, ActFunc action);
void PostorderTraversal(BTNode* node, ActFunc action);

#endif