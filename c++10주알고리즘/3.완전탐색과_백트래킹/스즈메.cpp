/*
 * 승철이는 도쿄 위의 빨간 구름위에 올라가 있다.
 * 이 구름을 그대로 내버려두면 땅으로 떨어져 100만명의 사상자가 발생한다.
 * 구름을 멈추는 방법은 구름의 특정 위치에 요석을 꽂으면 된다.
 * 해당 위치에는 숫자가 표기가 되어있고 몇 개를 골라 숫자의 합이 "소수"가 될 때 구름은 멈춘다.
 * 총 몇 개의 경우의 수가 있는지 말하라
 
 ? N개의 요석 후보의 숫자와 다음 줄에 해당 숫자들이 나온다.
 ? N <= 100

 TODO
 Input 1 
 * 10
 * 24 35 38 40 49 59 60 67 83 98
 
 ! 2*n으로 접근해야함
 ? O(2^10) = 1024 최대로는 1억정도까지 브루트포스로 풀 수 있을듯
 ? 26까지가 6천만 정도고 27은 1억 넘음
*/
#include <iostream>
#include <vector>
using namespace std;

int go(int idx, int sum);
bool check_(int n);
int n, temp;
vector<int> v;

int main(){

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        v.push_back(temp);
    }

    cout << go(0,0) << '\n';

    return 0;
}

//재귀적 부분집합 생성
int go(int idx, int sum){
    //제귀함수의 기저사례
    if(idx == n){ 
        //cout << "SUM" << sum << '\n';
        return check_(sum);
    }
    //선택하거나 선택하지 않는다.
    return go(idx + 1, sum + v[idx]) + go(idx + 1, sum); //순서대로 완전탐색
}

//주어진 정수 n이 소수인지 판별
bool check_(int n){
    if(n <= 1) return 0; //소수는 2 이상부터
    if(n == 2) return 1; //2는 소수
    if(n%2 == 0) return 0; //2으로 나눠지면 소수가 아님
    for(int i =2; i * i <= n; i++){
        if (n % i == 0) return 0; //모듈러 연산시 배수면 소수가 아님
    }
    return 1; // 다 무시되면 소수가 맞음
}