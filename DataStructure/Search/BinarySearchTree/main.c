#include "BinarySearchTree.h"

int main(void) {

	BTNode* BSTRoot;
	BTNode* sNode;		// searchNode
	srand((unsigned int)time(NULL));

	BSTMakeAndInit(&BSTRoot);

	for (int i = 0; i < 10; ++i) {
		BSTInsert(&BSTRoot, i);
	}

	BSTPrintAll(BSTRoot);
	BSTRemove(&BSTRoot, 4);
	BSTPrintAll(BSTRoot);

	return 0;
}