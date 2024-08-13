/*
* BFS는 그래프를 탐색하는 알고리즘.
* 어떤 정점에서 시작해 다음 깊이의 정점으로 이동하기 전 현재 깊이의 모든 정점을 탐색하며, 방문한 정점은 다시 방문하지 않음
* 같은 가중치를 가진 그래프에서 최단거리 알고리즘으로 쓰임
* BFS로 탐색한다는 것은 이런식으로 레이어별, 레벨별로 탐색한다는 뜻.
* Layer 0 , Layer 1, Layer 2 .... 이런순으로 탐색을 진행함 
*/

/*
* 수도코드 1
* 시작점인 u를 방문처리 -> 큐에 push
* q.size()만큼 while반복문을 돌면서 큐 앞단에 있는 u를 다시 끄집어내어 그 u를 중심으로 인접한 노드들을 탐색
* 방문한 정점은 다시 방문하지 않고 방문처리를 하면서 queue에 푸시하며 방문처리를 함
*
* 
* BFS(G, u)
*     u.visited = true
*     q.push(u)
*     while(q.size())
*         u = q.front()
*         q.pop()
*         for each v G.Adj[u]
*             if v.visited == false
*                v.visited = true  -------------> 코드의 차이점
*                q.push(v)
*/

/*
* 수도코드 2
* 수도코드 1은 방문처리만을 위한 코드
* 하지만 보통 문제에서 BFS를 쓸 때에는 가중치가 같은 그래프 내에서 최단거리 알고리즘으로 쓰임
* 그러기 위해 "최단거리 배열"을 방문하면서 만들어주어야 하는데 다음과 같은 수도코드 사용
*
* 
* BFS(G, u)
*     u.visited = 1
*     q.push(u)
*     while(q.size())
*         u = q.front()
*         q.pop()
*         for each v G.Adj[u]
*             if v.visited == false
*                v.visited = u.visited + 1  ----------> 코드의 차이점
*                q.push(v)
*/

#include <iostream>
#include <queue>

using namespace std;

vector<int> adj[100];
int visited[100];
int nodeList[] = {10, 12, 14, 16, 18, 20, 22, 24};
void bfs(int here){
    for(int i=1; i <= 3; i++)
    {
        
    }
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while(q.size()){
        int here = q.front();
        q.pop();
        for(int there : adj[here]){
            if(visited[there]) continue; //방문한 정점은 지나치고
            visited[there] = visited[here] + 1; //방문하지 않은 정점은 +1 한다.
            q.push(there);
        }
    }
}

int main() {
    adj[10].push_back(12);
    adj[10].push_back(14);

    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[20].push_back(22);
    adj[20].push_back(24);
    bfs(10);
    for(int i : nodeList){
        cout << i << " : " << visited[i] << '\n';
    }
    //visited 배열의 24번째 요소를 출력하니 답이 나옴
    cout<< "10번으로부터 24번까지 최단거리는 : " << visited[24] - 1 << '\n'; 
    return 0;
}
