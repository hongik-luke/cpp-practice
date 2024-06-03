#include <iostream>
#include <algorithm>
#include <cstring>



using namespace std;

int64_t MOD = 1000000000;
int N,K;
int64_t dp[210][210]; //K, N 


void getresult(){
    for(int i = 1; i <= K ;i++)
        dp[i][0] = 1;
    for(int i = 0; i <= N ;i++)
        dp[1][i] = 1;
        
    for(int i = 2 ; i <= K ; i++)
        for(int j = 1 ; j <= N ; j++)
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
  
}


int main(void){

    cin>>N>>K;
    memset(dp,0,sizeof(dp));
    getresult();
    cout<<dp[K][N];

}