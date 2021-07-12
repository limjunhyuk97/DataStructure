#include "InfixCalculator.h"

// exp의 원래 문자열을 보존하기 위하여 복사를 수행했다.
int EvalInfixExp(char exp[]) {

	int expLen = strlen(exp);
	char* tmpExp = (char*)malloc(expLen + 1);
	strcpy_s(tmpExp, expLen +1, exp);

	ConvToRPNExp(tmpExp);
	int res = EvalRPNExp(tmpExp);

	free(tmpExp);
	return res;
}
