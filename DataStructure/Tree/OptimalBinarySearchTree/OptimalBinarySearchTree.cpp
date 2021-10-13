// BST를 기반으로, BST에 존재하는 key들의 등장 빈도에 따라서 Optimal BST를 조직할 수 있다.

// 평균 검색 시간이 가장 적게 드는 트리를 조직하려고 한다.
// 평균 검색 시간 : (단어별 검색 빈도) * (단어 찾기까지 필요한 비교연산 횟수)의 총합
//  - 검색 빈도가 높을수록 위로, 검색 빈도가 낮을수록 아래로 내려가 있어야 한다.
//  - 이런 원리롤 조직하여, 평균 검색 시간이 가장 작은, 가장 효율적인 트리를 최적 이진 탐색 트리라고 함.

// Optimal Binary Search Tree 조직
//   - 입력
//     - sorted Array A[1 ... n]
//     - probability p[1 ... n]
//   - 출력
//     - optimal average search time
//     - R[][] : i번째 - j번째 수들로 optBST를 형성할 때의 root 값으로 사용될 수의 위치를 저장.
//   - 방식
//     - DP[][] : 최적의 평균 탐색 시간을 저장
//     - DP를 이용하여 i번째부터 j번째까지의 key들을 이용하여 tree를 조직했을 때, 탐색에 소요되는 시간 평균의 최소가 얼마인지 찾는다.
//     - recurrence relation을 결정한다.
//       - DP[i][j] : i 부터 j 번째 수들을 이용하여 tree를 조직할 때
//       - DP[i][j] = min(DP[i][k-1] + DP[k+1][j]) + (p[i] + p[i+1] + .. + p[j]) : i 부터 j 까지 k값 바꾸변서 시행했을 때 최소
//         - DP[i][k-1] : 루트 노드 기준, 왼쪽 서브트리의 최적 평균 탐색 시간
//         - DP[k+1][j] : 루트 노드 기준, 오른쪽 서브트리의 최적 평균 탐색 시간
//         - p[i] + ... + p[j] : 루트 노드 탐색 시간 (i번째 부터 j번째 사이의 수가 root일 수 있는데, 이때 root 탐색에 소요되는 시간 : 다 더해봤자 1이 안넘는다. 평균.)
//       - DP[k+1][k] = 0
//       - DP[k][k] = p[k]
//     - R[][] : 최적의 평균 탐색 시간 만족할 때의 root 값 위치 저장.


#include <iostream>
#include <string>
#define INF 2e8
using namespace std;

typedef string Data;

struct node{
    Data data;
    node *lnode;
    node *rnode;
};

int R[15][15];

// p는 index 1의 값부터 n의 값까지, 1번째 요소부터 n번째 요소까지의 등장확률에 대한 정보를 갖는다고 한다면
double optimalBST(int n, double p[]){
   
    double DP[15][15];
    
    for(int i=1; i<=n; ++i){
        DP[i][i-1] = 0;
        DP[i][i] = p[i];
        R[i][i] = i;
        R[i][i-1] =0;
    }
    DP[n+1][n] = 0;
    R[n+1][n] = 0;
    
    // diagoanl 은 i와 j의 차이 값이다.
    for(int diagonal = 1; diagonal <= n-1; ++diagonal){
        // i를 1 부터, n - diagonal 만큼 돌린다.
        for(int i = 1; i <= n - diagonal; ++i){
            int j = i + diagonal, k_loc = 0;
            double minval = INF;
            // k_loc에 최적 평균값을 갖게 하는 root에 들어갈 요소 위치값을 넣는다.
            // minval에 DP[i][j] 에 들어갈, i 부터 j 까지의 최소 평균 탐색 소요시간 값을 넣는다.
            for(int k=i; k<=j; ++k){
                if(minval > DP[i][k-1] + DP[k+1][j]){
                    minval = DP[i][k-1] + DP[k+1][j];
                    k_loc = k;
                }
            }
            // R[i][j] 에 root에 들어갈 요소 위치값을 넣는다.
            R[i][j] = k_loc;
            // DP[i][j] 에 들어갈 root 노드 탐색 평균 소요시간 값을 구하기 위해 p[i] 부터 p[j]까지 더한다.
            double sum = p[i];
            for(int k=i+1; k<=j; ++k) sum += p[k];
            // DP[i][j] 에 둘어갈 i부터 j까지의 요소로 만든 tree의 최소 평균 탐색 시간 값을 넣는다.
            DP[i][j] = minval + sum;
        }
    }
    
    return DP[1][n];
}

// R 배열 안에 저장된 정보를 토대로 root 지정, left, right 지정을 recursive하게 진행한다.
node* make_optBST(int i, int j, const string contents[]){
    if (R[i][j] == 0) return NULL;
    
    node *newNode = new node;
    newNode->data = contents[R[i][j]];
    newNode->lnode = make_optBST(i, R[i][j] - 1, contents);
    newNode->rnode = make_optBST(R[i][j] + 1, j, contents);
    return newNode;
}

int main(void){
    
    string contents[5] = {"", "lim", "jack", "adolph", "jasmin"};
    double probability[5] = {0, 0.1, 0.2, 0.4, 0.3};
    
    optimalBST(4, probability);
    make_optBST(1, 4, contents);
    
    for(int i=1; i<=5; ++i){
        for(int j=1; j<=5; ++j){
            cout << R[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
