#include "EvalRPNExp.h"
#include "ListBaseStack.h"

int EvalRPNExp(char exp[]) {
	
	Stack stack;
	StackInit(&stack);

	int expLen = strlen(exp);
	int res = 0;

	for (int i = 0; i < expLen; ++i) {
		if (isdigit(exp[i]))
			SPush(&stack, exp[i]);
		else {
			int num2, num1;
			num2 = SPop(&stack) - '0';
			num1 = SPop(&stack) - '0';

			switch (exp[i]) {
			case '*': 
				res = (num1 * num2);
				break;
			case '/':
				res = (num1 / num2);
				break;
			case '+':
				res = (num1 + num2);
				break;
			case'-':
				res = (num1 - num2);
				break;
			}

			SPush(&stack, res +'0');
		}
	}

	return res;
}
