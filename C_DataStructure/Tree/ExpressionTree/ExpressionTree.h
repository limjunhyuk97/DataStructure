#ifndef __EXPRESSIONTREE_H__
#define __EXPRESSIONTREE_H__

#include "BTree.h"
#include "ListBaseStack.h"

// ���� ǥ��� -> ���� Ʈ�� : ���� Ʈ�� root ��ȯ
BTreeNode* MakeExpTree(char exp[]);

// ���� Ʈ�� -> ���� Ʈ�� ��� : ���� Ʈ�� ��� �� ��ȯ
int EvaluateExpTree(BTreeNode* bt);

// ����ǥ����� ����Ʈ�� ���
void ShowPrefixTypeExp(BTreeNode* bt);
void ShowInfixTypeExp(BTreeNode* bt);
void ShowPostfixTypeExp(BTreeNode* bt);
#endif