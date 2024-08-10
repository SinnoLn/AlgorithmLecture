/*
* Q3. 3*3 맵을 입력받는다. 이 맵은 1과 0으로 이루어져 있고 {0,0}은 무조건 1임을 보장한다.
*{0,0}부터 4방향을 기준으로 한칸씩 탐색해나가며 방문한 정점은 다시 방문하지 않으며 방문하는 좌표를 출력하는 코드.
*0은 갈 수 없는 지역, 1은 갈 수 있는 지역을 구현하시오.
*/

/*
* 1 0 1
* 1 0 1
* 0 1 1
*/

#include <iostream>

using namespace std;
const int n = 3;

int a[n][n], visited[n][n]; //map이니까 인접행렬로 구현

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

void go(int y, int x)
{
    visited[y][x] = 1;
    cout << y << " : " << x << "\n";

    for(int i=0; i<4; i++) //4방향으로 탐색
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        //맵이므로 범위 안에 존재하는지 반드시 파악

        /*
        * 정답에 있던 if문
        ! 순서를 맨 앞에 둬야만 방지 가능 
        ! if(ny < 0 || ny > n || nx < 0 || nx >= n) continue; //맵의 범위를 벗어났으면 pass (overflow, underflow 방지용 코드)
        * if(a[ny][nx] == 0) continue; //이동 가능한 위치가 아니라면 pass
        * if(visited[ny][nx]) continue; //방문했으면 pass
        */
        if((ny>=0 && ny<n && nx>= 0 && nx < n) && !visited[ny][nx] && a[ny][nx] == 1) //내가 구현한 코드
            go(ny, nx);
    }
}

int main () {

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    go(0, 0); //0,0부터 탐색 시작
    return 0;
}