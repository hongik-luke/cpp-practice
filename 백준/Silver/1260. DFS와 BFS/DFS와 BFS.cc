#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N,M,F;
vector <int> adj[1010];
bool visited[1010];
void input(){
    cin>>N>>M>>F;
    int n1,n2;
    for(int i  = 0 ; i < M ; i++){
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    for(int i  = 1 ; i <= N ; i++){
        sort(adj[i].begin(),adj[i].end());
    }
}
void DFS(int idx){
    visited[idx] = true;
    cout<<idx<<" ";
    for(int i = 0 ; i < adj[idx].size() ; i++){
        if(!visited[adj[idx][i]]) DFS(adj[idx][i]);
    }
    
}

void BFS(){
    visited[F] = true;
    queue<int> q;
    q.push(F);

    while(!q.empty()){
        int c = q.front();
        q.pop();
        cout<<c<<" ";
        for(int i = 0 ; i < adj[c].size() ; i++){
            if(!visited[adj[c][i]]){
                q.push(adj[c][i]);
                visited[adj[c][i]] = true;
            }
        }
    }
    
}
int main(void){
    input();
    memset(visited,false,sizeof(visited));
    DFS(F);
    cout<<"\n";
    memset(visited,false,sizeof(visited));
    BFS();
}