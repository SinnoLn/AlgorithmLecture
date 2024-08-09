#include <iostream>
#include <vector>

using namespace std;
const int V = 10; //노드 수 
bool visited[V];
vector<int> adj[V];
//1-2 1-3 3-4 연결, 무방향 연결리스트

void go(int node){
    visited[node] = true; //방문했다고 표시
    cout<<node<<" ";

    for(int next : adj[node]) {
        if(!visited[next]){
            go(next);
        }
    }
}

int main(){

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);    

    for(int i=0; i<V; i++)
    {
        if(!visited[i] && !adj[i].empty())
        {
            go(i);
        }
    }
    return 0;
}
