#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
vector<int> adj[1000005];
int dp[1000005][2];
bool check[1000005];
void input(){
    cin>>N;
    int n1,n2;
    for(int i = 0 ; i < N-1 ; i++){
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
}

void get(int idx){
    // idx가 얼리
    dp[idx][1] = 1;
    
    int len = adj[idx].size();
    for(int i = 0 ; i < len ; i++ ){
        int n = adj[idx][i];
        if(check[n]) continue;
        
        check[n] = true;
        get(n);
        
        dp[idx][0] += dp[n][1];
        dp[idx][1] += min(dp[n][0], dp[n][1]);
    }
}
int main(void){
    input();
    memset(dp,0,sizeof(dp));
    memset(check,false,sizeof(check));
    check[1] = true;
    get(1);
    cout<<min(dp[1][0],dp[1][1]);
}
