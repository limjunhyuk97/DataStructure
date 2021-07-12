#include "ExpressionTree.h"

int main(void) {

	char exp[] = "12+7*";

	BTreeNode* eTree = MakeExpTree(exp);

	printf("전위 표기법의 식 표현 : ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("중위 표기법의 식 표현 : ");
	ShowInfixTypeExp(eTree); printf("\n");

	printf("후위 표기법의 식 표현 : ");
	ShowPostfixTypeExp(eTree); printf("\n");

	ShowInfixTypeExp(eTree); printf(" =  %d\n", EvaluateExpTree(eTree));

	return 0;
}
