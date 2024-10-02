/*
 * 완전탐색 & 백트래킹을 이용하여 2차원 배열의 모든 경로를 탐색하는 문제
 */

#include <iostream>   // 표준 입출력 사용을 위한 헤더 파일 포함
#include <vector>     // 벡터 자료구조 사용을 위한 헤더 파일 포함
#define NUM 3         // 배열의 크기를 정의 (3x3 배열)

using namespace std;

// 3x3 2차원 배열 초기화
int a[NUM][NUM] = {
    {10, 20, 21},
    {70, 90, 12},
    {80, 110, 120}
};

// 각 위치의 방문 여부를 저장하는 2차원 배열
bool visited[NUM][NUM];

// 상하좌우 이동을 위한 방향 배열 (y 좌표 변화량)
const int dy[] = {-1, 0, 1, 0};
// 상하좌우 이동을 위한 방향 배열 (x 좌표 변화량)
const int dx[] = {0, 1, 0, -1};

// 현재까지 이동한 경로의 값을 저장하는 벡터
vector<int> v;

// 배열의 크기를 저장하는 변수 n (NUM으로 초기화)
int n = NUM;

// 경로를 출력하는 함수 선언
void print();

// 재귀적으로 경로를 탐색하는 함수 선언
void go(int y, int x);

int main(){
    visited[0][0] = true;      // 시작 위치 (0, 0)을 방문했다고 표시
    v.push_back(a[0][0]);      // 시작 위치의 값을 경로 벡터에 추가
    go(0, 0);                  // (0, 0)에서 탐색 시작
    return 0;                  // 프로그램 종료
}

// 현재까지의 경로를 출력하는 함수
void print() {
    for(int i : v)             // 경로 벡터 v의 모든 원소에 대해
        cout << i << " ";      // 원소 값을 출력하고 공백 추가
    cout << '\n';              // 한 경로의 출력이 끝나면 줄바꿈
}

// 재귀적으로 경로를 탐색하는 함수
void go(int y, int x){
    // 기저 사례: 도착 지점에 도달한 경우 (배열의 마지막 위치)
    if(y == n - 1 && x == n - 1){
        print();               // 현재까지의 경로를 출력
        return;                // 함수 종료 (재귀 반환)
    }
    // 네 가지 방향으로 이동 시도 (상하좌우)
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];    // 새로운 y 좌표 계산
        int nx = x + dx[i];    // 새로운 x 좌표 계산
        // 배열 범위를 벗어나는지 확인
        if(ny < 0 || nx < 0 || ny >= n || nx >= n)
            continue;          // 범위를 벗어나면 다음 방향으로
        // 이미 방문한 위치인지 확인
        if(visited[ny][nx])
            continue;          // 방문한 위치면 다음 방향으로
        // 방문 표시 및 경로에 현재 위치의 값 추가
        visited[ny][nx] = true;
        v.push_back(a[ny][nx]);
        go(ny, nx);            // 다음 위치로 이동하여 재귀 호출
        // 백트래킹: 방문 표시 해제 및 경로에서 현재 위치의 값 제거
        visited[ny][nx] = false;
        v.pop_back();
    }
}