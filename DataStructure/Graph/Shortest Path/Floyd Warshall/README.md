# Floyd-Warshall
  - 모든 정점에서 다른 모든 정점으로의 최단거리를 구하는 알고리즘이다.
  - i에서 j로 향하는 최단경로를 구하기 위해, k(모든 vertex)를 경유하는 i - k - j 구간을 모두 고려하여 최단경로를 구한다.
  - 시간복잡도 O(V^3)를 갖는다.


## Floyd-Warshall 구현 코드(cpp)

### 2차원 행렬을 이용한다.
  - 2차원 행렬을 이용하여, 모든 vertex에 대해서 각 vertex들 사이 구간의 weight를 모두 기술한다.
  
```cpp
#include <iostream>
#define INF 1e18
using namespace std;

typedef long long int ll;
ll w, path[102][102];
int N, M, u, v;

// Floyd_Warshall
void Floyd_Warshall(int vertex) {
  // vertex k를 경유하여 i - j로 가는 모든 경로에 대한 갱신이 일어난다.
	for (int k = 1; k <= vertex; ++k) {
		for (int i = 1; i <= vertex; ++i) {
			for (int j = 1; j <= vertex; ++j) {
				if (path[i][j] > path[i][k] + path[k][j])
					path[i][j] = path[i][k] + path[k][j];
			}
		}
	}

}

int main(void) {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 102; ++i) {
		for (int j = 0; j < 102; ++j) {
			if (i != j) path[i][j] = INF;
		}
	}

	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> u >> v >> w;
		path[u][v] = (path[u][v] > w ? w : path[u][v]);
	}

	Floyd_Warshall(N);

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if (path[i][j] == INF) cout << 0 << " ";
			else cout << path[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
```
