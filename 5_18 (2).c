#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
struct pos{
    int idx;
    int64_t value;
};
struct cmp{
    bool operator()(pos a , pos b){
        return a.value > b.value;
    }  
};

int N,M,K;
vector<pos> adj[100010];
vector<int> testplace;

void input(){
    cin>>N>>M>>K;
    pos npos;
    int n1,n2,n3;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        npos = {n1,n3};
        adj[n2].push_back(npos);
    }
    for(int i = 0 ; i < K ; i++){
        cin>>n1;
        testplace.push_back(n1);
    }
    
}
bool visited[100010];
void daikstra(){
    memset(visited,false,sizeof(visited));
    
    pos cpos,npos;
    priority_queue <pos,vector<pos>,cmp> pq;
    
    int64_t last_value = 0;
    vector<int64_t> forresult;
    for(int i = 0 ; i < testplace.size() ; i++){
        cpos = {testplace[i],0};
        pq.push(cpos);
    }
    
    while(!pq.empty()){
        cpos = pq.top();
        pq.pop();
        if(visited[cpos.idx]) continue;
        visited[cpos.idx] = true;
        
        if(cpos.value > last_value){
            forresult.clear();
            last_value = cpos.value;
        }
        forresult.push_back(cpos.idx);
        
        for(int i = 0 ; i < adj[cpos.idx].size() ; i++){
            if(visited[adj[cpos.idx][i].idx]) continue;
            
            npos = {adj[cpos.idx][i].idx, adj[cpos.idx][i].value + cpos.value};
            pq.push(npos);
            
        }
    }
    
    sort(forresult.begin(),forresult.end());
    cout<<forresult[0]<<"\n"<<last_value;
}

int main(void){
    input();
    daikstra();
}

