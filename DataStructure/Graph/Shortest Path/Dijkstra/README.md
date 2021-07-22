# Dijkstra
  - 음의 가중치가 없는, 가중치 그래프에서 특정 정점으로부터 다른 정점들까지의 최소 거리를 구하는데 사용한다.
  - greedy algorithm이 적용된다.
  - priority_queue를 이용하여 구현한다면, 시간복잡도 O(E\*logV)를 갖게 된다. : E만큼의 edge 꺼내고, logV의 복잡도로 vertex에 접근한다.

## Dijkstra 구현 코드(cpp)

### 1. pair이용
  - 기본 상태에서 priority_queue는 max_heap으로 구현되는 것을 감안하여 pair에 -weight 값을 넣어 weight가 오름차순으로 정렬되게 하는 방식
 
```cpp
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define INF 1e9
using namespace std;

// first : weight, second :end
typedef pair<int, int> edge;
int V, E, S;
int u, v, w;

int path[20005];
vector<edge> Edge[20005];
priority_queue<edge> nextE;

int main(void) {

	cin >> V >> E >> S;
	
	for (int i = 0; i < E; ++i) {
		cin >> u >> v >> w;
		Edge[u].push_back({ -w, v });
	}

	for (int i = 0; i < 20005; ++i)
		path[i] = INF;
	path[S] = 0;

	nextE.push({ 0 ,S });

	while (!nextE.empty()) {
		
		edge e = nextE.top(); nextE.pop();

		if (path[e.second] < -e.first) continue;
		for (int i = 0; i < Edge[e.second].size(); ++i) {
			int nextV = Edge[e.second][i].second;
			int nextW = -Edge[e.second][i].first;
			if (path[nextV] > path[e.second] + nextW) {
				path[nextV] = path[e.second] + nextW;
				nextE.push({ -path[nextV], nextV });
			}
		}

	}

	for (int i = 1; i <= V; ++i) {
		if (path[i] < INF) cout << path[i] << "\n";
		else cout << "INF" << "\n";
	}

	return 0;
}
```

### 2. sturct 정의
  - graph edge에 대한 struct를 미리 정의하여 사용.

```cpp
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 1e9
using namespace std;

struct edge {

    int end;
    int weight;

    bool operator<(const edge& other) const {
        return weight > other.weight;
    }
};

int V, E, S, u, v, w;
int path[20005];
vector<edge> edges[20005];
priority_queue<edge> nextEdges;

int main(void) {

    scanf("%d %d %d", &V, &E, &S);

    for (int i = 0; i < E; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back({ v, w });
    }

    for (int i = 0; i < 20005; ++i)
        path[i] = INF;
    path[S] = 0;
    nextEdges.push({ S, 0 });

    while (!nextEdges.empty()) {
        edge cur = nextEdges.top(); nextEdges.pop();
        int curE = cur.end; int curV = cur.weight;
        if (path[cur.end] < cur.weight) continue;
        for (int i = 0; i < edges[cur.end].size(); ++i) {
            int nextE = edges[cur.end][i].end;
            int nextW = edges[cur.end][i].weight;
            if (path[nextE] > path[curE] + nextW) {
                path[nextE] = path[curE] + nextW;
                // path 값이 갱신되었다면, 다음 노드에 대한 정보와 해당 노드까지의 path 값을 전달한다.
                nextEdges.push({ nextE, path[nextE] });
            }
        }
    }

    for (int i = 1; i <= V; ++i) {
        if (path[i] < INF) printf("%d\n", path[i]);
        else printf("INF\n");
    }
    printf("\n");

    return 0;
}
```
