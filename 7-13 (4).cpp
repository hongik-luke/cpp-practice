#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
vector<pair<int,int>> v[1005];
vector<pair<int,int>> adj[1005];
bool check[1005];
int N,M;
void input(){
 
    cin>>N>>M;
    int n1,n2,n3;
    for(int i = 0 ; i < M ; i++){
        cin>>n1>>n2>>n3;

        v[n1].push_back(make_pair(n2,n3));
        v[n2].push_back(make_pair(n1,n3));
    }

    queue<int> q;
    q.push(1);
    check[1] = true;
    while(!q.empty()){
        int c = q.front();
        q.pop();
        
        int len = v[c].size();
        for(int i = 0; i < len ; i++){
            if(check[v[c][i].first]) continue;
            
            check[v[c][i].first] = true;
            q.push(v[c][i].first);
            adj[c].push_back(v[c][i]);
            
        }
    }
}

int get(int idx){
    int ret = 0;
    int len = adj[idx].size();
    for(int i = 0 ; i < len ; i++){
        int n = get(adj[idx][i].first);
        
        // 리프노드라면 0 이 나올테니 무조건 끊어주는걸로
        if(n == 0) ret += adj[idx][i].second;
        else ret += min(adj[idx][i].second, n);

    }
    return ret;
}
int main(void){
    int TC;
    cin>>TC;
    for(int i = 0 ; i < TC ; i++){
        // 초기화
        for(int j = 0 ; j < 1005 ; j++){
            v[j].clear();
            adj[j].clear();
        }
        memset(check,false,sizeof(check));
        
        input();
        cout<<get(1)<<"\n";
    }

}

