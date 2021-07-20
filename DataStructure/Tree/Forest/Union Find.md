# Union Find


## 1. Forest
  - 0개 이상의 disjoint tree(set) 집합
  - 집합 연산을 위한 토대가 된다.


## 2. Union - Find 연산

### 2.1 Simple Union
  - disjoint tree(set)들 간의 union 연산
  - 배열을 통해 구현할 때, linear하게 연결되는 경우 n-1 번의 union 연산은 O(n)의 시간복잡도 갖는다.
  - weighted union 방식을 통해서 개선할 수 있다.

### 2.2 Simple Find
  - 어떤 원소 i, j가 같은 disjoint tree(set)안에 있는지 확인하는 연산
  - linear하게 연결된 상태의 경우 n 번의 find 연산은 O(n^2)의 시간복잡도를 갖는다.
  - collapsing find 방식을 통해서 개선할 수 있다.

### 2.3 Weighted Union
  - root에 -(해당 tree의 노드수) 값을 저장한다.
  - union 연산 시에 각 tree의 노드 수를 고려하여, 노드 수가 작은 tree를 노드 수가 큰 tree에 붙인다.
  - 연산 수행시간은 Simple Union에 비해 약간 증가하지만, 상수에 의해 한정.

### 2.4 Collapsing Find
  - 특정 root값을 갖는 모든 노드들의 부모노드 값을 root값으로 변경시키는 연산을 수행하며 root 값을 반환한다.
  - 시간 복잡도를 획기적으로 단축할 수 있다.


## 3. 구현

```cpp
#include <iostream>
#include <algorithm>
using namespace std;



// union - find 1 //
const int MAX_SIZE = 6;
int par[MAX_SIZE + 1];

// forest 초기화
void make_set() {
	for (int i = 1; i <= MAX_SIZE; ++i)
		par[i] = i;
}

// find 연산 (Collapsing Find의 재귀적 방식 방식)
int Find(int num) {
	if (par[num] == num) return num;
	else return par[num] = Find(par[num]);
}

// path compression (Weighted된 경우는 아니다.)
void Union(int a, int b) {
	if (Find(a) != Find(b)) par[Find(b)] = Find(a);
}



// union - find 2 //
class Sets {
private :
	int* parent;
	int n;

public :
	Sets(int numberOfElements) {
		if (numberOfElements < 2) throw "Must have at least 2 elements.";
		n = numberOfElements;
		parent = new int[n];
		fill(parent, parent + n, -1);
	}

	void SimpleUnion(int i, int j) {
		parent[i] = j;
	}

	int SimpleFind(int i) {
		while (parent[i] >= 0)
			i = parent[i];
		return i;
	}

	// path compression (Weighted된 경우이다.) : parent 배열의 root 인덱스 부분에 set에 포함된 node의 수를 넣는다.
	void WieghtedUnion(int i, int j) {
		
		int iroot = CollapsingFind(i);
		int jroot = CollapsingFind(j);
		int tmp = parent[iroot] + parent[jroot];

		// node의 수가 더 많은 곳에 node의 수가 더 적은 것을 붙인다.
		// iroot set보다 jroot set에 노드의 수가 많다
		if (jroot != iroot) {
			if (parent[iroot] > parent[jroot]) {
				parent[iroot] = jroot;
				parent[jroot] = tmp;
			}
			// jroot보다 iroot에 노드의 수가 많다
			else {
				parent[jroot] = iroot;
				parent[iroot] = tmp;
			}
		}

	}

	// find 연산 (Collapsing Find의 반복적 방식)
	int CollapsingFind(int i) {
		int r = i;
		// root를 찾는 과정
		for (; parent[r] >= 0; r = parent[r]);
		while (i != r) {
			int tmp = par[i];
			par[i] = r;
			i = tmp;
		}
		return r;
	}

	~Sets() {
		delete[] parent;
	}

};



int main(void) {

	Sets set1(6);

	set1.WieghtedUnion(2, 3);
	set1.WieghtedUnion(4, 5);
	set1.WieghtedUnion(0, 2);

	for (int i = 0; i < 6; ++i)
		cout << set1.SimpleFind(i) << " ";

	return 0;

}


```
