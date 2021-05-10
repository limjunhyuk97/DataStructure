#include "disjointSet.h"

void SetInit(disjointSet* set) {
	for (int i = 0; i < MAX_LEN; ++i) {
		set->disjointSet[i] = -1;
	}
}

int Find(int n, disjointSet* set) {

	for (; set->disjointSet[n] > 0; n = set->disjointSet[n]);

	return n;
}

void Union(int n, int m, disjointSet *set) {
	if (Find(n, set) == Find(m, set))
		return;

	set->disjointSet[Find(n,set)] = m;
}

void PrintAllRoot(disjointSet* set) {
	for (int i = 1; i < MAX_LEN; ++i) {
		printf("노드 %d의 root는 %d\n", i, Find(i, set));
	}
}

void SetCheck(disjointSet* set) {
	int flag = 1;
	printf(CHECKSAMESETMSG);
	
	char flagChar = 0;
	int n, m;
	while (flag) {
		printf(INPUTNODEMSG);
		scanf_s("%d %d", &n, &m);
		while (getchar() != '\n') {}
		if ((n < 0 || n>15) || (m < 0 || m>15)) {
			printf(ERRNODEINPUTMSG);
			continue;
		}

		if (Find(n, set) == Find(m, set))
			printf(SAMESETMSG, n, m);
		else
			printf(DIFFSETMSG, n, m);

		flagChar = 0;
		while (!flagChar) {
			printf(MORETRIALMSG);
			scanf_s("%c", &flagChar, 1);
			while (getchar() != '\n') {}
			switch (flagChar) {
			case 'Y':
				break;
			case 'N':
				flag = 0;
				break;
			default:
				flagChar = 0;
				printf(ERRFLAGINPUTMSG);
				break;
			}
		}
	}

}