#include "Hash.h"

#include <stdio.h>

Hash hash;

char sample[][MAXWORDLEN] = {
	"apple", "berry", "grape", "raisn","banana","watermelon","grapefruit","orange","kiwi","pear","peach"
};

int main(void) {

	char input[MAXWORDLEN];

	HashInit(&hash);

	// HashAdd 함수 이용하여 단어 추가
	for (int i = 0; i < sizeof(sample) / (sizeof(char) * MAXWORDLEN); ++i) {
		HashAdd(&hash, sample[i]);
	}

	// Hash Table 전체 상태 출력
	HashPrint(&hash);

	// LocationPrint 함수 이용하여 탐색 및 출력
	for (int i = 0; i < sizeof(sample) / (sizeof(char) * MAXWORDLEN); ++i) {
		LocationPrint(&hash, sample[i]);
	}
	printf("\n===================================\n\n");

	// Runtime에 Hash Table에서 단어 찾기
	while (TRUE) {

		printf(SEARCH);
		scanf_s("%s", input, MAXWORDLEN);

		if(HashSearch(&hash, input) > 0)
			printf(LOCATION, input, HashSearch(&hash, input));

		while (getchar() != '\n') {}
	};

	return 0;
}