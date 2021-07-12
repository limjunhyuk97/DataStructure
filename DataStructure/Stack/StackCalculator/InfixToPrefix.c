#include "InfixToPrefix.h"
#include "ListBaseStack.h"

// GetOpPrec() function과, WhoPrecOp() function은 이 .c 파일 내부에만 있기에 외부에서 호출 불가능
// 마치 은닉된 것 같은 효과를 얻을 수 있다.

int GetOpPrec(char op) {
	switch (op) {
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	default:
		return -1;
	}
}

int WhoPrecOp(char op1, char op2) {

	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[]) {

	Stack stack;
	int expLen = strlen(exp);
	char* tmpExp = (char*)malloc(expLen + 1);

	int idx = 0;

	memset(tmpExp, 0, expLen + 1);
	StackInit(&stack);
		
	for (int i = 0; i < expLen; ++i) {
		if (isdigit(exp[i])) {
			tmpExp[idx++] = exp[i];
		}
		else {
			switch (exp[i]) {
			case '(':
				SPush(&stack, exp[i]);
				break;
			case ')':
				while (SPeek(&stack) != '(')
					tmpExp[idx++] = SPop(&stack);
				SPop(&stack);
				break;
			case '*': case'/': case '+': case '-':
				if(!SIsEmpty(&stack) &&  WhoPrecOp(SPeek(&stack), exp[i])>=0) {
					while (SIsEmpty(&stack))
						tmpExp[idx++] = SPop(&stack);
				}
				SPush(&stack, exp[i]);
				break;
			}
		}
			
	}

	while (!SIsEmpty(&stack)) {
		tmpExp[idx++] = SPop(&stack);
	}

	strcpy_s(exp, strlen(tmpExp)+1, tmpExp);
	free(tmpExp);

}
