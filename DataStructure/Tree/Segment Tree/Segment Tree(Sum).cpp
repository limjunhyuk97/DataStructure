#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#define INF 1000000000
#define MIN -1
using namespace std;

int dataSet[15] = { 2, 5, 7, 10, 34, 67, 23, 10, 9, 1, 22, 76, 94, 43, 50 };
int sTree[35];
int minCnt, maxCnt;

// segment tree 
int makeSTree(int start, int end, int node) {

	if (start == end) return sTree[node] = dataSet[start];

	int mid = start + end >> 1;
	return sTree[node] = makeSTree(start, mid, 2 * node) + makeSTree(mid + 1, end, 2 * node + 1);

}

// start, end, node : 현재 들여다 보고 있는 구간
// left, right : 알고 싶은 구간
// 특정 구간의 합 뽑아내기
int getSectionSum(int start, int end, int node, int left, int right) {
	
	if (start > right || end < left) return 0;

	if (left <= start && end <= right) {
		cout << start<<"부터 " << end << " 까지 : node[" << node <<"] 더함 : " << sTree[node] << endl;
		return sTree[node];
	}

	int mid = start + end >> 1;
	
	return getSectionSum(start, mid, 2 * node, left, right) + getSectionSum(mid + 1, end, 2 * node + 1, left, right);

}

// start, end, node : 현재 들여다 보고 있는 구간
// left, right : 알고 싶은 구간
// 특정 구간에서 최소값 뽑아내기
int getMinimumElement(int start, int end, int node, int left, int right) {

	++minCnt;

	if (end < left || right < start) return INF;

	if (start == end) return sTree[node];

	int mid = start + end >> 1;

	return min(getMinimumElement(start, mid, node * 2, left, right), getMinimumElement(mid + 1, end, node * 2 + 1, left, right));
}

// start, end, node : 현재 들여다 보고 있는 구간
// left, right : 알고 싶은 구간
// 특정 구간에서 최대값 뽑아내기
int getMaximumElement(int start, int end, int node, int left, int right) {

	++maxCnt;

	if (end < left || right < start) return MIN;

	if (start == end) return sTree[node];

	int mid = start + end >> 1;

	return max(getMaximumElement(start, mid, node * 2, left, right), getMaximumElement(mid + 1, end, node * 2 + 1, left, right));

}

// 구간합들에 대한 갱신
void setSectionSum(int start, int end, int node, int dif, int target) {
	
	if (target < start || end < target) return;

	sTree[node] += dif;

	if (start == end) return;

	int mid = start + end >> 1;
	setSectionSum(start, mid, node * 2, dif, target);
	setSectionSum(mid + 1, end, node * 2 + 1, dif, target);

}

int main(void) {

	makeSTree(0, 14, 1);

	cout << getSectionSum(0, 14, 1, 2, 5) << endl;
	cout << getMinimumElement(0, 14, 1, 3, 6) << ", operation count : ";
	cout<< minCnt << endl;
	cout << getMaximumElement(0, 14, 1, 6, 12) << ", operation count : ";
	cout << maxCnt << endl;

	return 0;
}
