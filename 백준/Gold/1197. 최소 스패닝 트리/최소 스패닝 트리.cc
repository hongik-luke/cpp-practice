#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct pos{
    int value;
    int idx;
};
struct cmp{
    bool operator()(pos a , pos b){
        return a.value > b.value;
    }    
};

int V,E;
vector<pos> adj[10010];

void input(){
    cin>>V>>E;
    int n1,n2,n3;
    for(int i = 0 ; i < E ; i++){
        cin>>n1>>n2>>n3;
        pos newpos = {n3,n2};
        adj[n1].push_back(newpos);
        newpos = {n3,n1};
        adj[n2].push_back(newpos);
    }
}
int result = 0;
bool visited[10010];
void getresult(){
    memset(visited,false,sizeof(visited));
    
    priority_queue<pos,vector<pos>,cmp> pq;
    pos newpos,nowpos;
    nowpos = {0,1};
    pq.push(nowpos);
    
    while(!pq.empty()){
        nowpos = pq.top();
        pq.pop();
        
        if(visited[nowpos.idx]) continue;
        visited[nowpos.idx] = true;
        result += nowpos.value;
        
        for(int i = 0 ; i < adj[nowpos.idx].size() ;i++){
            if(visited[adj[nowpos.idx][i].idx]) continue;
            
            newpos = {adj[nowpos.idx][i].value, adj[nowpos.idx][i].idx};
            pq.push(newpos);
        }
    }
}
int main(void){
    input();    
    getresult();
    cout<<result;
}