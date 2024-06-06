#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int,int> pos;
int f,l;
int max__road = 1000000000;
vector<pos> adj[10010]; // 앞 거리 , 뒤 갈곳
int N,M;
void input(){
    cin>>N>>M;
    int n1,n2,n3;
    pos a;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        adj[n1].push_back(make_pair(n3,n2));
        adj[n2].push_back(make_pair(n3,n1));
    }
    cin>>f>>l;
}
struct cmp{
    bool operator()(pos a , pos b){
        return a.first < b.first;
    }
};
bool visited[100010];
void get(){
    memset(visited,false,sizeof(visited));
    pos c,n;
    priority_queue<pos,vector<pos>,cmp>pq;
    c = make_pair(1000000000,f);
    pq.push(c);
    while(!pq.empty()){
        c = pq.top();
        pq.pop();
        if(visited[c.second]) continue;
        max__road = min(max__road,c.first);
        visited[c.second] = true;
        if(c.second == l) return;
        
        for(int i = 0 ; i < adj[c.second].size() ; i++){
            if(visited[adj[c.second][i].second]) continue;
            pq.push(adj[c.second][i]);
        }
    }
    
}

int main(void){
    input();
    get();
    cout<<max__road;
}
