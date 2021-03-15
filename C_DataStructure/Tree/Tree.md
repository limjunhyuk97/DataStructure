# [Tree](https://gmlwjd9405.github.io/2018/08/12/data-structure-tree.html)

## Tree 란?   

  - **계층적 관계**를 **표현**하는 **자료구조**이다.
  - 자료의 저장과 삭제, 추가가 중점이 되는 자료구조가 아니라, **자료의 위계를 표현하는 방식이 중점이 되는 자료구조**이다.
  - **트리 구조의 무언가를 표현하기에 트리가 적절하게 정의되어 있는가?** 가 핵심적인 고려사항이다.
   
## Tree 관련 용어정리   

  - **노드(node)**
  - **간선(edge)** : 노드를 연결하는 선
  - **루트 노드(root node)** : 부모가 없는 노드. 트리는 단 하나의 루트 노드만 갖는다.
  - **단말 노드(terminal node, leaf node)** : 자식이 없는 노드.
  - **내부 노드(nonterminal node, internal node)** : 노드 중 루트노드, 단말노드가 아닌 노드.
  - **부모(parent), 자식(child), 형제(sibling) 노드**
    - **부모 노드** : subtree 갖는 노드
    - **자식 노드** : 부모에 속하는 부속 노드
    - **형제 노드** : 같은 부모를 가지는 노드
  - **조상(ancestor), 후손(descendant)**
    - **조상** : 노드의 부모노드들의 총 집합
    - **후손** : 노드의 subtree에 있는 모든 노드들
  - **레벨(level), 높이(height)**
    - **레벨** : 루트 노드로 부터의 깊이. (루트노드 = 레벨 0)
    - **높이** : 트리에 속한 레벨의 최고 값.
  
## Tree의 종류   

  - **이진 트리 (binary-tree)**
    - **이진 트리의 조건 (재귀적)**
      - 루트 노드를 중심으로 두개의 서브 트리로 나뉘어진다.
      - 노드가 존재해야 하는 곳에 노드가 존재하지 않는다면 공집합 노드가 존재하는 것으로 간주한다. 공집합 노드도 노드로 인정한다!
      - 나뉘어진 두 서브 트리도 이진 트리이어야 한다.
    - **전 이진 트리 (Full binary-tree)**
      - every node has 0 or 2 childrens
    - **완전 이진 트리 (Complete binary-tree)**
      - all levels are completely filled (except possibly the last level)
      - if last level is not completely filled, the nodes in the last level are filled from left to right
    - **포화 이진 트리 (Perfect binary-tree)**
      - all internal nodes have 2 children
      - all leaves are at the same level
      - PBT이면, CBT, FBT이다. 
      - 
<img src="https://user-images.githubusercontent.com/59442344/111159501-81af9800-85dc-11eb-9b52-6190849f1036.jpg" height = "38%" width = "38%">
<img src="https://user-images.githubusercontent.com/59442344/111159504-81af9800-85dc-11eb-81ae-f2bd57b27683.jpg" height = "38%" width = "38%">
<img src="https://user-images.githubusercontent.com/59442344/111159507-82482e80-85dc-11eb-99bd-820491ca3282.jpg" height = "38%" width = "38%">
<img src="https://user-images.githubusercontent.com/59442344/111159495-807e6b00-85dc-11eb-92b0-097513dd796c.jpg" height = "38%" width = "38%">

  - **서브 트리 (sub-tree)**
    - 트리 내부에 속하는 작은 트리를 말한다.
  
  
