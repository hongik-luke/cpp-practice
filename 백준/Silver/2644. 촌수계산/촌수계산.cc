#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N,M;
vector<int> adj[103];
int compare[2];
void input(){
    cin>>N;
    cin>>compare[0]>>compare[1];
    cin>>M;
    int n1,n2;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
}
bool check[103];
int get(){
    queue <pair<int,int>> q;
    pair<int,int> c,n;
    c = make_pair(compare[0],0);
    q.push(c);
    while(!q.empty()){
        c = q.front();
        q.pop();
        
        if(check[c.first]) continue;
        check[c.first] = true;
        if(c.first == compare[1]){
            return c.second;
        }
        
        int len = adj[c.first].size();
        for(int i = 0 ; i < len ;  i++){
            if(check[adj[c.first][i]]) continue;
            n = make_pair(adj[c.first][i], c.second+1);
            q.push(n);
        }
    }
    return -1;
}
int main(void){
    input();
    memset(check,false,sizeof(check));
    cout<<get();
}