
/*
* DFS는 그래프를 탐색할 때 쓰는 알고리즘. 
* 어떤 노드부터 시작해 인접한 노드들을 재귀적으로 방문, 방문한 정점은 다시 방문하지 않음
* 각 분기마다 가능한 가장 멀리 있는 노드까지 탐색하는 알고리즘
*/

/*
* 수도코드 
* 
* DFS(u, adj)
*     u.visited = true
*     for each v adj[u]
*           if v.visited == false
*               DFS(v, adj)
*/

#include <iostream>
#include <vector>

using namespace std;

const int n = 6; //총 노드수 6개
vector<int> adj[n]; //인접리스트로 구현
int visited[n]; //방문했는지 체크

//깊이우선 탐색
void dfs(int u){
    visited[u] = 1;
    cout<<u<<'\n';

    for(int v : adj[u]){
        if(visited[v] == 0){ //방문하지 않았다면
            dfs(v);
        }
    }
    cout<< u << "로부터 시작된 함수가 종료되었습니다.\n";
    return ;
}

int main() {
    //각 간선 연결
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[4].push_back(2);
    adj[2].push_back(5);
    dfs(1);
}

/*
 ! OUTPUT
 *  1
 *  2
 *  4
 *  4로부터 시작된 함수가 종료되었습니다.
 *  5
 *  5로부터 시작된 함수가 종료되었습니다.
 *  2로부터 시작된 함수가 종료되었습니다.
 *  3
 *  3로부터 시작된 함수가 종료되었습니다.
 *  1로부터 시작된 함수가 종료되었습니다.
*/