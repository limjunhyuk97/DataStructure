#include "BinaryTree.h"

BTNode* MakeBTreeNode(void) {
	BTNode* newBTNode = malloc(sizeof(BTNode));
	newBTNode->lsub = NULL;
	newBTNode->rsub = NULL;
	newBTNode->data = 0;
}

BTData GetData(BTNode* bt) {
	return bt->data;
}

void SetData(BTNode* bt, BTData data) {
	bt->data = data;
}

void MakeLeftSubTree(BTNode* root, BTNode* sub) {
	if (root->lsub != NULL)
		free(root->lsub);
	root->lsub = sub;
}

void MakeRightSubTree(BTNode* root, BTNode* sub) {
	if (root->rsub != NULL)
		free(root->rsub);
	root->rsub = sub;
}

BTNode* GetLeftSubTree(BTNode* root) {
	return root->lsub;
}

BTNode* GetRightSubTree(BTNode* root) {
	return root->rsub;
}

// 주소값에 대한 반환을 통해서 메모리 해제의 책임을 main으로 넘기고 있다.
// 제거와 메모리 해제는 별개의 것이다!
BTNode* RemoveLeftSubTree(BTNode* bt) {
	BTNode* tmpNode = NULL;
	if (bt->lsub != NULL) {
		tmpNode = bt->lsub;
		bt->lsub = NULL;
	}
	return tmpNode;
}

BTNode* RemoveRightSubTree(BTNode* bt) {
	BTNode* tmpNode = NULL;
	if (bt->rsub != NULL) {
		tmpNode = bt->rsub;
		bt->rsub = NULL;
	}
	return tmpNode;
}

void ChangeLeftSubTree(BTNode* root, BTNode* sub) {
	root->lsub = sub;
}

void ChangeRightSubTree(BTNode* root, BTNode* sub) {
	root->rsub = sub;
}

typedef void (*VisitFunc)(BTData data);

void InorderTraverse(BTNode* bt, VisitFunc action) {
	if (bt == NULL)
		return;
	
	InorderTraverse(bt->lsub, action);
	action(bt->data);
	InorderTraverse(bt->rsub, action);
}

void PreorderTraverse(BTNode* bt, VisitFunc action) {
	if (bt == NULL)
		return;

	action(bt->data);
	PreorderTraverse(bt->lsub, action);
	PreorderTraverse(bt->rsub, action);
}

void PostorderTraverse(BTNode* bt, VisitFunc action) {
	if (bt == NULL)
		return;

	PostorderTraverse(bt->lsub, action);
	PostorderTraverse(bt->rsub, action);
	PostorderTraverse(bt->rsub, action);
	action(bt->data);
}