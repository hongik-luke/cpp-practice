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
int n,m,v1,v2;
vector<pos> v[810];

void input(){
    cin>>n>>m;
    pos n;
    int n1,n2,n3;
    for(int i = 0 ; i < m ; i++){
        cin>>n1>>n2>>n3;
        n = {n3,n2};
        v[n1].push_back(n);
        n = {n3,n1};
        v[n2].push_back(n);
    }
    cin>>v1>>v2;
}




bool visited[810];
int getone(int startidx, int findidx){
    memset(visited,false,sizeof(visited));
    priority_queue<pos, vector<pos>, cmp> pq;
    pos now = {0,startidx};
    pos new1;
    pq.push(now);

    while(!pq.empty()){
        now = pq.top();
        pq.pop();
        
        if(now.nextidx == findidx) return now.value;
        if(visited[now.nextidx]) continue;
        visited[now.nextidx] = true;
        
        for(int i = 0 ; i < v[now.nextidx].size() ; i++){
            if(visited[v[now.nextidx][i].nextidx]) continue;
            new1 = {now.value + v[now.nextidx][i].value, v[now.nextidx][i].nextidx};
            pq.push(new1);
        }
    }
    
    return -1;
}



int short_path(){
    int min1 = 0;
    int min2 = 0;
    bool is_it_wrong1 = false;
    bool is_it_wrong2 = false;
    int now;
    //1 -> v1 -> v2 -> n
    now = getone(1,v1);
    if(now == -1) is_it_wrong1 = true;
    else min1 += now;
    
    if(!is_it_wrong1)
        now = getone(v1,v2);
    if(now == -1) is_it_wrong1 = true;
    else min1 += now;
    
    if(!is_it_wrong1)
        now = getone(v2,n);
    if(now == -1) is_it_wrong1 = true;
    else min1 += now;
    
    //1 -> v2 -> v1 -> n
    
    now = getone(1,v2);
    if(now == -1) is_it_wrong2 = true;
    else min2 += now;
    
    if(!is_it_wrong2)
        now = getone(v2,v1);
    if(now == -1) is_it_wrong2 = true;
    else min2 += now;
    
    if(!is_it_wrong2)
        now = getone(v1,n);
    if(now == -1) is_it_wrong2 = true;
    else min2 += now;
    
    
    
    if(is_it_wrong2 && is_it_wrong1) return -1;
    else if(is_it_wrong2 || is_it_wrong1){
        if(is_it_wrong1) return min2;
        if(is_it_wrong2) return min1;
    }
    else return min(min1,min2);
}



int main(void)
{
    input();
    cout<<short_path();
    
}