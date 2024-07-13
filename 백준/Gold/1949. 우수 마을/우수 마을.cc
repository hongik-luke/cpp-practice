#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N;
int arr[10005];
vector<int> adj[10005];
int dp[10005][2];
bool check[10005];
void input(){
    cin>>N;
    for(int i = 1 ; i <= N ; i++) cin>>arr[i];
    int n1,n2;
    for(int i = 0 ; i < N-1 ; i++){
        cin>>n1>>n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1);
    }
}

void get(int idx){
    // idx가 우수
    dp[idx][1] = arr[idx];

    int len = adj[idx].size();
    for(int i = 0 ; i < len ; i++ ){
        int n = adj[idx][i];
        if(check[n]) continue;
        
        check[n] = true;
        get(n);
        
        // 모든 인접 우수마을 x
        dp[idx][1] += dp[n][0];
        
        // 최소 1개는 우수마을 >> 근데 이거 어차피 만족함 모든 애들이 선택안됐는데 굳이 날 선택안할 이유가 없음
        if(dp[n][1] >= dp[n][0]) dp[idx][0] += dp[n][1];
        else dp[idx][0] += dp[n][0];
    }

}
int main(void){
    input();
    memset(dp,0,sizeof(dp));
    memset(check,false,sizeof(check));
    check[1] = true;
    get(1);
    cout<<max(dp[1][0],dp[1][1]);
}