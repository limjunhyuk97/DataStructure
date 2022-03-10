# Graph
  


## 01. Graph 정의

- **graph** :  V가 non-empty set이고, E가 V의 원소들로 이루어진 unordered pair의 multiset일 때, (V, E) 의 ordered pair.
- **directed graph** : V가 non-empty set이고, A가 V의 원소들로 이루어진 ordered pair의 set일 때, (V, A) 의 ordered pair.
  - A : arc set
  - element of A : arc



## 02. Graph(G) 용어

- **maximal과 maximum**
  - **maximal** : 포함관계에 따라 최대 인 것
  - **maximum** : 우리가 고려하는 것 중 가장 큰 것. (maximal 중에 가장 큰 것.)

- **V(G)** : vertex set of G, element of V : vertex
  - **isolated vertex** : degree가 0인 vertex
  - **pendant vertex (leaf)** : degree가 1인 vertex

- **E(G)** : edge set of G, element of E : edge
  - u, v vertex를 끝점으로 갖는 edge를 **uv**로 표현한다.
  - **multiple edges** : 동일한 두 vertex에 edge가 여러개 연결된 경우

- **adjacent** : vertex x와 y가 edge e로 연결되어 있는 상태
  - **neighbor** : adjacent한 두 vertex x, y
  - **endpoint** : edge e의 양끝 x, y
  - **incident** : x, y에 연결된 edge e

- **loop** : 오직 하나의 vertex와 연결된 edge

- **simple graph** : loop, multiple edge 가 없는 graph

- **isomorphic** : vertex 수와 edge 수가 같고, 동일한 edge connectivity를 갖는 graph 관계

- **isomorphisim** : "graph G1 에서의 vertex a와 연결된 edge수 = graph G2 에서의 vertex f(a)와 연결된 edge수" 를 만족하는 함수 f를 isomorphism 이라 한다.

- **neighborhood NG(v)** : vertex v와 edge로 연결된 vertex 집합

- **closded neighborhood NG[v]** : NG(v) U {v}

- **degree degG(v)** : (V, E) 의 E집합에서 원소 v의 frequency
  - **minimum degree δ(G)** : minimum degree of G
  - **maximum degree ∆(G)** : maximum degree of G
  - **average degree d(G)** : average degree of G

- **regular graph** : 모든 vertex의 degree가 같은 경우
  - **d-regular** : 모든 vertex의 degree가 d인 graph
  - **cubic graph** : 3-regular
  - **subcubic graph** : ∆(G) <= 3 인 graph

- **degree-sequence of G** : graph G의 각 vertex 들의 degree 나열
  - **graphic** : sequence d가 simple graph를 만들 수 있다면 sequence 가 graphic 하다고 한다.

- **subgraph H** : V (H) ⊂ V (G) / E(H) ⊂ E(G)
  - **spanning subgraph H** : V (H) = V (G) / E(H) ⊂ E(G)
  - **induced subgraph H** : V (H) ⊂ V (G) / u,v ∈ V(H) and uv ∈ E(G)
  - example
    - G1, G2, G3 는 G 의 subgraph
    - G2, G3 는 G의 induced subgraph
    - G3는 G2의 induced subgraph
    - 어느 하나 G의 spanning subgraph 만족 안함

<p align="center"><img src="https://user-images.githubusercontent.com/59442344/157672002-a3565cde-0f5e-49a6-b521-53b4e58766b7.png" width="80%"></p>

- **H-factor** : 

- **k-factor of G** : 정수 k에 대해 그래프 G의 spanning subgraph 중 k-regular 인 것.

- **connected graph** : G 안의 아무 vertex 사이에 walk가 존재하는 graph
- **connected component** : G의 maximal connected subgraph

- **walk** : v0e1v1e2··· envn 꼴의 edge와 vertex로 이루어진 sequence로, sequence 안의 ei는 vi-1, vi를 endpoint로 갖는 edge
  - **path** : sequence 안에 중복된 vertex를 갖지 않는 walk
  - **trail** : sequence 안에 중복된 edge를 갖지 않는 walk
  - **length of walk** : sequence 안에 edge의 수

- **distance distG(u, v)** : u와 v 사이의 shortest path의 length
  - **diameter diam(G)** : graph G 안의 distance 중 가장 큰 값
  - **eccentricity of v** : 어떤 vertex가 graph G 안에서 갖을 수 있는 다른 vertex 까지의 distance 중 가장 큰 값 (이심률)
  - **radius of G** : G 안에서 가능한 eccentricity 중 가장 작은 값
  - **center of G** : eccentricity가 radius와 같은 graph 내 vetex 집합

