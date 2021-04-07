## 향상된 Heap의 구현
  - 사용자가 제시한 **data와, data의 우선순위 판단기준을 받아들이는 Heap**의 구현
  - 코드 상으로 무엇이 향상되었나?

```c
// 1. Heap 구조에 대한 struct 묶음이 변경되었다.
// 우선순위 비교의 기준을 사용자가 입력해줄 수 있는 PriorityComp라는 함수 포인터가 들어가 있다.
typedef int (*PriorityComp)(HData , HData);

typedef struct Heap{
  HData heapArr[MAX_HEAP_LEN];
  PriorityComp comp;
  int numOfData;
}Heap;

// 2. Heap을 다루는 함수들의 내용(매개인자, 함수 내 구현 부분의 코드들)이 달라졌다.
```
