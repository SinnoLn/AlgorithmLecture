/*
 ! 영역구하기 (백준 2583)
 
 ? 문제
 ? 눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다.
 ? 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
 ? 예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 
 ? 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.
 ? <그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.
 ? M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, 
 ? K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 
 ? 그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.

 
 * 입력
   첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. 
   M, N, K는 모두 100 이하의 자연수이다. 
   둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다.
   모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 
   입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.
 
 * 출력
   첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다.
   둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다.
  
 
 * 예제입력 
  5 7 3
  0 2 4 4 
  1 1 2 5 
  4 0 6 2

 * 예제출력
   3
   1 7 13
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_NUM 100

using namespace std;
int n, m, k, x, y, ny, nx, fx, fy, ex, ey,sum, rs;
int a[MAX_NUM][MAX_NUM] = {0,};
bool visited[MAX_NUM][MAX_NUM];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
vector<int> ret;
//0이 디폴트고 1이 사각형으로 채워지는 부분

void dfs(int y, int x);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n >> k;
    for(int i=0; i<k; i++){
        cin >> fx >> fy >> ex >> ey;
        for(int x=fx; x<ex; x++)
            for(int y=fy; y<ey; y++)
                a[y][x] = 1; //주의!!!!!! 뒤집어서 해야함!!!!!
    }
    
    for(int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++) {
            if (a[y][x] == 0 && !visited[y][x]) {
                sum = 0;
                dfs(y, x); 
                rs ++;
                ret.push_back(sum);
            }
        }
    }
    
    sort(ret.begin(), ret.end());
    
    cout << rs << '\n';
    for(int i=0; i<ret.size(); i++)
    {
        cout << ret[i]<<" ";
    }
    
    return 0;
}

void dfs(int y, int x){
    visited[y][x] = 1; //방문처리
    sum++;
    for(int i=0; i<4; i++) {
        ny = y + dy[i];
        nx = x + dx[i];
        if(ny<0 || nx<0 || ny >= m || nx >= n) continue; //인접행렬 범위안에 있는지
        if (a[ny][nx] == 0 && !visited[ny][nx]) { //지나갈 수 있고 방문안했으면 dfs go
            dfs(ny, nx);
        }
    }
}