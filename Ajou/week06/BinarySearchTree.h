#include "BinaryTree.h"

// BST �ʱ�ȭ
void InitBST(BTNode** pRoot);

// BST �Է�
int BSTInsert(BTNode** pRoot);

// BST Ž�� -> ���
void BSTPrint(BTNode** pRoot);

// BST Ž��
BTNode* BSTSearch(BTNode** pRoot, char *tName);

// BST ����
BTNode* BSTDelete(BTNode** pRoot);

// BST Ž�� -> ����
void BSTChange(BTNode** pRoot);