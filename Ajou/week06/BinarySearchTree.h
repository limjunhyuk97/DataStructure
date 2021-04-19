#include "BinaryTree.h"

// BST 초기화
void InitBST(BTNode** pRoot);

// BST 입력
int BSTInsert(BTNode** pRoot);

// BST 탐색 -> 출력
void BSTPrint(BTNode** pRoot);

// BST 탐색
BTNode* BSTSearch(BTNode** pRoot, char *tName);

// BST 삭제
BTNode* BSTDelete(BTNode** pRoot);

// BST 탐색 -> 변경
void BSTChange(BTNode** pRoot);