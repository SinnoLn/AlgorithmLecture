#include <iostream>

using namespace std;

//행렬은 현재 10*10
const int v = 10;

//2차원 배열 기반으로 그래프를 표현 
bool a[v][v], visited[v];

void go(int from){
    
    visited[from] = 1; //이제 방문하니까 1로 변경
    cout<< from << " ";

    for(int i = 0; i<v; i++){  //일단 0부터 계속 도는데
        if(visited[i]) continue; //방문했으면 지나가고
        if(a[from][i]){ //방문하지 않았다면 dfs(깊이 우선 탐색)
            go(i); //dfs
        }
    }
    return;
}

int main() {

    //무방향으로 연결된 노드
    a[1][2] = 1; a[1][3] = 1; a[3][4] =1;
    a[2][1] = 1; a[3][1] = 1; a[4][3] =1;

   //인접행렬은 이중포문 씀
    for(int i=0; i<v; i++)
    {
    for(int j=0; j<v; j++){
        if(a[i][j] && visited[i] == 0) {
            go(i);
            }
        }
    }
    return 0;
}