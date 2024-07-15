#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int N,M;
int arr[100];
int cost_arr[100];
void input(){
    cin>>N>>M;
    for(int i = 0 ; i < N ; i++){
        cin>>arr[i];
    }
    for(int i = 0 ; i < N ; i++){
        cin>>cost_arr[i];
    }
}
int dp[11000];
int get(){
    int dp2[11000];
    for(int i = 0 ; i < N ; i++){
        memset(dp2,-1,sizeof(dp2));
        for(int j = 0 ; j <= 10000 ; j++){
            if(dp[j] == -1) continue;
            dp2[j+cost_arr[i]] = max(dp[j+cost_arr[i]], dp[j]+arr[i]);
        }
        for(int j = 0 ; j <= 10000 ; j++){
            if(dp2[j] != -1) dp[j] = dp2[j];
        }
    }
    for(int i = 0 ; i <= 10000 ; i++){
        if(dp[i] >= M) return i;
    }
}

int main(void){
    FASTIO;
    input();
    memset(dp,-1,sizeof(dp));
    dp[0] = 0;
    cout<<get();
}

