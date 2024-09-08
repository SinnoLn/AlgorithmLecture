/*
 ! 미로탐색 (백준 2178)
 
 ? 문제
 ? N×M크기의 배열로 표현되는 미로가 있다.
 ? 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
 ? 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 
 ? 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
 ? 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
 
 * 입력
   첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다.
   다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 
   각각의 수들은 붙어서 입력으로 주어진다.
 
 * 출력
   첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 
   항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
 
 * 예제입력 
   4 6
   101111
   101010
   101011
   111011

 * 예제출력
   15 
 
 * 예제입력2 
   4 6
   110110
   110110
   111111
   111101

 * 예제출력2
   9

 * 지나야 하는 최소 칸의 수 출력이므로 가중치가 1씩 더해짐. 그러므로 이건 BFS 인걸 할 수 있음 
 * 또한 이건 인접해 있으니까 인접 행렬이 맞는거 아닌가? 
 * 근데 일단 연속으로 입력하니 string으로 입력해야 함
 */

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int max_n = 104;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m, a[max_n][max_n], visited[max_n][max_n], y, x; 
char c;

int main() {

    cin >> n >> m;
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++) {
        cin >> c;
        a[i][j] = c - '0';
      }
    }

    queue<pair<int,int>> q;
    visited[0][0] = 1; //0,0 (문제상 1,1) 부터 시작하므로 방문했다고 표시
    q.push(make_pair(0,0));

    while(!q.empty()){
      tie(y,x) = q.front(); //여러 변수 한번에 초기화 방법
      q.pop();
      for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = visited[y][x] + 1;
        q.push(make_pair(ny, nx));
      }
    }

    // 최종적으로 (n-1, m-1) 위치에 있는 최소 칸 수 출력
    cout << visited[n-1][m-1] << '\n';

    return 0;
}