- **closed walk(trail)** : 시작 vertex, 끝 vertex 같은 walk(trail)

- **cycle** : 중복되는 vertex와 edge를 지나지 않고, 시작과 끝 vertex 가 같은 walk
  - 중복되는 vertex가 없는 closed trail
  - **acyclic** : cycle이 없는 graph

- **girth g(G)** : G에 존재하는 minimum length cycle의 length

- **Hamiltonian cycle** : G가 모든 vertex를 포함하는 cycle을 갖을 때 해당 cycle을
- **Hamiltonian graph** : Hamiltonian cycle이 있는 graph

- **Eulerian circuit** : G의 모든 edge를 지나는 closed trail
- **Eulerian graph** : Eulerian ciruit을 지니는 graph

- **clique** : complete graph와 isomorphic한 subgraph
- **independent set** : edgless graph와 isomorphic한 subgraph

- **complement of G** : G의 vertex로 만들수 있는 edge 조합 중, G에 존재하지 않는 edge와 G에 존재하는 vertex로 이뤄진 graph


## 03. 특별한 Graph

- **complete graph Kn** : 모든 vertex 가 서로 다 연결된 graph
- **cycle Cn** : 정다각형 그래프
- **Wheel Wn** : 모든 vertex와 연결된 vertex가 존재하는 graph
- **Path Pn** : 모든 vertex 차수가 2 이하인 Tree
- **Hypercube Qn** : vertex는 0과 1로 이루어진 sequence, edge는 sequence에서 digit 하나만 다른 경우 연결된 형태의 graph
- **bipartite** : vertex 집합이 v1, v2 disjoint set으로 쪼개져 있고, 모든 edge는 v1의 원소와 v2의 원소를 잇고 있는 형태의 graph
  - **complete bipartite graph Km,n** : 다른 파트의 vertex들 간에 빠짐없이 짝을 이루어 연결되어 있는 bipartite graph


## 04. Graph 구현

### 04-1. 인접 행렬 (Adjacency matrix)

- vertex와 vertex 사이의 관계에 대한 행렬
- 가로, 세로 길이 같은 정방행렬(2차원 행렬)을 통해서 구현.

<p align="center"><img src="https://user-images.githubusercontent.com/59442344/157691137-3cbd7249-7c6d-497c-8cde-a6eac1078d41.png" width="80%"></p>

### 04-2. 인접 리스트 (Adjacency list)

- 각 정점 별로 연결되어 있는 정점 리스트를 갖고 있음.

<p align="center"><img src="https://user-images.githubusercontent.com/59442344/116784381-e6607c80-aace-11eb-839d-6a05c2e07bab.png" width="80%"></p>

### 04-3. Incidence matrix

- vertex와 edge 사이의 관계에 대한 행렬
- directed graph를 이 방식으로 표현한다면, matrix 내부 원소를 0, -1 , 1 로 표현할 수 있다.
- Handshake Theorem을 matrix를 그림으로써 바로 보일 수 있다.

<p align="center"><img src="https://user-images.githubusercontent.com/59442344/157690944-f208097f-c244-4ed7-b76a-c1db30e9df41.png" width="80%"></p>

## 05. Lemma

### Handshaking Lemma

- 모든 vertex의 degree의 합 = edge수 의 2배



## 06. Theorem

### First Theorem of Graph Theory

- graph 는 홀수 차수의 vertex를 짝수개 갖는다.
- 이 성질을 바탕으로 **degree sequence를 바탕으로 graph 생성가능 여부 판단 가능**하다.



## 07. Notes

- degree sequence에 있는 수를 다 더했을 때 짝수라면, 해당 degree sequence로 graph를 만들 수 있다.
- |V(G)| = n , |E(G)| = m 일 떄, Graph는 n-m 개의 최소 component 갖는다.
- 모든 simple graph는, 적어도 δ(G) length의 path를 갖는다.
- δ(G)>=2 를 만족하는 모든 simple graph는, 적어도 δ(G) + 1 length의 cycle 갖는다.
- connected graph G의 모든 vertex가 짝수 degree를 갖으면, 해당 graph는 eulerian graph이다.
- Graph G
  - A : adjacency matrix
  - R : 주대각에 degree 값 갖는 matrix
  - D : directed graph
  - M : incidence matrix
  - M * transpose(M) = A + R
- maximal clique/independent set != maximum clique/independent set