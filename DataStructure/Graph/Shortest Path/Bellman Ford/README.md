# Bellman-Ford Algorithm
  - 음의 가중치가 존재하는 graph에 대해 shortest path를 구하기 위해 Dijkstra algorithm을 사용하면 cycle을 감지할 수 없다.
  - 위와 같은 경우 Bellman-Ford algorithm을 사용하면 cycle을 검출할 수 있다.
  - 시간복잡도는 O(E\*V)이며, 간선이 꽉 차있고 별다른 처리를 해주지 않는다면 E = V^2에 근사하여, O(V^3)의 시간복잡도를 갖게될 수도 있다.

<img src="https://user-images.githubusercontent.com/59442344/126596732-016ba66f-6130-4d6a-b06f-be3c72f7ac2d.jpg" width=80% height=70%>

## Bellman-Ford 구현 코드(cpp)

### 1. 시작 vertex와 vertex 수를 input으로 받는다.

```cpp
int Bellman_Ford(int s, int v) {

	// path 전체와 시작 vertex 초기화
	for (int i = 1; i <= v; ++i)
		path[i] = INF;
	path[s] = 0;

	// v - 1 횟수만큼 반복시킨다. v 번째에서 cycle 여부를 확인한다.
	// cycle 여부의 확인은 path 값 갱신 여부를 통해서 확인한다.
	bool update = false;

	// v번의 cycle을 돌린다
	for (int i = 0; i < v; ++i) {
		update = false;

		// v - 1 번의 loop(1 ~ v의 각 vertex들까지에 대한 path 값 갱신), v 번째에서 확인
		for (int j = 1; j <= v; ++j) {

			// path 값이 무한대이면 고려할 필요도 없다.
			if (path[j] == INF) continue;

			// 각 vertex와 연결된 다음 vertex까지의 path 값들을 갱신.
			for (int k = 0; k < edges[j].size(); ++k) {
				if (path[edges[j][k].first] > path[j] + edges[j][k].second) {
					path[edges[j][k].first] = path[j] + edges[j][k].second;
					update = true;
				}

			}
		}

		// update가 일어나지 않았다면, 다음번 cycle에서도 일어나지 않을 것이다.
		if (!update)
			break;
	}

	if (update) return -1;
	else return 0;

}
```

### 2. 시작 위치에 따라 cycle이 감지될 수도, 되지 않을 수도 있다.
  - 아래와 같은 경우, 시작 지점이 2, 1, 3의 경우 cycle이 탐지된다.
  - 반면 4의 경우 cycle을 탐지할 수 없다.
  
<img src="https://user-images.githubusercontent.com/59442344/126627129-9b2d5a4d-0646-4d01-aa88-da44895c2fc5.png" width = 40% height = 40%>

