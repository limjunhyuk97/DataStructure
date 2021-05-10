#include "disjointSet.h"

int main(void) {

	disjointSet set;

	SetInit(&set);
	Union(1, 2, &set);
	Union(1, 3, &set);
	Union(1, 4, &set);
	Union(3, 5, &set);
	Union(5, 6, &set);
	Union(7, 8, &set);
	Union(9, 10, &set);
	Union(10, 11, &set);
	Union(12, 14, &set);

	PrintAllRoot(&set);
	SetCheck(&set);

	return 0;
}