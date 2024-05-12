//2636
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int maxer = 0;
int dp[4][10010];
vector<int> v;

void input(){
    int N,M;
    cin>>N;
    
    for(int i = 0 ; i < N; i++){
        cin>>M;
        v.push_back(M);
        maxer = max(maxer,M);
    }
}
void getdp(){
    for(int i = 0 ; i < maxer ; i++)
        dp[1][i] = 1;
        
    dp[2][0] = 1;
    dp[2][1] = 1;
    for(int i = 2 ; i < maxer ; i++)
        dp[2][i] = dp[2][i-2] + dp[1][i];
        
    dp[3][0] = dp[2][0];
    dp[3][1] = dp[2][1];
    dp[3][2] = dp[2][2];
    
    for(int i = 3 ; i < maxer ; i++)
        dp[3][i] = dp[3][i-3] + dp[2][i];

    
    
}
void getresult(){
    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] <= 3){
            cout<<v[i]<<"\n";
        }
        else{
            cout<<dp[1][v[i]-1] + dp[2][v[i]-2] + dp[3][v[i]-3]<<"\n";
        }
    }
    

}

int main(void){
    input();
    getdp();
    getresult();
}



