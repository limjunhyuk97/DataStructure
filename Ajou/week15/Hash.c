#include "Hash.h"

#include <stdio.h>
#include <string.h>

int HashFunction(char* word) {

	int sum = 0;

	for (int i = 0; i < strlen(word); ++i) {
		sum += word[i];
	}

	return sum % BUCKETCOUNT;
}

void HashInit(Hash* hash) {

	hash->hashFull = FALSE;

	for (int i = 0; i < BUCKETCOUNT; ++i) {
		hash->bucketOccupy[i] = FALSE;
	}

}

void HashAdd(Hash* hash, char* word) {

	if (hash->hashFull) {
		printf(HASHFULL, word);
		return;
	}

	int hashVal = HashFunction(word);
	int dstVal = hashVal;

	while (hash->bucketOccupy[dstVal]) {

		// 중복된 데이터 제거
		if (strcmp(hash->bucket[dstVal], word) == 0) {
			printf(DUPLICATEDATA, word, dstVal);
			return;
		}

		dstVal = (dstVal + 1) % BUCKETCOUNT;

		// Hash Table이 가득찬 경우
		if (dstVal == hashVal) {
			hash->hashFull = TRUE;
			printf(HASHFULL, word);
			return;
		}

	}

	strcpy_s(hash->bucket[dstVal], 20, word);
	hash->bucketOccupy[dstVal] = TRUE;

	return;
}

int HashSearch(Hash* hash, char* word) {

	int hashVal = HashFunction(word);
	int targetVal = hashVal;

	while (strcmp(hash->bucket[targetVal], word) != 0) {

		targetVal = (targetVal + 1) % BUCKETCOUNT;

		if (targetVal == hashVal) {
			printf(NOSUCHDATA, word);
			return -1;
		}

	}

	return targetVal;

}

void HashPrint(Hash* hash) {

	printf("\n===================================\n");

	for (int i = 0; i < BUCKETCOUNT; ++i) {
		printf("[%d]", i);
		if (hash->bucketOccupy[i]) {
			printf("\t %s", hash->bucket[i]);
		}
		printf("\n");
	}

	printf("===================================\n\n");

}

void LocationPrint(Hash* hash, char* word) {

	if (HashSearch(hash, word) > 0) {
		printf(PRINTSEARCH, word, HashSearch(hash, word));
	}

	return;
}