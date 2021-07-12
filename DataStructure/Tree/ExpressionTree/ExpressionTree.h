#ifndef __EXPRESSIONTREE_H__
#define __EXPRESSIONTREE_H__

#include "BTree.h"
#include "ListBaseStack.h"

// 후위 표기식 -> 수식 트리 : 수식 트리 root 반환
BTreeNode* MakeExpTree(char exp[]);

// 수식 트리 -> 수식 트리 계산 : 수식 트리 계산 값 반환
int EvaluateExpTree(BTreeNode* bt);

// 전위표기법의 수식트리 출력
void ShowPrefixTypeExp(BTreeNode* bt);
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixTypeExp(BTreeNode* bt);
#endif