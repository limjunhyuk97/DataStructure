#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

// 삽입, 삭제, 탐색이 주요 기능이다.

#include "BinaryTree.h"

// 초기화
void BSTMakeAndInit(BTNode** pRoot);

// 데이터 반환
BSTData BSTGetNodeData(BTNode* bst);

// 정보 삽입
void BSTInsert(BTNode** pRoot, BSTData data);

// 정보 탐색
BTNode* BSTSearch(BTNode* bst, BSTData target);

// 정보 삭제
BTNode* BSTRemove(BTNode** pRoot, BSTData target);

// 모든 정보 출력
void BSTPrintAll(BTNode* bst);

#endif