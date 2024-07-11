#include <iostream>
#include <queue>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int N;
vector<int> adj[100001];
int parent[1000001];
void input(){
    cin>>N;
    int n1,n2;
    for(int i =  0 ; i < N-1 ; i++){
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
    parent[1] = -1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int n = q.front();
        q.pop();
        int len = adj[n].size();
        for(int i = 0 ; i < len ; i++){
            if(parent[adj[n][i]] != 0 ) continue;
            parent[adj[n][i]] = n;
            q.push(adj[n][i]);
        }
    }
}
int get(int idx){
    int ret = -98765432;
    int len = adj[idx].size();

    bool flag = false;
    for(int i = 0 ; i < len ; i++){
        if(parent[idx] == adj[idx][i]) continue;
        ret = max(ret, idx-get(adj[idx][i]));
        flag = true;
    }
    if(!flag) ret = idx;
    
    return ret;
}
int main() {
    FASTIO;
    input();
    for(int i = 1 ; i <= N ; i++){
        if(get(i) >= 0) cout<<1<<"\n";
        else cout<<0<<"\n";
    }
}