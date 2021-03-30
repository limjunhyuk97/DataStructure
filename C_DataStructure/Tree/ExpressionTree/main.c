#include "ExpressionTree.h"

int main(void) {

	char exp[] = "12+7*";

	BTreeNode* eTree = MakeExpTree(exp);

	printf("���� ǥ����� �� ǥ�� : ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("���� ǥ����� �� ǥ�� : ");
	ShowInfixTypeExp(eTree); printf("\n");

	printf("���� ǥ����� �� ǥ�� : ");
	ShowPostfixTypeExp(eTree); printf("\n");

	ShowInfixTypeExp(eTree); printf(" =  %d\n", EvaluateExpTree(eTree));

	return 0;
}
