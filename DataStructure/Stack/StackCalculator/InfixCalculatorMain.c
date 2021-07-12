#include <stdio.h>
#include "InfixToPrefix.h"
#include "ListBaseStack.h"
#include "EvalRPNExp.h"
#include "InfixCalculator.h"

int main(void) {

	char exp[50];

	printf("수식을 입력하세요 : ");
	scanf_s("%s", exp, 50);
	printf("계산 결과 : %d\n",EvalInfixExp(exp));

	return 0;
}
