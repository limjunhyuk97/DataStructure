#include "BTree.h"

BTreeNode* MakeBTreeNode() {
	BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
	newNode->right = NULL;
	newNode->left = NULL;
	return newNode;
}
BTData GetData(BTreeNode* bt) {
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data) {
	bt->data = data;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
	return bt->right;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) {
	return bt->left;
}

void MakeLeftSubTree(BTreeNode* bt, BTreeNode* sub) {
	bt->left = sub;
}

void MakeRightSubTree(BTreeNode* bt, BTreeNode* sub) {
	bt->right = sub;
}

void DeleteTree(BTreeNode* bt) {
	if (bt == NULL) return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);
	free(bt);

}

void InorderTraverse(BTreeNode* bt, VisitFunc action) {
	if (bt == NULL) return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PreorderTraverse(BTreeNode* bt, VisitFunc action) {
	if (bt == NULL) return;

	action(bt->data);
	InorderTraverse(bt->left, action);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFunc action) {
	if (bt == NULL) return;

	InorderTraverse(bt->left, action);
	InorderTraverse(bt->right, action);
	action(bt->data);
}