#include <iostream>
#include <vector>
using namespace std;

//연결리스트를 여러개 만들어서 그래프를 표현하는 방법
const int V = 4;
vector<int> adj[V];

/*
 ! fad : holy 
 todo 
 * -n번째 인덱스에 삽입, 삭제: O(n)
 * -마지막 요소에 삽입, 삭제: O(1)
 * -특정요소 탐색: O(n)
 * -n번째 요소 참조: O(1)
 * 
 * 인접리스트 구현시 많이 사용되는 연산은 마지막 요소에 삽입과 해당 배열을 탐색하는 연산
 * 그래서 vector로 구현해도 무방
 */

int main(){

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(0);

    for(int i=0; i<4; i++){
        cout<<i<<" :: ";
        for(int next : adj[i]){
            cout<<next<<" ";
        }
        cout<<'\n';
    }

    cout<<'\n';

    //이렇게도 표현 가능
    for(int i=0; i<4; i++){
        cout<<i<<" :: ";
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}