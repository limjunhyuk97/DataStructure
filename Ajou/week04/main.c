#include "BinaryTree.h"

void printNodeData(BTNode* node) {
	printf("%d ", node->data);
}

int main(void) {
	
	BTNode* BTree[11];

	for (int i = 0; i < 11; ++i) {
		BTree[i] = MakeNode();
		SetNodeData(BTree[i], i + 1);
	}

	SetLeftSubNode(BTree[5], BTree[3]);
	SetRightSubNode(BTree[5], BTree[8]);
	SetLeftSubNode(BTree[3], BTree[1]);
	SetRightSubNode(BTree[3], BTree[4]);
	SetLeftSubNode(BTree[1], BTree[0]);
	SetRightSubNode(BTree[1], BTree[2]);
	SetLeftSubNode(BTree[8], BTree[6]);
	SetRightSubNode(BTree[8], BTree[9]);
	SetLeftSubNode(BTree[9], BTree[7]);
	SetRightSubNode(BTree[9], BTree[10]);

	printf("Inorder traversal의 결과 : ");
	InorderTraversal(BTree[5], printNodeData);
	printf("\n");

	printf("Preorder traversal의 결과 : ");
	PreorderTraversal(BTree[5], printNodeData);
	printf("\n");

	printf("Postorder traversal의 결과 : ");
	PostorderTraversal(BTree[5], printNodeData);
	printf("\n");

}