#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
vector<int> adj[100005];
bool check[100005];
int dp[100005][2];
void input(){
    cin>>N;
    int n1,n2;
    for(int i = 0 ; i < N ; i++){
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }

}
void get(int idx){
    dp[idx][1] = 1;
    dp[idx][0] = 0;
    int len = adj[idx].size();
    for(int i = 0 ; i < len ; i++){
        if(!check[adj[idx][i]]){
            check[adj[idx][i]] = true;
            get(adj[idx][i]);
            dp[idx][1] += min(dp[adj[idx][i]][1],dp[adj[idx][i]][0]); 
            dp[idx][0] += dp[adj[idx][i]][1];
        }
    }

}

int main(void){
    FASTIO;
    input();
    memset(check ,false ,sizeof(check));
    
    check[1] = true;
    get(1);
    
    cout<<min(dp[1][0], dp[1][1]);
}