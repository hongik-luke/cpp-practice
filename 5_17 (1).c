//최단경로가 여러개
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

int  N,M,T,S,G,H;

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

struct up_pos{
    int value;
    int idx;
    int beforeidx;
};
struct cmp{
    bool operator()(up_pos a ,up_pos b){
        return a.value > b.value;
    }
};

vector<int> daikstra_arr[2020];
bool checking[2020];

void make_daikstra(int startidx){
    memset(checking,false,sizeof(checking));
    for(int i = 0 ; i < 2020 ; i++)
        daikstra_arr[i].clear();
    
    up_pos cpos,npos;
    cpos = {0,startidx,0};
    priority_queue <up_pos,vector<up_pos>,cmp> pq;
    pq.push(cpos);

    while(!pq.empty()){
        cpos = pq.top();
        pq.pop();
        
        if(checking[cpos.idx]) continue;
        checking[cpos.idx] = true;
        daikstra_arr[cpos.beforeidx].push_back(cpos.idx);
        //cout<<cpos.value<<" "<<cpos.idx<<" "<<cpos.beforeidx<<"\n";
        for(int i = 0 ; i < adj[cpos.idx].size() ; i++){
            if(checking[adj[cpos.idx][i].idx]) continue;
            npos = {adj[cpos.idx][i].value+cpos.value, adj[cpos.idx][i].idx,cpos.idx};
            
            pq.push(npos);
        }
    }
}

vector<int> daikstra_result;
vector<int> print_result;
int main(void){
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ; i++){
        input();
        make_daikstra(S);

        bool g_first = false;
        for(int i = 0 ; i < daikstra_arr[G].size() ; i++){
            if(daikstra_arr[G][i] == H) g_first = true;
        }
        queue <int> pq;
            int now;
        if(g_first)
            pq.push(H);
        else
            pq.push(G);
        while(!pq.empty()){
            now = pq.front();
            pq.pop();
            daikstra_result.push_back(now);
            for(int i = 0 ; i < daikstra_arr[now].size(); i++)
                pq.push(daikstra_arr[now][i]);
        }
        for(int i = 0 ; i < dest_can.size(); i++){
            for(int j = 0 ; j < daikstra_result.size(); j++){
                if(dest_can[i] == daikstra_result[j]){
                    print_result.push_back(dest_can[i]);
                    break;
                }
            }
        }
        
        sort(print_result.begin(),print_result.end());
        for(int i = 0 ; i < print_result.size(); i++)
            cout<<print_result[i]<<" ";
        cout<<"\n";
        
        daikstra_result.clear();
        print_result.clear();
    }
}



