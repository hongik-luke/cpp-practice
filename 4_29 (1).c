#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[101][100001] = {0,};
int v[101][2];
int N,K;

int SomeObscureFunction(){
    
    for(int i = 1 ; i <= K ; i++)
        for(int j = 1 ; j <= N ; j++){
            if(i < v[j][0])
                dp[j][i] = dp[j-1][i];
            
            else
                dp[j][i] = max(dp[j-1][i] , v[j][1] + dp[j-1][i-v[j][0]]);
        }
    
    return dp[N][K];
}
void getthem(){
    cin>>N>>K;
    for(int i = 1 ; i <= N ; i++)
        cin>>v[i][0]>>v[i][1];
}

int main(void){
    getthem();
    cout<<SomeObscureFunction();
    
}