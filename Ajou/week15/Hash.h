#ifndef __HASH_H__
#define __HASH_H__

#define TRUE 1
#define FALSE 0
#define BUCKETCOUNT 26
#define MAXWORDLEN 20

#define HASHFULL "Hash Table is Full. Can't Insert %s\n"
#define DUPLICATEDATA "Word %s Already exists in index %d.\n"
#define NOSUCHDATA "Word %s doesn't exist in Hash Table.\n\n"
#define PRINTSEARCH "Å½»ö %s: À§Ä¡ = %d\n"
#define SEARCH "Å½»ö  : "
#define LOCATION "%sÀÇ À§Ä¡ = %d\n\n"

typedef struct Hash {
	char bucket[BUCKETCOUNT][20];
	int bucketOccupy[BUCKETCOUNT];
	int hashFull;
}Hash;

void HashInit(Hash* hash);

void HashAdd(Hash* hash, char* word);

int HashSearch(Hash* hash, char* word);

void HashPrint(Hash* hash);

void LocationPrint(Hash *hash, char* word);

#endif