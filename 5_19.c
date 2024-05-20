//5719
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define fasti ios_base::sync_with_stdio(false); cin.tie(0);
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
struct pos{
    int value;
    int idx;
    int beforeidx;
};
struct cmp{
    bool operator()(pos a ,pos b){
        return a.value > b.value;
    }
};

int N,M,S,D;
vector<pos> adj[505];
int shortcut = -1;


bool input(){
    for(int i = 0 ; i < 505 ; i++){
        adj[i].clear();
    }
    cin>>N>>M;
    if(N == 0 && M == 0) return true;
    cin>>S>>D;
    int n1,n2,n3;
    pos npos;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;
        npos = {n3,n2,n1};
        adj[n1].push_back(npos);
    }
    return false;
}
int visited[510];
vector<pair<int,int>> back_adj[505];

void delete_min(){
    queue<pair<int,int>> pq;
    for(int i = 0 ; i < back_adj[D].size() ; i++){
        pq.push(back_adj[D][i]);
    }
    pair<int,int> now;

    while(!pq.empty()){
        now = pq.front();
        pq.pop();

        for(int i = 0 ; i < adj[now.first].size() ; i++){
            if(adj[now.first][i].idx == now.second){
                //cout<<adj[now.first][i].beforeidx<<" "<<adj[now.first][i].idx<<"\n";
                adj[now.first].erase(adj[now.first].begin()+i);
            }
        }

        for(int i = 0 ; i < back_adj[now.first].size() ; i++){
            pq.push(back_adj[now.first][i]);
        }
        for(int i = 0 ; i < back_adj[now.first].size() ; i++){
            back_adj[now.first].erase(back_adj[now.first].begin()+i);
        }
    }
}


int daikstra(){
    for(int i = 0 ; i < 505 ; i++){
        back_adj[i].clear();
    }
    memset(visited,-1,sizeof(visited));
    shortcut = -1;

    priority_queue<pos,vector<pos>,cmp> pq;
    pos cpos,npos;
    cpos = {0,S,S};
    pq.push(cpos);

    while(!pq.empty()){
        cpos = pq.top();
        pq.pop();

        if(cpos.idx == D){
            if(shortcut == -1 || shortcut == cpos.value){
                back_adj[cpos.idx].push_back(make_pair(cpos.beforeidx, cpos.idx));
                shortcut = cpos.value;
                continue;
            }
            else break;
        }
        if(visited[cpos.idx] == -1 || visited[cpos.idx] == cpos.value){
            back_adj[cpos.idx].push_back(make_pair(cpos.beforeidx, cpos.idx));
        }

        if(visited[cpos.idx] != -1) continue;
        visited[cpos.idx] = cpos.value;

        //cout<<cpos.value<<" "<<cpos.idx<<" "<<cpos.beforeidx<<"\n";
        for(int i = 0 ; i < adj[cpos.idx].size() ; i++){
            if(visited[adj[cpos.idx][i].idx] != -1) continue;
            npos = {cpos.value + adj[cpos.idx][i].value, adj[cpos.idx][i].idx, cpos.idx};
            pq.push(npos);
        }
    }

    delete_min();
    if(shortcut != -1) return shortcut;
    else return -1;
}   

int main(void){
    int print_result;
    while(true){
        if(input()) break;
        daikstra();
        cout<<daikstra()<<"\n";
    }
}


