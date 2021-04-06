# Heap

## Heap이란 무엇인가?
 - binary tree이자, complete binary tree (CBT)이다.
 - 각 노드에 저장된 값이 자식 노드에 저장된 값보다 일관되게 크면서 같거나, 작으면서 같은 자료구조이다.
 - priority queue의 구현을 위해서 응용된 binary tree 구조이다.

## Heap의 종류

### 1. Max Heap - 최대 힙
  - 자식 노드로 내려갈 수록 데이터의 크기가 작아지는 Heap

### 2. Min Heap - 최소 힙
  - 자식 노드로 내려갈 수록 데이터의 크기가 커지는 Heap

<img src="https://user-images.githubusercontent.com/59442344/113717901-0cd90500-9727-11eb-9508-c739685e1363.png" width=50% height=50%>

## Heap의 구현
  - **Heap은 배열로 구현하는 것이 일반적**이다. 가급적 배열로 구현한다.
  - 마지막 위치에 새로운 노드를 추가하는 것이 연결리스트를 이용하는 방법으로는 어렵기 때문이다!

