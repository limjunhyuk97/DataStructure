#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX(n, m) n > m ? n : m

int cnt, i, num;
int SamSpace[100];

int BSearchRecursive(int arr[], int start, int end, int target) {
	if (start > end) {
		return -1;
	}
	else {
		++cnt;
		int pivot = (start + end) / 2;
		if (arr[pivot] == target)
			return pivot;
		else if (arr[pivot] < target)
			BSearchRecursive(arr, pivot + 1, end, target);
		else
			BSearchRecursive(arr, start, pivot - 1, target);
	}
}

int main(void) {

	int arr[20];

	// 난수 생성하여 배열에 넣음
	srand((unsigned int)time(NULL));
	while (i < 20) {
		num = rand() % 100;
		if (SamSpace[num] == 0) {
			arr[i++] = num;
			SamSpace[num] = 1;
		}
	}

	// 배열 정렬
	for (int i = 0; i < 19; ++i) {
		for (int j = 0; j < 19 - i; ++j) {
			if (MAX(arr[j], arr[j + 1]) == arr[j]) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}


	// 각 위치에 따라서, 탐색에 걸리는 시간 도출해 봄
	for (int i = 0; i < 20; ++i) {
		int idx = BSearchRecursive(arr, 0, 19, arr[i]);
		printf("arr[%d] = %d\t index 찾기 : %d \t / recursion count : %d\n", i, arr[i], idx, cnt);
		cnt = 0;
	}

	return 0;
}
