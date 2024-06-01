#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int N,M;
int adj[1010][1010];
bool visited[1010];
int fir,la;

int back[1010];
vector <int> back_adj;

void input(){
    cin>>N>>M;
    int num1,num2,num3;
    for(int i = 0 ; i < M ; i++){
        cin>>num1>>num2>>num3;
        if(adj[num1][num2] == -1){
            adj[num1][num2] = num3;
        }
        else{
            adj[num1][num2] = min(adj[num1][num2],num3);
        }
    }
    cin>>fir>>la;
   
}

struct pos{
    int now;
    int before;
    int value;
};
struct cmp{
    bool operator()(pos a , pos b){
        return a.value > b.value;
    }
};

int get(){
    priority_queue<pos,vector<pos>,cmp> pq;
    pos c,n;
    c = {fir,fir,0};
    pq.push(c);
    
    while(!pq.empty()){
        c = pq.top();
        pq.pop();
        
        if(c.now == la){
            back[c.now] = c.before;
            for(int i = c.now ; i != fir ; i = back[i]){
                back_adj.push_back(i);
            }
            back_adj.push_back(fir);
            return c.value;
        }
        if(visited[c.now]) continue;
        back[c.now] = c.before;
        visited[c.now] = true;
        for(int i = 1 ; i <= N ; i++){
            if(visited[i] || adj[c.now][i] == -1) continue;
            n = {i, c.now, c.value+adj[c.now][i]};
            pq.push(n);
        }
    }
}


int main(void){
    memset(adj,-1,sizeof(adj));
    memset(visited,false,sizeof(visited));
    input();
    int value = get();
    int len = back_adj.size();
    cout<<value<<"\n"<<len<<"\n";
    for(int i = 0 ; i < len ; i++)
        cout<<back_adj[len-1-i]<<" ";
    
}   









