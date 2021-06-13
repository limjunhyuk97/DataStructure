#include "Hash.h"

#include <stdio.h>

Hash hash;

char sample[][MAXWORDLEN] = {
	"apple", "berry", "grape", "raisn","banana","watermelon","grapefruit","orange","kiwi","pear","peach"
};

int main(void) {

	char input[MAXWORDLEN];

	HashInit(&hash);

	// HashAdd �Լ� �̿��Ͽ� �ܾ� �߰�
	for (int i = 0; i < sizeof(sample) / (sizeof(char) * MAXWORDLEN); ++i) {
		HashAdd(&hash, sample[i]);
	}

	// Hash Table ��ü ���� ���
	HashPrint(&hash);

	// LocationPrint �Լ� �̿��Ͽ� Ž�� �� ���
	for (int i = 0; i < sizeof(sample) / (sizeof(char) * MAXWORDLEN); ++i) {
		LocationPrint(&hash, sample[i]);
	}
	printf("\n===================================\n\n");

	// Runtime�� Hash Table���� �ܾ� ã��
	while (TRUE) {

		printf(SEARCH);
		scanf_s("%s", input, MAXWORDLEN);

		if(HashSearch(&hash, input) > 0)
			printf(LOCATION, input, HashSearch(&hash, input));

		while (getchar() != '\n') {}
	};

	return 0;
}