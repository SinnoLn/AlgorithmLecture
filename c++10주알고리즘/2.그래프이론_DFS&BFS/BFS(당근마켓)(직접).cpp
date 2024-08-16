/*
*   BFS 예시문제 : 1
*   당근마켓 엔지니어 승원이
*   승원이는 당근을 좋아해서 당근마켓 엔지니어로 취업, 이때 당근차를 샀는데 
*   한칸 움직일때마다 당근을 내뿜으면서 간다. 즉, 한칸 움직일 때 "당근한개 소모"
*   승원이는 오늘도 아침 9시에 일어나 당근마켓으로 출근하고자 한다.
*   승원이는 최단거리로 당근마켓으로 향한다고 할때 당근 몇개를 소모해야 당근마켓으로 갈 수 있는지 알아보자.
*   이때 승원이는 육지로만 가고 바다는 못감. 상하좌우로만 갈 수 있음
*   1은 육지이며 0은 바다를 가리킨다. 
*
*   입력
*   맵의 세로길이 N과 가로길이 M이 주어지고 이어서 N * M 의 맵이 주어진다.
*   승원이의 위치(y,x)와 당근마켓의 위치(y,x)가 주어진다.
*   이때 승원이의 시작위치 (y,x)에서 이미 당근한개가 소모된 상태로 본다.
*
*   출력
*   당근을 몇개 소모해야 하는지 출력하라.
*
*   범위
*   1 <= N <= 100
*   1 <= M <= 100
*
*   예제입력
*   5 5   
*   0 0
*   4 4
*   1 0 1 0 1
*   1 1 1 0 1
*   0 0 1 1 1
*   0 0 1 1 1
*   0 0 1 1 1
*   
*   출력
*   9
*/

//일단 인접 리스트가 아니라 행렬인것 같음
#include <iostream>
#include <queue>
#include <tuple> 

using namespace std;

const int max_n = 104;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int n, m, a[max_n][max_n], visited[max_n][max_n], y, x, sy, sx, ey, ex;

int main() {
    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;
    
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> q;
    visited[sy][sx] = 1;
    q.push({sy, sx});
    while(q.size()){
        tie(y,x) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    //최단거리 디버깅
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<< visited[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}