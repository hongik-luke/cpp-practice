#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

struct pos{
    int ignore_cnt;
    int idx;
    int64_t value;
};
struct cmp{
    bool operator()(pos a, pos b){
        return a.value > b.value;
    }  
};
int N,M,K;
vector<pos> adj[10010];


void input(){
    cin>>N>>M>>K;
    int n1,n2;
    int64_t n3;
    pos npos;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        npos = {0,n2,n3};
        adj[n1].push_back(npos);
        npos = {0,n1,n3};
        adj[n2].push_back(npos);
    }
}
bool visited[22][10010];
int64_t getresult(){
    memset(visited,false,sizeof(visited));
    priority_queue<pos,vector<pos>,cmp> pq;
    pos cpos,npos;
    cpos = {0,1,0};
    pq.push(cpos);
    
    while(!pq.empty()){
        cpos = pq.top();
        pq.pop();
        //cout<<cpos.ignore_cnt<<" "<<cpos.idx<<" "<<cpos.value<<"\n";
        if(cpos.idx == N) return cpos.value;
        if(visited[cpos.ignore_cnt][cpos.idx]) continue;
        visited[cpos.ignore_cnt][cpos.idx] = true;
        
        for(int i = 0 ; i < adj[cpos.idx].size() ; i++){
            npos = {cpos.ignore_cnt, adj[cpos.idx][i].idx, cpos.value+(int64_t)adj[cpos.idx][i].value };
            if(!visited[cpos.ignore_cnt][adj[cpos.idx][i].idx]&& npos.ignore_cnt <= K){
                pq.push(npos);
            }
            
            npos = {cpos.ignore_cnt +1, adj[cpos.idx][i].idx, cpos.value};
            if(!visited[cpos.ignore_cnt][adj[cpos.idx][i].idx] && npos.ignore_cnt <= K){
                pq.push(npos);
            }
        }
    }
}


int main(void){
    input();
    cout<<getresult();
}