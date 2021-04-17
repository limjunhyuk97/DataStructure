#include <stdio.h>

int cnt;

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

	int arr[10] = { 2, 4, 6, 8, 10, 12, 14, 16, 18 };
	int target;
	
	scanf_s("%d", &target);

	printf("%d ", BSearchRecursive(arr, 0, 9, target));
	printf("%d", cnt);

	return 0;
}
