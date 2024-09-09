# BFS와 DFS 차이

## 문제에서 "퍼져나간다" "탐색한다" 이런 말이 있으경우 반드시 BFS 와 DFS가 생각나야함

### 한쪽은 깊이우선 탐색이고 한쪽은 너비우선 탐색이지만 둘 다 퍼져나가거나 탐색할 때 쓰이는건 똑같음

보통 "퍼져나간다" "탐색한다"라고 하면 DFS를 씀. 왜냐? 코드가 더 짧으니까.
그치만 최단거리를 구한다고 하면 "BFS"를 씀

DFS: 메모리를 덜 씀. 절단점 등 구할 수 있음. 코드가 짧으며 완전탐색의 경우 많이 씀
BFS: 메모리 더 씀(무조건 Queue가 필요하니까). 가중치가 같은 그래프 내에서 최단거리 구할 수 있음. 코드가 더 김

## 시간 복잡도는 둘다 큰 차이가 없음

- 인접리스트의 경우
  O(V+E)
- 인접행렬의 경우
  O(V^2)

### DFS

dfs(int here)
{
    if(visited[here]) return;
    visited[here] = 1;
    for(int there: adj[here]){
        dfs(there);
    }
}

### BFS

bfs(int here)
{
    queue<int> q;
    visited[here] = 1;
    q.push(here);
    while(q.size()){
        int here = q.front(); q.pop();
        for(int there: adj[here]){
            visited[there] = visited[here] + 1;
            q.push(there); 
        }
    }
}