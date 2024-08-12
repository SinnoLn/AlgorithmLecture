/*
 !  깊이우선 탐색 구현 방법은 2가지가 있다.
 *  구현방법 1. 돌다리를 두들겨보자 (특정 정점에서 특정 정점으로 갈때 방문되어 있나 확인하고 들어가는 방법)
 *  구현방법 2. 못먹어도 GO (방문했던 안했던 무조건 가는 방법)
 *  두 방법은 모두 암기해야한다!!!! 진자 중요하다!!!! 
*/

#include <iostream>
#include <vector>

using namespace std;

const int V = 6;
vector<int> adj[V];
int visited[V];

//만약 방문이 되어있다면(visited[there])이라면 방문을 하지 않고 방문이 안되어있다면 방문을 하는 코드
void dfs_1(int here){
    visited[here] = 1;
    for(int there : adj[here]){
        if(visited[there]) continue;
        dfs_1(there);
    }
}

//방문되어있던 안되어있던 무조건 dfs 호출. 해당 함수에서 만약에 방문되어있다면 return해 함수를 종료시키는 방법
void dfs_2(int here){ 
    if(visited[here]) return;
    visited[here] = 1;
    for(int there : adj[here]){
        dfs_2(there);
    }
}

int main()
{
    return 0;
}