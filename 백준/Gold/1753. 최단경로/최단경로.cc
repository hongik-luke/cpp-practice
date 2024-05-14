#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int firstidx, N, M;
vector<pair<int,int>> v[20010];
int visited[20010];

void input(){
    cin>>N>>M;
    cin>>firstidx;
    
    int n1,n2,n3;
    for(int i = 0; i < M ;i++){
        cin>>n1>>n2>>n3;
        v[n1].push_back(make_pair(n3,n2));
    }
    memset(visited,-1,sizeof(visited));
}


void getresult(){
    pair<int,int> c,n;
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,firstidx));

    while(!pq.empty()){
        c = pq.top();
        pq.pop();
        if(visited[c.second] != -1) continue;
        visited[c.second] = -c.first;
        
        for(int i = 0 ; i < v[c.second].size() ; i++){
            
            if(visited[v[c.second][i].second] != -1) continue;
            n.first = c.first-v[c.second][i].first;
            n.second = v[c.second][i].second;
            pq.push(n);
        }
    }
}


int main(void){
    input();
    getresult();
    for(int i = 1 ; i <= N ; i++){
        if(visited[i] != -1)cout<<visited[i]<<"\n";
        else cout<<"INF"<<"\n";
    }
}