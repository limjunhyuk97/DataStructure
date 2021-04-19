#include "BinaryTree.h"

BTNode* makeBTNode() {
	BTNode *newNode = malloc(sizeof(BTNode));
	newNode->lsub = NULL;
	newNode->rsub = NULL;
	return newNode;
}

void setBTNode(BTNode* bt, char* name, char* region, int date) {
	strcpy_s(bt->name, 22, name);
	strcpy_s(bt->region, 42, region);
	bt->date = date;
	return;
}

BTNode* getRightSubTree(BTNode* bt) {
	return bt->rsub;
}

BTNode* getLeftSubTree(BTNode* bt) {
	return bt->lsub;
}

void setRightSubTree(BTNode* bt, BTNode* rsub) {
	bt->rsub = rsub;
}

void setLeftSubTree(BTNode* bt, BTNode* lsub) {
	bt->lsub = lsub;
}

BTNode* deleteLeftSubTree(BTNode* bt) {
	BTNode* tmpNode = bt->lsub;
	if (bt->lsub != NULL)
		bt->lsub = NULL;
	return tmpNode;
}

BTNode* deleteRightSubTree(BTNode* bt) {
	BTNode* tmpNode = bt->rsub;
	if (bt->rsub != NULL)
		bt->rsub = NULL;
	return tmpNode;
}
