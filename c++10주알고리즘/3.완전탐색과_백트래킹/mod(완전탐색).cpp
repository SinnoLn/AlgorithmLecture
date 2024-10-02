/*
! 재귀함수를 이용한 완전탐색
* N과 N개의 자연수가 주어진다.
* 여기서 몇개의 숫자를 골라 합을 mod 11 했을때 나오는 가장 큰 수를 구하라

TODO
Input 1
* 10
* 24 35 38 49 59 60 67 83 98
? O(2*10) = 1024
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//만약 ret이 최소를 구하라고 한다면 최대로 세팅 
int n, temp, ret, cnt; //ret은 최대를 구하고 범위가 자연수이므로 0으로 세팅하며 답의 범위와 안겹치게 해야 한다.
const int mod = 11;
vector<int> v;
void go(int idx, int sum);
bool check_(int n);

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }
    go(0,0); //1024번 탐색됨
    cout << ret << "\n";
    cout << cnt << "\n";
    return 0;
}

//재귀함수 
void go(int idx, int sum){
    //기저사레
    if(idx == n){
        ret = max(ret, sum % mod); //최대 구할때는 최소로, 최소 구할때는 최대로, 문제의 범위에 겹치치않게 세팅이 중요!
        cnt++;
        return;
    }
    go(idx + 1, sum + v[idx]); //현재 숫자를 선택하는 경우
    go(idx + 1, sum); //현재 숫자를 선택하지 않는 경우
}