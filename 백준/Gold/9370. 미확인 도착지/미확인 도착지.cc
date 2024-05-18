//최단경로가 여러개
#include <iostream>
#include <algorithm>
#include <cstring>

#include <vector>
#include <queue>
using namespace std;
const int IMF = 987654321;

struct pos{
    int value;
    int idx;
};

int  N,M,T,S,G,H;
int G_Hdistance;
vector<pos> adj[2020];
vector<int> dest_can;
void input(){
    dest_can.clear();
    for(int i = 0 ; i < 2020 ; i++)
        adj[i].clear();
    
    cin>>N>>M>>T>>S>>G>>H;

    int n1,n2,n3;
    pos newpos;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        if(n1 == G && n2 == H) G_Hdistance = n3;
        if(n2 == G && n1 == H) G_Hdistance = n3;
        newpos = {n3,n2};
        adj[n1].push_back(newpos);
        newpos = {n3,n1};
        adj[n2].push_back(newpos);
    }
    for(int i = 0 ; i < T ; i++){
        cin>>n1;
        dest_can.push_back(n1);
    }
}


struct cmp{
    bool operator()(pos a ,pos b){
        return a.value > b.value;
    }
};

bool checking[2020];
int daikstra(int startidx,int lastidx){
    memset(checking,false,sizeof(checking));
    
    pos cpos,npos;
    cpos = {0,startidx};
    priority_queue <pos,vector<pos>,cmp> pq;
    pq.push(cpos);

    while(!pq.empty()){
        cpos = pq.top();
        pq.pop();
        
        if(cpos.idx == lastidx) return cpos.value;
        if(checking[cpos.idx]) continue;
        checking[cpos.idx] = true;
        
        //cout<<cpos.value<<" "<<cpos.idx<<" "<<cpos.beforeidx<<"\n";
        for(int i = 0 ; i < adj[cpos.idx].size() ; i++){
            if(checking[adj[cpos.idx][i].idx]) continue;
            npos = {adj[cpos.idx][i].value+cpos.value, adj[cpos.idx][i].idx};
            
            pq.push(npos);
        }
    }
    return IMF;
}
vector<int> print_result;
int main(void){
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ; i++){
        input();
        print_result.clear();
        for(int i = 0 ; i < dest_can.size() ; i++){
            int corret_answer = daikstra(S,dest_can[i]);
            if(corret_answer >= IMF) continue;
            
            int answer1 = daikstra(S,H) + G_Hdistance + daikstra(G,dest_can[i]);
            int answer2 = daikstra(S,G) + G_Hdistance + daikstra(H,dest_can[i]);
            int answer = min(answer1,answer2);
            if(answer >= IMF) continue;
            
            if(corret_answer == answer) print_result.push_back(dest_can[i]);
        }
        
        sort(print_result.begin(),print_result.end());
        for(int i = 0 ; i < print_result.size() ; i++)
            cout<<print_result[i]<<" ";
        cout<<"\n";
    }
}