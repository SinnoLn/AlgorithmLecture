/*
*   DFS 예시문제 : 1
*   코로나 바이러스
*   종화는 코로나 바이러스에 감염되었다. 종화는 현재 배를 타고 한국으로 돌아오고 있었고, 
*   종화가 육지에 발을 디딛는 순간 종화와 연결된 육지는 모두 코로나 바이러스가 퍼진다. 
*   (바다에서는 코로나 바이러스가 퍼지지 않는다.)
*   이때 종화가 최소한 몇 번 이동해야 모든 육지에 코로나 바이러스를 퍼트릴 수 있는지 말해보자 
*   1은 육지이며 0은 바다를 가리킨다. 
*
*   입력
*   맵의 세로길이 N과 가로길이 M이 주어지고 이어서 N * M 의 맵이 주어진다.
*
*   출력
*   종화가 최소 몇 번 이동해야 모든 육지에 코로나 바이러스가 퍼지는지 출력해라 (4아닌가)
*
*   범위
*   1 <= N <= 100
*   1 <= M <= 100
*
*   예제입력
*   5 5   
*   1 0 1 0 1
*   1 1 0 0 1
*   0 0 0 1 1
*   0 0 0 1 1
*   0 1 0 0 0
*   
*   출력
*   4 
*/
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int m, n, k, y, x, ret, ny, nx, t;
int a[104][104]; //꼭 104일 필요는 없고 그냥 공간을 넓게 만든것
bool visited[104][104];

//인접리스트는 일차원이지만 이건 인접행렬이므로 2차원으로 변수를 받는다.
void dfs(int y, int x){
    visited[y][x] = 1;
    cout << y << " : " << x << '\n';
    for(int i=0; i<4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny<0 || nx<0 || ny >=n || nx >= m) continue;
        if(a[ny][nx] == 1 && !visited[ny][nx]) { //지나갈 수 있고, 방문을 아직 안했다면
            dfs(ny, nx);
        }
    }
    return;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    
    //행렬 구조 입력
    for(int i = 0; i < n; i++) {
        for(int j =0; j<m; j++){
            cin >> a[i][j];
        }
    }

    //인접행렬이니까 이중 포문 사용
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == 1 && !visited[i][j]){ //지나갈 수 있고, 방문을 아직 안했다면
                dfs(i , j); //깊이 우선 탐색 dfs 호출
                ret++; //횟수를 증가시킴
                cout << i << " : " << j << '\n';
                cout << ret << " : " << "dfr가 시작됩니다.\n";
            }
        }
    }

    cout << "answer : " << ret <<'\n';

    return 0;
}

