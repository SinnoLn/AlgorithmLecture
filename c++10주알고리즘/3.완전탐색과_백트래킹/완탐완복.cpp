#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[4];
vector<int> v;

bool visited[4];
void print();
void go(int n);

int main() {
    adj[0].push_back(1); //A와 B연결
    adj[1].push_back(0);

    adj[1].push_back(2); //B와 C연결
    adj[2].push_back(1);

    adj[1].push_back(3); //C와 D연결
    adj[3].push_back(1);

    visited[0] = 1;
    v.push_back(0);
    go(0);
    return 0;
}

void go(int idx){
    if(v.size() == 3){ //3개의 정점 탐색 시 print
        print();
        return;
    }
    for(int there : adj[idx]){
        if(visited[there]) continue; //방문했으면 지나침
        visited[there] = 1;
        v.push_back(there);
        cout << "push_back :: there :" << there << '\n';
        for(int i : v) cout << i << " ";
        cout << '\n';
        go(there);
        visited[there] = 0;
        v.pop_back();
        cout << "pop_back :: there :" << there << '\n';
        for(int i : v) cout << i << " ";
        cout << '\n';
    }
}

void print() {
    //숫자를 문자로 바꾸어 출력
    for(int i : v) cout << char(i + 'A') << " ";
    cout << '\n';
}