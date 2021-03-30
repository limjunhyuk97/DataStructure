#include "ExpressionTree.h"

BTreeNode* MakeExpTree(char exp[]) {
	int expLen = strlen(exp);
	BTreeNode* tmp;
	Stack stack;

	InitStack(&stack);

	for (int i = 0; i < expLen; ++i) {
		tmp = MakeBTreeNode();
		if (isdigit(exp[i])) {
			SetData(tmp, exp[i] - '0');
		}
		else {
			SetData(tmp, exp[i]);
			MakeRightSubTree(tmp, Pop(&stack));
			MakeLeftSubTree(tmp, Pop(&stack));
		}
		Push(&stack, tmp);
	}
	return Pop(&stack);
}


int EvaluateExpTree(BTreeNode* bt) {

	if (bt->left == NULL || bt->right == NULL)
		return GetData(bt);

	int op1 = EvaluateExpTree(GetLeftSubTree(bt));
	int op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch (GetData(bt)) {
	case '+':
		return op1 + op2;
		break;
	case '-':
		return op1 - op2;
		break;
	case '*':
		return op1 * op2;
		break;
	case '/':
		return op1 / op2;
		break;
	}

	return 0;
}

void ShowNodeData(BTData data) {
	if (data >= 0 && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode* bt) {
	PreorderTraverse(bt, ShowNodeData);
}



void ShowInfixTypeExp(BTreeNode* bt) {
	if (bt == NULL) return;
	if (bt->data < 0 || bt->data >9)
		printf(" ( ");
	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);
	if (bt->data < 0 || bt->data >9)
		printf(" ) ");
}

void ShowPostfixTypeExp(BTreeNode* bt) {
	PostorderTraverse(bt, ShowNodeData);
}
