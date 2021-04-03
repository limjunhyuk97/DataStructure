#include "BinaryTree.h"

BTNode* MakeNode(){
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

void SetNodeData(BTNode* node, BTData data) {
	node->data = data;
}

BTData GetNodeData(BTNode* node) {
	return node->data;
}

BTNode* GetRightSubNode(BTNode* node) {
	return node->right;
}

BTNode* GetLeftSubNode(BTNode* node) {
	return node->left;
}

void SetRightSubNode(BTNode* rootNode, BTNode* subNode) {
	rootNode->right = subNode;
}

void SetLeftSubNode(BTNode* rootNode, BTNode* subNode) {
	rootNode->left = subNode;
}

void InorderTraversal(BTNode* node, ActFunc action) {
	if (node == NULL)
		return;
	InorderTraversal(node->left, action);
	action(node);
	InorderTraversal(node->right, action);
}

void PreorderTraversal(BTNode* node, ActFunc action) {
	if (node == NULL)
		return;
	action(node);
	PreorderTraversal(node->left, action);
	PreorderTraversal(node->right, action);
}

void PostorderTraversal(BTNode* node, ActFunc action) {
	if (node == NULL)
		return;
	PostorderTraversal(node->left, action);
	PostorderTraversal(node->right, action);
	action(node);
}