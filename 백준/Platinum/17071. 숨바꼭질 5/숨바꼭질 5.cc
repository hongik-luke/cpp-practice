#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
int N,M;

int dp[2][500010]; // 짝 , 홀
int get(){
    queue<pair<int,int>> q;
    memset(dp,-1,sizeof(dp));

    q.push({N,0});
    dp[0][N] = 0;
    
    int now = M;
    for(int i = 0 ; i < 1100 ; i++){
        now += i;
        if(now > 500000) return -1;
        
        if(dp[i%2][now] != -1) return i;
        
        pair<int,int> c;
        while(!q.empty()){
            c = q.front();
            if(c.second > i) break;
            q.pop();
            
            int j = c.first;
            if(j-1 >= 0 && dp[(i+1)%2][j-1] == -1){
                q.push({j-1,c.second+1});
                dp[(i+1)%2][j-1] = c.second+1;
            }
            if(j+1 <= 500000 && dp[(i+1)%2][j+1] == -1){
                q.push({j+1,c.second+1});
                dp[(i+1)%2][j+1] = c.second+1;
            }
            if(j*2 <= 500000 && dp[(i+1)%2][j*2] == -1){
                q.push({j*2,c.second+1});
                dp[(i+1)%2][j*2] = c.second+1;
            }
        }
    }
}

int main(){
    cin>>N>>M;
    cout<<get();
}