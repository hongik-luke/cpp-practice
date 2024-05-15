#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct pos{
    int value;
    int nextidx;
};
struct cmp{
    bool operator()(pos a ,pos b){
        return a.value > b.value;
    }
};

int n = 0;
int m,c;
vector<pos> v[10010];
int result_cnt = 0;



void input(){
    cin>>n>>m>>c;
    
    int n1,n2,n3;
    pos npos;
    for(int i = 0 ; i < m ;i++){
        cin>>n1>>n2>>n3;
        npos = {n3,n1};
        v[n2].push_back(npos);
    }
}

bool visited[10010];
int short_path(){
    int returnnum = 0;
    memset(visited,false,sizeof(visited));
    priority_queue<pos, vector<pos>, cmp> pq;
    pos now = {0,c};
    pos new1;
    pq.push(now);

    while(!pq.empty()){
        now = pq.top();
        pq.pop();
        
        if(visited[now.nextidx]) continue;
        visited[now.nextidx] = true;
        result_cnt++;
        returnnum = now.value;
        
        for(int i = 0 ; i < v[now.nextidx].size() ; i++){
            if(visited[v[now.nextidx][i].nextidx]) continue;
            
            new1 = {now.value + v[now.nextidx][i].value ,v[now.nextidx][i].nextidx};
            pq.push(new1);
        }
    }
    return returnnum;
}



int main(void)
{
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ;i++){
        input();
        int time_cnt = short_path();
        cout<<result_cnt<<" "<<time_cnt<<"\n";
        
        for(int i = 1 ; i <= n ;i++)
            v[i].clear();
        result_cnt = 0; 
    }
}