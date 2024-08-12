
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

const int V = 6;
vector<int>adj[V]; //그래프 연결
int visited[V]; // 방문했는지 확인

void dfs(int n) //전역변수로 설정해놔서 넣을필요 없음
{
    visited[n] = 1;
    cout<< n <<'\n';
    for(int j: adj[n])
    {
        if(visited[j] == 0) //아직 방문하지 않았다면
        dfs(j);
    }
    cout<< n << "로부터 시작된 함수가 종료되었습니다.\n";
    return;
}

int main() {

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(4);
    adj[2].push_back(5);
    adj[4].push_back(2);

    dfs(1); //1부터 깊이우선 탐색 시작 (노드가 1부터 시작하니까)

    return 0;
}