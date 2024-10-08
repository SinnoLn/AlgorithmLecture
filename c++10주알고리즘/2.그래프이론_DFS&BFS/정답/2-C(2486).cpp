/*
 ! 안전 영역 (백준 2468)
 
 ? 문제
 ? 재난방재청에서는 많은 비가 내리는 장마철에 대비해서 다음과 같은 일을 계획하고 있다.
 ? 먼저 어떤 지역의 높이 정보를 파악한다. 
 ? 그 다음에 그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이 최대로 몇 개가 만들어 지는 지를 조사하려고 한다.
 ? 이때, 문제를 간단하게 하기 위하여, 장마철에 내리는 비의 양에 따라 일정한 높이 이하의 모든 지점은 물에 잠긴다고 가정한다.
 ? 어떤 지역의 높이 정보는 행과 열의 크기가 각각 N인 2차원 배열 형태로 주어지며 배열의 각 원소는 해당 지점의 높이를 표시하는 자연수이다.
 ? 예를 들어, 다음은 N=5인 지역의 높이 정보이다.
 
 * 입력
   첫째 줄에는 어떤 지역을 나타내는 2차원 배열의 행과 열의 개수를 나타내는 수 N이 입력된다. 
   N은 2 이상 100 이하의 정수이다. 
   둘째 줄부터 N개의 각 줄에는 2차원 배열의 첫 번째 행부터 N번째 행까지 순서대로 한 행씩 높이 정보가 입력된다.
   각 줄에는 각 행의 첫 번째 열부터 N번째 열까지 N개의 높이 정보를 나타내는 자연수가 빈 칸을 사이에 두고 입력된다. 
  ! 높이는 1이상 100 이하의 정수이다.  비의 분량은 1이상 100이하라고 했지만 
  ? 아무 지역도 물에 잠기지 않을 수 있다고 했으므로 그걸 고려하지 않으면 틀리게 된다.
  ? 참고로 내가 그래서 틀림
  ? 정말 왜틀렸는지 모르겠다 시벌 
 
 * 출력
   첫째 줄에 장마철에 물에 잠기지 않는 안전한 영역의 최대 개수를 출력한다.
  
 ! 아무 지역도 물에 잠기지 않을 수 있다
 
 * 예제입력 
  5
  6 8 2 6 2
  3 2 3 4 6
  6 7 3 3 2
  7 2 5 3 6
  8 9 5 2 7

 * 예제출력
   5
 
 * 예제입력2 
  7
  9 9 9 9 9 9 9
  9 2 1 2 1 2 9
  9 1 8 7 8 1 9
  9 2 7 9 7 2 9
  9 1 8 7 8 1 9
  9 2 1 2 1 2 9
  9 9 9 9 9 9 9

 * 예제출력2
   6
*/

/*
! 반례를 생각하는 방법
? 범위를 보고 최소, 최대 체크
? 없거나, 있거나 체크
! 변수명을 통일하자!
? 방향벡터를 사용할때는 dy, dx를 사용하자
? 또한 y, x로 뻗어나가는 벡터들은
? ny, nx를 사용하자
? 어떤거를 카운팅할 경우 cnt를 사용하자
? 결과물을 뽑고싶다면 ret를 사용하자
? 최대값은 mx, 최소값은 mn
*/

#include <iostream>

using namespace std;
int a[101][101], visited[101][101], n, temp, ret = 1;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, int d){
  visited[y][x] = 1;
  for(int i = 0; i<4; i++){
    int ny = y+dy[i];
    int nx = x+dx[i];
    if(ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
    if(!visited[ny][nx] && a[ny][nx] > d) dfs(ny, nx, d);
  }
  return;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cin >> a[i][j];
    }
  }
  for(int d=1; d<101; d++){
    fill(&visited[0][0], &visited[0][0] + 101*101, 0); //이게 뭔코드지
    int cnt = 0;
    for(int i = 0; i<n; i++){
      for(int j=0; j<n; j++){
        if(a[i][j] > d && !visited[i][j]) {
          dfs(i, j, d);
          cnt++;
        }
      }
    }
    ret = max(ret,cnt);
  }
  cout << ret << '\n';
  return 0;
}
