/*
 * 트위치 bj 랄로는 2400이란 숫자를 좋아한다.
 * 파카는 랄로의 수를 만들고자 하는데 랄로의 수란 2400이 들어간 수를 말한다.
 * 첫번재 랄로의 수는 2400이고 두번재 랄로의 수는 12400, 세번재 랄로의 수는 22400이다.
 * N이 입력으로 주어졌을 때 N번재 랄로의 수를 구하라
 * N은 300이하로 주어진다.
 */
#include <iostream>

using namespace std;
int n, cnt;
const int INF = 1e6; //10만 정도

int main() {
    cin >> n;
    int i =2400;

    //while문으로 돌리기
    while(true){ //무한루프
        string a = to_string(i);
        if(a.find("2400") != string::npos){ //a.find() 함수가 찾기를 실패하면 string::npos를 반환, 성공할경우 인덱스 번호 반환
            cnt++;
            if(n == cnt){
                cout<<a<<'\n';
                break;
            }
        }
        i++;
    }

    //for문으로 돌리기
    for(int i=2400; i<n; i++){
        string a = to_string(i);
        if(a.find("2400") != string::npos){ //a.find() 함수가 찾기를 실패하면 string::npos를 반환, 성공할경우 인덱스 번호 반환
            cnt++;
            cout<<a<<'\n';
        }
    }
    return 0;
}